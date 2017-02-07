/*
 * file:  dpp.l
 * ------------
 * Lex inupt file to generate the scanner for the preprocessor.
 * If you decide to use lex for the preprocesor, put your rules
 * here, otherwise the file can remain empty.
 */


%{
#include <map>
#include <string>
#include "errors.h"

using namespace std;

std::map<std::string, std::string>macromap;

int line = 1;

int c_char(string s, char c) {
  int count = 0;
  
  for (int i = 0; i < s.size(); i++)
    if (s[i] == c) count++;

  return count;
}

%}

%x COM_STATE
%option stack

SINGLELINE_COMMENT \/\/.*
MULTI_COMMENT \/\*([^*]|[\n]|(\*+([^*/]|[\n])))*\*+\/
BEGIN_COMMENT \/\*
NAME [A-Z]+

DEF_MACRO "#define"\ {NAME}\ .*
MACRO_USE \#{NAME}

%%

\n {line++;
	string text = strdup(yytext);
	printf("%s", text.c_str());
}

{BEGIN_COMMENT} {
	BEGIN(COM_STATE);
	yy_push_state(COM_STATE);
}

<COM_STATE><<EOF>> {
	ReportError::UntermComment(); 	
	yy_pop_state();
}

{SINGLELINE_COMMENT} { /* printf("%s", "\n"); */ }

{MULTI_COMMENT} { 
	string text = strdup(yytext);
	int nrow = c_char(text, '\n');
	for(int i = 0; i < nrow; i++){
		printf("%s", "\n");
	}

}

{DEF_MACRO} { 
	
	string name_replacement, name, replacement, text;
	int find_space;
	text = strdup(yytext);

	name_replacement = text.substr(8); 
	find_space = name_replacement.find(" "); 
	name = name_replacement.substr(0, find_space);
	replacement = name_replacement.substr(find_space);
	macromap.insert(make_pair(name, replacement)); 
}

{MACRO_USE} {
	string text, name, replacement;
	text = strdup(yytext);
	name = text.substr(1);
	if(macromap.find(name) == macromap.end()){
		ReportError::InvalidDirective(line); 
	} else {
		replacement = macromap.find(name)->second;
		printf("%s", replacement.c_str());
	}
}

#define[^\n]* {
	ReportError::InvalidDirective(line); 
}

. {
	string text = strdup(yytext);
	printf("%s", text.c_str());
}

%%