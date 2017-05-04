/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h>


ClassDecl* Expr::GetClassDeclaration(Scope *s) {
    while (s != NULL) {
        ClassDecl *d;
        if ((d = s->GetClassDeclaration()) != NULL)
            return d;
        s = s->GetParent();
    }

    return NULL;
}


Decl* Expr::GetFieldDeclaration(Identifier *f, Type *b) {
    NamedType *t = dynamic_cast<NamedType*>(b);

    while (t != NULL) {
        Decl *d = Program::gScope->table->Lookup(t->Name());
        ClassDecl *c = dynamic_cast<ClassDecl*>(d);
        InterfaceDecl *i = dynamic_cast<InterfaceDecl*>(d);

        Decl *fieldDecl;
        if (c != NULL) {
            if ((fieldDecl = GetFieldDeclaration(f, c->GetScope())) != NULL)
                return fieldDecl;
            else
                t = c->GetExtends();
        } else if (i != NULL) {
            if ((fieldDecl = GetFieldDeclaration(f, i->GetScope())) != NULL)
                return fieldDecl;
            else
                t = NULL;
        } else {
            t = NULL;
        }
    }

    return GetFieldDeclaration(f, scope);
}


Decl* Expr::GetFieldDeclaration(Identifier *f, Scope *s) {
    while (s != NULL) {
        Decl *lookup;
        if ((lookup = s->table->Lookup(f->Name())) != NULL)
            return lookup;

        s = s->GetParent();
    }

    return NULL;
}


Type* EmptyExpr::ObtainType() {
    return Type::errorType;
}


IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}


Type* IntConstant::ObtainType() {
    return Type::intType;
}


DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}


Type* DoubleConstant::ObtainType() {
    return Type::doubleType;
}


BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}


Type* BoolConstant::ObtainType() {
    return Type::boolType;
}


StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}


Type* StringConstant::ObtainType() {
    return Type::stringType;
}


Type* NullConstant::ObtainType() {
    return Type::nullType;
}


Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}
CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r)
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this);
    (right=r)->SetParent(this);
}


CompoundExpr::CompoundExpr(Operator *o, Expr *r)
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL;
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}


CompoundExpr::CompoundExpr(Expr *l, Operator *o)
  : Expr(Join(l->GetLocation(), o->GetLocation())) {
    Assert(o != NULL && l != NULL);
    right = NULL;
    (op=o)->SetParent(this);
    (left=l)->SetParent(this);
}


void CompoundExpr::ScopeBuilder(Scope *parent) {
    scope->SetParent(parent);

    if (left != NULL)
        left->ScopeBuilder(scope);
    if (right != NULL)
        right->ScopeBuilder(scope);
}


void CompoundExpr::Check() {
    if (left != NULL)
        left->Check();

    if (right != NULL)
        right->Check();
}


Type* PostfixExpr::ObtainType() {
    Type *ltype = left->ObtainType();

    if (ltype->Equivalent(Type::intType))
        return ltype;
    else
        return Type::errorType;
}


void PostfixExpr::Check() {
    if (left != NULL)
        left->Check();

    Type *ltype = left->ObtainType();

    if (ltype->Equivalent(Type::intType))
        return;
    else
        ReportError::IncompatibleOperand(op, ltype);
}


Type* ArithmeticExpr::ObtainType() {
    Type *rtype = right->ObtainType();

    if (left == NULL) {
        if (rtype->Equivalent(Type::intType) ||
            rtype->Equivalent(Type::doubleType))
            return rtype;
        else
            return Type::errorType;
    }

    Type *ltype = left->ObtainType();

    if (ltype->Equivalent(Type::intType) &&
        rtype->Equivalent(Type::intType))
        return ltype;

    if (ltype->Equivalent(Type::doubleType) &&
        rtype->Equivalent(Type::doubleType))
        return ltype;

    return Type::errorType;
}


void ArithmeticExpr::Check() {
    if (left != NULL)
        left->Check();

    right->Check();

    Type *rtype = right->ObtainType();

    if (left == NULL) {
        if (rtype->Equivalent(Type::intType) ||
            rtype->Equivalent(Type::doubleType))
            return;
        else
            ReportError::IncompatibleOperand(op, rtype);

        return;
    }

    Type *ltype = left->ObtainType();

    if (ltype->Equivalent(Type::intType) &&
        rtype->Equivalent(Type::intType))
        return;

    if (ltype->Equivalent(Type::doubleType) &&
        rtype->Equivalent(Type::doubleType))
        return;

    ReportError::IncompatibleOperands(op, ltype, rtype);
}


Type* RelationalExpr::ObtainType() {
    Type *rtype = right->ObtainType();
    Type *ltype = left->ObtainType();

    if (ltype->Equivalent(Type::intType) &&
        rtype->Equivalent(Type::intType))
        return Type::errorType;

    if (ltype->Equivalent(Type::doubleType) &&
        rtype->Equivalent(Type::doubleType))
        return Type::errorType;

    return Type::boolType;
}


void RelationalExpr::Check() {
    left->Check();
    right->Check();
    Type *rtype = right->ObtainType();
    Type *ltype = left->ObtainType();

    if (ltype->Equivalent(Type::intType) &&
        rtype->Equivalent(Type::intType))
        return;

    if (ltype->Equivalent(Type::doubleType) &&
        rtype->Equivalent(Type::doubleType))
        return;

    ReportError::IncompatibleOperands(op, ltype, rtype);
}


Type* EqualityExpr::ObtainType() {
    Type *rtype = right->ObtainType();
    Type *ltype = left->ObtainType();

    if (!rtype->Equivalent(ltype) &&
        !ltype->Equivalent(rtype))
        return Type::errorType;

   return Type::boolType;
}


void EqualityExpr::Check() {
    left->Check();
    right->Check();

    Type *rtype = right->ObtainType();
    Type *ltype = left->ObtainType();

    if (!rtype->Equivalent(ltype) &&
        !ltype->Equivalent(rtype))
        ReportError::IncompatibleOperands(op, ltype, rtype);
}


Type* LogicalExpr::ObtainType() {
    Type *rtype = right->ObtainType();

    if (left == NULL) {
        if (rtype->Equivalent(Type::boolType))
            return Type::boolType;
        else
            return Type::errorType;
    }

    Type *ltype = left->ObtainType();

    if (ltype->Equivalent(Type::boolType) &&
        rtype->Equivalent(Type::boolType))
        return Type::boolType;

    return Type::errorType;
}


void LogicalExpr::Check() {
    if (left != NULL)
        left->Check();

    right->Check();

    Type *rtype = right->ObtainType();

    if (left == NULL) {
        if (rtype->Equivalent(Type::boolType))
            return;
        else
            ReportError::IncompatibleOperand(op, rtype);

        return;
    }

    Type *ltype = left->ObtainType();

    if (ltype->Equivalent(Type::boolType) &&
        rtype->Equivalent(Type::boolType))
        return;

    ReportError::IncompatibleOperands(op, ltype, rtype);
}


Type* AssignExpr::ObtainType() {
    Type *ltype = left->ObtainType();
    Type *rtype = right->ObtainType();

    if (!rtype->Equivalent(ltype))
        return Type::errorType;

    return ltype;
}


void AssignExpr::Check() {
    left->Check();
    right->Check();

    Type *ltype = left->ObtainType();
    Type *rtype = right->ObtainType();

    if (!rtype->Equivalent(ltype) && !ltype->IsEqualTo(Type::errorType))
        ReportError::IncompatibleOperands(op, ltype, rtype);
}


Type* This::ObtainType() {
    ClassDecl *d = GetClassDeclaration(scope);
    if (d == NULL)
        return Type::errorType;

    return d->ObtainType();
}


void This::Check() {
    if (GetClassDeclaration(scope) == NULL)
        ReportError::ThisOutsideClassScope(this);
}


ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this);
    (subscript=s)->SetParent(this);
}


Type* ArrayAccess::ObtainType() {
    ArrayType *t = dynamic_cast<ArrayType*>(base->ObtainType());
    if (t == NULL)
        return Type::errorType;

    return t->GetElemType();
}


void ArrayAccess::ScopeBuilder(Scope *parent) {
    scope->SetParent(parent);

    base->ScopeBuilder(scope);
    subscript->ScopeBuilder(scope);
}


void ArrayAccess::Check() {
    base->Check();
    subscript->Check();

    if (base->ObtainType() == Type::errorType) // The base is an undeclared variable, so we don't need to further check the fields.
        return;

    ArrayType *t = dynamic_cast<ArrayType*>(base->ObtainType());
    if (t == NULL)
        ReportError::BracketsOnNonArray(base);

    if (subscript->ObtainType() != Type::errorType && !subscript->ObtainType()->IsEqualTo(Type::intType))
        ReportError::SubscriptNotInteger(subscript);
}


FieldAccess::FieldAccess(Expr *b, Identifier *f)
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
}


Type* FieldAccess::ObtainType() {
    Decl *d;
    ClassDecl *c;
    Type *t;

    c = GetClassDeclaration(scope);

    if (base == NULL) {
        if (c == NULL) {
            d = GetFieldDeclaration(field, scope);
        } else {
            t = c->ObtainType();
            d = GetFieldDeclaration(field, t);
        }
    } else {
        t = base->ObtainType();
        d = GetFieldDeclaration(field, t);
    }

    if (d == NULL)
        return Type::errorType;

    if (dynamic_cast<VarDecl*>(d) == NULL)
        return Type::errorType;

    return static_cast<VarDecl*>(d)->ObtainType();
}


void FieldAccess::ScopeBuilder(Scope *parent) {
    scope->SetParent(parent);

    if (base != NULL)
        base->ScopeBuilder(scope);
}

void FieldAccess::Check() {
    if (base != NULL) {
        base->Check();

        if (base->ObtainType() == Type::errorType) // The base is an undeclared variable, so we don't need to further check the fields.
            return;
    }
    Decl *d;
    Type *t;

    if (base == NULL) {
        ClassDecl *c = GetClassDeclaration(scope);
        if (c == NULL) {
            if ((d = GetFieldDeclaration(field, scope)) == NULL) {
                ReportError::IdentifierNotDeclared(field, LookingForVariable);
                return;
            }
        } else {
            t = c->ObtainType();
            if ((d = GetFieldDeclaration(field, t)) == NULL) {
                ReportError::FieldNotFoundInBase(field, t);
                return;
            }
        }
    } else {
        t = base->ObtainType();
        if ((d = GetFieldDeclaration(field, t)) == NULL) {
            ReportError::FieldNotFoundInBase(field, t);
            return;
        }
        else if (GetClassDeclaration(scope) == NULL) {
            ReportError::InaccessibleField(field, t);
            return;
        }
    }

    if (dynamic_cast<VarDecl*>(d) == NULL)
        ReportError::IdentifierNotDeclared(field, LookingForVariable);
}


Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

Type* Call::ObtainType() {
    Decl *d;

    if (base == NULL) {
        ClassDecl *c = GetClassDeclaration(scope);
        if (c == NULL) {
            if ((d = GetFieldDeclaration(field, scope)) == NULL)
                return Type::errorType;
        } else {
            if ((d = GetFieldDeclaration(field, c->ObtainType())) == NULL)
                return Type::errorType;
        }
    } else {
        Type *t = base->ObtainType();
        if ((d = GetFieldDeclaration(field, t)) == NULL) {

            if (dynamic_cast<ArrayType*>(t) != NULL &&
                strcmp("length", field->Name()) == 0)
                return Type::intType;

            return Type::errorType;
        }
    }

    if (dynamic_cast<FnDecl*>(d) == NULL)
        return Type::errorType;

    return static_cast<FnDecl*>(d)->GetReturnType();
}


void Call::ScopeBuilder(Scope *parent) {
    scope->SetParent(parent);

    if (base != NULL)
        base->ScopeBuilder(scope);

    for (int i = 0, n = actuals->NumElements(); i < n; ++i)
        actuals->Nth(i)->ScopeBuilder(scope);
}


void Call::Check() {
    if (base != NULL)
        base->Check();

    Decl *d;
    Type *t;

    if (base == NULL) {
        ClassDecl *c = GetClassDeclaration(scope);
        if (c == NULL) {
            if ((d = GetFieldDeclaration(field, scope)) == NULL) {
                CheckActuals(d);
                ReportError::IdentifierNotDeclared(field, LookingForFunction);
                return;
            }
        } else {
            t = c->ObtainType();
            if ((d = GetFieldDeclaration(field, t)) == NULL) {
                CheckActuals(d);
                ReportError::IdentifierNotDeclared(field, LookingForFunction);
                return;
            }
        }
    } else {
        t = base->ObtainType();
        if (! t->typeDeclared) {return;} // No need to check the fields of undeclared type.
        if ((d = GetFieldDeclaration(field, t)) == NULL) {  //&& f->ObtainType() == lookup->ObtainType()
            CheckActuals(d);

            if (dynamic_cast<ArrayType*>(t) == NULL ||
                strcmp("length", field->Name()) != 0)
                    ReportError::FieldNotFoundInBase(field, t);

            return;
        }
    }

    CheckActuals(d);
}


void Call::CheckActuals(Decl *d) {
    for (int i = 0, n = actuals->NumElements(); i < n; ++i)
        actuals->Nth(i)->Check();

    FnDecl *fnDecl = dynamic_cast<FnDecl*>(d);
    if (fnDecl == NULL)
        return;

    List<VarDecl*> *formals = fnDecl->GetFormals();

    int numExpected = formals->NumElements();
    int numGiven = actuals->NumElements();
    if (numExpected != numGiven) {
        ReportError::NumArgsMismatch(field, numExpected, numGiven);
        return;
    }

    for (int i = 0, n = actuals->NumElements(); i < n; ++i) {
        Type *given = actuals->Nth(i)->ObtainType();
        Type *expected = formals->Nth(i)->ObtainType();
        if (!given->Equivalent(expected))
            ReportError::ArgMismatch(actuals->Nth(i), i+1, given, expected);
    }
}


NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) {
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}


Type* NewExpr::ObtainType() {
    Decl *d = Program::gScope->table->Lookup(cType->Name());
    ClassDecl *c = dynamic_cast<ClassDecl*>(d);

    if (c == NULL)
        return Type::errorType;

    return c->ObtainType();
}


void NewExpr::Check() {
    Decl *d = Program::gScope->table->Lookup(cType->Name());
    ClassDecl *c = dynamic_cast<ClassDecl*>(d);

    if (c == NULL)
        ReportError::IdentifierNotDeclared(cType->GetId(), LookingForClass);
}


NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this);
    (elemType=et)->SetParent(this);
}


Type* NewArrayExpr::ObtainType() {
    return new ArrayType(elemType);
}


void NewArrayExpr::ScopeBuilder(Scope *parent) {
    scope->SetParent(parent);

    size->ScopeBuilder(scope);
}


void NewArrayExpr::Check() {
    size->Check();

    if (size->ObtainType() != Type::errorType && !size->ObtainType()->IsEqualTo(Type::intType))
        ReportError::NewArraySizeNotInteger(size);

    if (elemType->IsPrimitive() && !elemType->Equivalent(Type::voidType))
        return;

    Decl *d = Program::gScope->table->Lookup(elemType->Name());
    if (dynamic_cast<ClassDecl*>(d) == NULL)
        elemType->ReportNotDeclaredID(LookingForType);
}


Type* ReadIntegerExpr::ObtainType() {
    return Type::intType;
}


Type* ReadLineExpr::ObtainType() {
    return Type::stringType;
}


