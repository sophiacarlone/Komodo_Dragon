%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"
#include "tree.h"
#include "symtab.h" 
#include "semantic.h" 

scope_t *top_scope;
list_t *id_ptr;

%}

%union{
	/*token attributes*/
	int ival; /*INUM*/
	float rval; /*RNUM*/
	char *sval; /*ID*/
	int opval; /* RELOP ADDOP MULOP */

	tree_t *tval; /* tree value */
}

%token DEF
%token VAR
%token ARRAY OF
%token INTEGRAL RATIONAL
%token FUNC PROC
%token BBEGIN END
%token IF THEN ELSE
%token WHILE DO
%token DOTDOT
%token ASSIGNOP

%token <opval> RELOP
%token <opval> LT LE GT GE EQ NE
%token <opval> ADDOP
%token <opval> PLUS MINUS OR
%token <opval> MULOP
%token <opval> STAR SLASH DIV MOD AND
%token <opval> NOT

%token FUNCTION_CALL ARRAY_ACCESS
%token LIST

%token <sval> ID
%token <ival> INUM
%token <rval> RNUM

%type <ival> type
%type <ival> standard_type

%type <tval> statement_list
%type <tval> statement
%type <tval> matched_statement
%type <tval> unmatched_statement
%type <tval> identifier_list
%type <tval> variable
%type <tval> expression
%type <tval> expression_list
%type <tval> simple_expression
%type <tval> term
%type <tval> factor
%type <tval> compound_statement
%type <tval> procedure_statement
%type <tval> optional_statements

%%

program: DEF ID '(' identifier_list ')' ';'
	declarations
	subprogram_declarations
	compound_statement
	'.'
	;

identifier_list: ID
		 { id_ptr = scope_insert( top_scope, $1 ); 
		   $$ = make_id( id_ptr );}
	| identifier_list ',' ID
		{ /*fprintf(stderr, "this is $3 %s \n", $3) ;*/ 
		 id_ptr = scope_insert( top_scope, $3 );
		fprintf(stderr, "this is list %d\n", LIST); 
		 $$ =  make_tree(LIST, $1, make_id(id_ptr)); }
	;

declarations: declarations VAR identifier_list ':' type ';' 
	/*make something for type that will pointing at the stack to catch names*/
	{ semantic_set_type( $3, $5 ); } 
	| /*empty*/
	;

type: standard_type { $$ = $1; }
	| ARRAY '[' range ']' OF standard_type
		{ $$ = -1; }
	;

range: INUM DOTDOT INUM
	;

standard_type: INTEGRAL { $$ = INTEGRAL; }
	| RATIONAL { $$ = RATIONAL; }	
	;

subprogram_declarations: subprogram_declarations subprogram_declaration ';'
	| /*empty*/
	;

subprogram_declaration: 
	subprogram_header
	declarations
	subprogram_declarations
	compound_statement
	{ top_scope = scope_pop( top_scope ); } /* leaving inner scope */
	;

subprogram_header: FUNC ID 
		{ /* do we need a tree here */  
			id_ptr = scope_insert( top_scope, $2 ); /* record function ID in current scope */
			top_scope = scope_push(top_scope);  /* create a new scope */
		} arguments ':' standard_type ';' 
	| PROC ID 
		{ 
			id_ptr = scope_insert( top_scope, $2 ); /* record procedure ID in current scope */
			top_scope = scope_push(top_scope);  /* create a new scope */
		} arguments ';'
	;

arguments: '(' parameter_list ')' 
	| /*empty*/
	;

parameter_list: identifier_list ':' type {semantic_set_type( $1 , $3 ); } 
	| parameter_list ';' identifier_list ':' type {semantic_set_type( $3 , $5 );}
	;

compound_statement: 
	BBEGIN 
		optional_statements
	END { $$ = $2; }
	;

optional_statements: statement_list { $$ = $1; }
	| { $$ = NULL; }
	;

statement_list: statement
		{ $$ = $1; }
	| statement_list ';' statement
		{ $$ = make_tree( LIST, $1, $3 ); }
	;

statement: matched_statement
		{ $$ = $1; }
	| unmatched_statement
		{ $$ = $1; }
	;

matched_statement:  IF expression THEN matched_statement ELSE matched_statement
		{
			$$ = make_tree( IF, $2, make_tree( THEN, $4, $6 ));
		}
	| variable ASSIGNOP expression
		{ 
			if (type_of($1) != type_of($3) ){
				fprintf(stderr, "1 ERROR: mismatch in assignment type\n");
				exit(1);
			}
			$$ = make_tree( ASSIGNOP, $1, $3 );
			
		}/* call tree here */
	| procedure_statement
			{$$ = $1;}
	| compound_statement
			{$$ = $1;}
	| WHILE expression DO matched_statement 
			{$$ = make_tree( WHILE, $2, $4 ); }
	;

unmatched_statement: IF expression THEN statement
		{ $$ = make_tree( IF, $2, $4); }
	| IF expression THEN matched_statement ELSE unmatched_statement
		{ $$ = make_tree(IF, $2, make_tree(THEN, $4, $6)); }
	;

variable: ID
		{
			id_ptr = semantic_lookup(top_scope, $1);
			$$ = make_id( id_ptr ); //can make this a one liner
		}
	| ID '[' expression ']'
		{
			id_ptr = semantic_lookup(top_scope, $1); //change all of these with errors to lookup
			$$ = make_tree( ARRAY_ACCESS, make_id (id_ptr), $3 );
		}

	;

procedure_statement: ID
		{ 
			id_ptr = semantic_lookup( top_scope, $1);
			$$ = make_id( id_ptr ); 
		} 
	| ID '(' expression_list ')'
		{ $$ = make_tree( FUNCTION_CALL, make_id( semantic_lookup( top_scope, $1 ) ) , $3); } /* looking for the ID */
	;

expression_list: expression
		{ $$ = $1; }
	| expression_list ',' expression 
		{ $$ = make_tree( LIST, $1, $3 ); } /*ask Tino about this attribute */
	;

expression: simple_expression
		{ $$ = $1; } /* is this enough for an expression */
	| simple_expression RELOP simple_expression
		{ $$ = make_tree( RELOP, $1, $3 ); $$->attribute.opval = $2; }
	;

simple_expression: term
		{ $$ = $1; }
	| ADDOP term
		{ $$ = make_tree( ADDOP, $2, NULL ); $$->attribute.opval = $1; }
	| simple_expression ADDOP term
		{ $$ = make_tree( ADDOP, $1, $3); $$->attribute.opval = $2; }
	;

term: factor
		{ $$ = $1; }
	| term MULOP factor
		{ 
			$$ = make_tree( MULOP, $1, $3); 
			$$->attribute.opval = $2;
		}
	;

factor: ID
		{ 
			id_ptr = semantic_lookup( top_scope, $1);
			$$ = make_id( id_ptr ); 
		} 
	| ID '(' expression_list ')'
		{ $$ = make_tree( FUNCTION_CALL, make_id( semantic_lookup( top_scope, $1 ) ) , $3); } /* looking for the ID */
	| ID '[' expression ']'
		{ $$ = make_tree( ARRAY_ACCESS, make_id( semantic_lookup( top_scope, $1 ) ), $3); } /*add function to make sure make_id != NULL */ 
	| INUM
		{ $$ = make_inum( $1 ); }
	| RNUM
		{ $$ = make_rnum( $1 ); }
	| '(' expression ')'
		{ $$ = $2; }
	| NOT factor
		{ $$ = make_tree( NOT, $2, NULL ); } /* and for not a factor */
	;

%%

main(){
	
	top_scope = scope_push(top_scope); //should have something in scope before you want to use it 
	yyparse(); /*entry point for parser*/
	//gencode_start($$);

}
