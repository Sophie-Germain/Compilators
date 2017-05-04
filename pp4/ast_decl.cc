/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"


Decl::Decl(Identifier *n) : Node(*n->GetLocation()), scope(new Scope) {
    Assert(n != NULL);
    (id=n)->SetParent(this);
}


bool Decl::Equivalent(Decl *other) {
    return true;
}


void Decl::ScopeBuilder(Scope *parent) {
    scope->SetParent(parent);
}


VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}


bool VarDecl::Equivalent(Decl *other) {
    VarDecl *varDecl = dynamic_cast<VarDecl*>(other);
    if (varDecl == NULL)
        return false;

    return type->Equivalent(varDecl->type);
}


void VarDecl::Check() {
    CheckType();
}


void VarDecl::CheckType() {
    if (type->IsPrimitive())
        return;

    Scope *s = scope;
    while (s != NULL) {
        Decl *d;
        if ((d = s->table->Lookup(type->Name())) != NULL) {
            if (dynamic_cast<ClassDecl*>(d) == NULL &&
                dynamic_cast<InterfaceDecl*>(d) == NULL) {
                type->ReportNotDeclaredID(LookingForType);
                type->typeDeclared = false;
            }

            return;
        }
        s = s->GetParent();
    }

    type->ReportNotDeclaredID(LookingForType);
    type->typeDeclared = false;
}

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
    Assert(n != NULL && imp != NULL && m != NULL);
    extends = ex;
    if (extends) extends->SetParent(this);
    (implements=imp)->SetParentAll(this);
    (members=m)->SetParentAll(this);
}


//construimos scope
void ClassDecl::ScopeBuilder(Scope *parent) {
    scope->SetParent(parent);
    scope->SetClassDecl(this);

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        scope->AddDeclaration(members->Nth(i));

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        members->Nth(i)->ScopeBuilder(scope);
}

void ClassDecl::Check() {
    for (int i = 0, n = members->NumElements(); i < n; ++i)
        members->Nth(i)->Check();

    CheckExt();
    CheckImplementation();

    for (int i = 0, n = implements->NumElements(); i < n; ++i)
        CheckImplMemb(implements->Nth(i));

    CheckExtMemb(extends);
    CheckImplInterf();
}

void ClassDecl::CheckExt() {
    if (extends == NULL)
        return;

    Decl *lookup = scope->GetParent()->table->Lookup(extends->Name());
    if (dynamic_cast<ClassDecl*>(lookup) == NULL)
        extends->ReportNotDeclaredID(LookingForClass);
}

void ClassDecl::CheckImplementation() {
    Scope *s = scope->GetParent();

    for (int i = 0, n = implements->NumElements(); i < n; ++i) {
        NamedType *nth = implements->Nth(i);
        Decl *lookup = s->table->Lookup(implements->Nth(i)->Name());

        if (dynamic_cast<InterfaceDecl*>(lookup) == NULL)
            nth->ReportNotDeclaredID(LookingForInterface);
    }
}

void ClassDecl::CheckExtMemb(NamedType *extType) {
    if (extType == NULL)
        return;

    Decl *lookup = scope->GetParent()->table->Lookup(extType->Name());
    ClassDecl *extDecl = dynamic_cast<ClassDecl*>(lookup);
    if (extDecl == NULL)
        return;

    CheckExtMemb(extDecl->extends);
    CheckVsScope(extDecl->scope);
}

void ClassDecl::CheckImplMemb(NamedType *impType) {
    Decl *lookup = scope->GetParent()->table->Lookup(impType->Name());
    InterfaceDecl *intDecl = dynamic_cast<InterfaceDecl*>(lookup);
    if (intDecl == NULL)
        return;

    CheckVsScope(intDecl->GetScope());
}

void ClassDecl::CheckVsScope(Scope *other) {
    Iterator<Decl*> iter = scope->table->GetIterator();
    Decl *d;
    while ((d = iter.GetNextValue()) != NULL) {
        Decl *lookup = other->table->Lookup(d->Name());

        if (lookup == NULL)
            continue;

        if (dynamic_cast<VarDecl*>(lookup) != NULL)
            ReportError::DeclConflict(d, lookup);

        if (dynamic_cast<FnDecl*>(lookup) != NULL &&
            !d->Equivalent(lookup))
            ReportError::OverrideMismatch(d);
    }
}

void ClassDecl::CheckImplInterf() {
    Scope *s = scope->GetParent();

    for (int i = 0, n = implements->NumElements(); i < n; ++i) {
        NamedType *nth = implements->Nth(i);
        Decl *lookup = s->table->Lookup(implements->Nth(i)->Name());
        InterfaceDecl *intDecl = dynamic_cast<InterfaceDecl*>(lookup);

        if (intDecl == NULL)
            continue;

        List<Decl*> *intMembers = intDecl->GetMembers();

        for (int i = 0, n = intMembers->NumElements(); i < n; ++i) {
            Decl *d = intMembers->Nth(i);

            ClassDecl *classDecl = this;
            Decl *classLookup;
            while (classDecl != NULL) {
                classLookup = classDecl->GetScope()->table->Lookup(d->Name());

                if (classLookup != NULL)
                    break;

                if (classDecl->GetExtends() == NULL) {
                    classDecl = NULL;
                } else {
                    const char *extName = classDecl->GetExtends()->Name();
                    Decl *ext = Program::gScope->table->Lookup(extName);
                    classDecl = dynamic_cast<ClassDecl*>(ext);
                }
            }

            if (classLookup == NULL) {
                ReportError::InterfaceNotImplemented(this, nth);
                return;
            }
        }
    }
}

InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

void InterfaceDecl::ScopeBuilder(Scope *parent) {
    scope->SetParent(parent);

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        scope->AddDeclaration(members->Nth(i));

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        members->Nth(i)->ScopeBuilder(scope);
}

void InterfaceDecl::Check() {
    for (int i = 0, n = members->NumElements(); i < n; ++i)
        members->Nth(i)->Check();
}

FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) {
    (body=b)->SetParent(this);
}

bool FnDecl::Equivalent(Decl *other) {
    FnDecl *fnDecl = dynamic_cast<FnDecl*>(other);

    if (fnDecl == NULL)
        return false;

    if (!returnType->Equivalent(fnDecl->returnType))
        return false;

    if (formals->NumElements() != fnDecl->formals->NumElements())
        return false;

    for (int i = 0, n = formals->NumElements(); i < n; ++i)
        if (!formals->Nth(i)->Equivalent(fnDecl->formals->Nth(i)))
            return false;

    return true;
}

void FnDecl::ScopeBuilder(Scope *parent) {
    scope->SetParent(parent);
    scope->SetFnDecl(this);

    for (int i = 0, n = formals->NumElements(); i < n; ++i)
        scope->AddDeclaration(formals->Nth(i));

    for (int i = 0, n = formals->NumElements(); i < n; ++i)
        formals->Nth(i)->ScopeBuilder(scope);

    if (body)
        body->ScopeBuilder(scope);
}

void FnDecl::Check() {
    for (int i = 0, n = formals->NumElements(); i < n; ++i)
        formals->Nth(i)->Check();

    if (body)
        body->Check();
}

