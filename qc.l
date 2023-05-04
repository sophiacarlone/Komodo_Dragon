%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"
#include "tree.h"
#include "y.tab.h" /*where def and other constants will exist" */
%}

identifier 	[a-zA-Z][a-zA-Z0-9]* /*variable name */
number 		[0-9]+
whitespace 	[ \t]+
comment         .*

%%
"def" 			{ fprintf( stderr, "[DEF]" ); return DEF; }
"var" 			{ fprintf( stderr, "[VAR]" ); return VAR; }
"array"			{ fprintf( stderr, "[ARRAY]" ); return ARRAY; }
"of" 			{ fprintf( stderr, "[OF]" ); return OF; }
"begin"			{ fprintf( stderr, "[BBEGIN]" ); return BBEGIN; }
"end"			{ fprintf( stderr, "[END]" ); return END; }
"if"			{ fprintf( stderr, "[IF]" ); return IF; }
"then"			{ fprintf( stderr, "[THEN]" ); return THEN; }
"else"			{ fprintf( stderr, "[ELSE]" ); return ELSE; }
"while"			{ fprintf( stderr, "[WHILE]" ); return WHILE; }
"do"			{ fprintf( stderr, "[DO]" ); return DO; }
"rational"		{ fprintf( stderr, "[RATIONAL]" ); return RATIONAL; }
"integral"		{ fprintf( stderr, "[INTEGRAL]" ); return INTEGRAL; }
"proc"			{ fprintf( stderr, "[PROC]" ); return PROC; }
"func"			{ fprintf( stderr, "[FUNC]" ); return FUNC; }
{identifier}		{ fprintf( stderr, "[ID:%s]", yylval.sval = (char *)strdup(yytext) ); return ID; }
{number} 		{ fprintf( stderr, "[INUM:%d]", yylval.ival = atoi(yytext) ); return INUM; }
{number}"."{number} 	{ fprintf( stderr, "[RNUM:%f]", yylval.rval = atof(yytext) ); return RNUM; }
{whitespace} 		{ ; }
"(*"{comment}"*)"       { ; } /*comment*/
"{"{comment}"}"       	{ ; } /*comment*/

":="		{ fprintf( stderr, "[ASSIGNOP]" ); return ASSIGNOP; }
"<"		{ fprintf( stderr, "[RELOP:%d]", yylval.opval = LT ); return RELOP; }
"<="		{ fprintf( stderr, "[RELOP:%d]", yylval.opval = LE ); return RELOP; }
">"		{ fprintf( stderr, "[RELOP:%d]", yylval.opval = GT ); return RELOP; }
">="		{ fprintf( stderr, "[RELOP:%d]", yylval.opval = GE ); return RELOP; }
"<>"		{ fprintf( stderr, "[RELOP:%d]", yylval.opval = NE ); return RELOP; }
"="		{ fprintf( stderr, "[RELOP:%d]", yylval.opval = EQ ); return RELOP; }
"not"		{ fprintf( stderr, "[RELOP:%d]", yylval.opval = NOT ); return RELOP; }
"+"		{ fprintf( stderr, "[ADDOP:%d]", yylval.opval = PLUS ); return ADDOP; }
"-"		{ fprintf( stderr, "[ADDOP:%d]", yylval.opval = MINUS ); return ADDOP; }
"or"		{ fprintf( stderr, "[ADDOP:%d]", yylval.opval = OR ); return ADDOP; }
"*"		{ fprintf( stderr, "[MULOP:%d]", yylval.opval = STAR ); return MULOP; }
"/"		{ fprintf( stderr, "[MULOP:%d]", yylval.opval = SLASH ); return MULOP; }
"div"		{ fprintf( stderr, "[MULOP:%d]", yylval.opval = DIV ); return MULOP; }
"mod"		{ fprintf( stderr, "[MULOP:%d]", yylval.opval = MOD ); return MULOP; }
"and"		{ fprintf( stderr, "[MULOP:%d]", yylval.opval = AND ); return MULOP; }
"("		{ fprintf( stderr, "{%c}", yytext[0] ); return yytext[0]; }
")"		{ fprintf( stderr, "{%c}", yytext[0] ); return yytext[0]; }
"["		{ fprintf( stderr, "{%c}", yytext[0] ); return yytext[0]; }
"]"		{ fprintf( stderr, "{%c}", yytext[0] ); return yytext[0]; }
":"		{ fprintf( stderr, "{%c}", yytext[0] ); return yytext[0]; }
";"		{ fprintf( stderr, "{%c}", yytext[0] ); return yytext[0]; }
","		{ fprintf( stderr, "{%c}", yytext[0] ); return yytext[0]; }
"."		{ fprintf( stderr, "{%c}", yytext[0] ); return yytext[0]; }
".."		{ fprintf( stderr, "[DOTDOT]" ); return DOTDOT; }
\n 		{ fprintf( stderr, "\n" ); } /*ignoring*/
.		{ fprintf( stderr, "<%c>", yytext[0] ); return yytext[0]; }

%%

int yyerror( char *message ){
	fprintf( stderr, "ERROR: %s\n", message );
	exit(1);
}
