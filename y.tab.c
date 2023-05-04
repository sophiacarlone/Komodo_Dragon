#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "qc.y"
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

#line 16 "qc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	/*token attributes*/
	int ival; /*INUM*/
	float rval; /*RNUM*/
	char *sval; /*ID*/
	int opval; /* RELOP ADDOP MULOP */

	tree_t *tval; /* tree value */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 49 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define DEF 257
#define VAR 258
#define ARRAY 259
#define OF 260
#define INTEGRAL 261
#define RATIONAL 262
#define FUNC 263
#define PROC 264
#define BBEGIN 265
#define END 266
#define IF 267
#define THEN 268
#define ELSE 269
#define WHILE 270
#define DO 271
#define DOTDOT 272
#define ASSIGNOP 273
#define RELOP 274
#define LT 275
#define LE 276
#define GT 277
#define GE 278
#define EQ 279
#define NE 280
#define ADDOP 281
#define PLUS 282
#define MINUS 283
#define OR 284
#define MULOP 285
#define STAR 286
#define SLASH 287
#define DIV 288
#define MOD 289
#define AND 290
#define NOT 291
#define FUNCTION_CALL 292
#define ARRAY_ACCESS 293
#define LIST 294
#define ID 295
#define INUM 296
#define RNUM 297
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    7,    7,   17,   17,    1,    1,   19,    2,    2,
   18,   18,   20,   23,   21,   24,   21,   22,   22,   25,
   25,   14,   16,   16,    3,    3,    4,    4,    5,    5,
    5,    5,    5,    6,    6,    8,    8,   15,   15,   10,
   10,    9,    9,   11,   11,   11,   12,   12,   13,   13,
   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
   10,    1,    3,    6,    0,    1,    6,    3,    1,    1,
    3,    0,    4,    0,    7,    0,    5,    3,    0,    3,
    5,    3,    1,    0,    1,    3,    1,    1,    6,    3,
    1,    1,    4,    4,    6,    1,    4,    1,    4,    1,
    3,    1,    3,    1,    2,    3,    1,    3,    1,    4,
    4,    1,    1,    3,    2,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    2,    0,    0,    0,    5,    3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,
    0,   14,   16,    0,    0,    0,    0,   25,   27,   28,
    0,   32,   31,    0,    1,   11,    0,    0,    9,   10,
    0,    6,    0,    0,    0,    0,    0,   52,   53,    0,
    0,    0,    0,   47,    0,    0,    0,    0,    0,   22,
    0,    0,    4,    0,    0,    0,    0,   55,    0,    0,
    0,    0,    0,    0,    0,    0,   40,    0,    0,   26,
   30,   13,    0,    0,    0,    0,    0,   17,    0,    0,
   54,   34,    0,    0,    0,   48,    0,   33,   39,    0,
   37,    0,    0,    0,   18,    0,    0,   50,   51,    0,
    0,   41,    8,    0,   20,    0,   15,   29,   35,    0,
    7,    0,    0,   21,    0,
};
static const short yydgoto[] = {                          2,
   41,   42,   27,   28,   29,   30,    6,   31,   77,   78,
   52,   53,   54,   32,   33,   34,   11,   13,   84,   19,
   20,   65,   43,   44,   86,
};
static const short yysindex[] = {                      -225,
 -261,    0,    3, -250,    0,   -5,   11, -218,    0,    0,
 -179, -250, -237,   -6, -211, -201, -223,   50,   38,    0,
 -176,    0,    0,  -40,  -40,  -28,   43,    0,    0,    0,
 -170,    0,    0, -159,    0,    0, -179,   17,    0,    0,
   52,    0,   70,   70,  -37,  -37,  -26,    0,    0,  -40,
 -156, -251, -172,    0, -157,  -40,  -40, -223,  -40,    0,
 -237, -181,    0, -250,   58,   59, -172,    0,  -40,  -40,
   76, -223,  -40,  -37,  -37, -189,    0,   49,   26,    0,
    0,    0, -152,   28,   22,  -30, -244,    0,   51,   29,
    0,    0, -146, -155, -172,    0,  -40,    0,    0,  -40,
    0, -171, -136, -176,    0, -250,   68,    0,    0, -223,
 -140,    0,    0, -244,    0,   24,    0,    0,    0, -189,
    0, -176, -139,    0, -189,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -164,    0,    0,    0,    0,    0, -137,    0,    0,    0,
    0,    0,    0,    0,    0,  -58, -135,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -164,    0,    0,    0,
    0,    0,   74,   75,    0,    0,  -39,    0,    0,    0,
    0,  -35,   -4,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    5,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -52,   12,   16,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  -91,  -79,    0,   15,  -51,   23,   -2,    0,   -9,   66,
   63,  -41,  -24,    6,    0,    0,  117,  101,    0,    0,
    0,   95,    0,    0,    0,
};
#define YYTABLESIZE 297
static const short yytable[] = {                         50,
   38,   49,   50,   67,   49,   42,   27,  107,   42,   14,
  105,   56,  115,   69,   51,   55,   39,   40,   18,   49,
   93,   68,   73,   42,   98,   15,   16,   17,  106,   74,
  124,    1,   95,    3,  121,    7,   44,    8,    8,   44,
   71,   17,    4,   24,    5,   45,   25,   79,   45,   81,
   96,   21,   43,   49,   44,   43,   46,   42,  118,   46,
   90,   85,   57,   45,   70,    8,   82,    8,  123,    9,
   43,   26,   80,  118,   46,   17,   10,   97,   12,  104,
   25,  122,   38,   22,   39,   40,   92,  111,   44,   99,
  112,  108,  100,   23,  100,   35,   36,   45,   12,   12,
   12,   58,   59,  116,   43,   26,   60,   62,   46,   64,
   63,   72,   75,   76,   83,   87,   91,   88,  101,  102,
  103,  109,  110,  114,  113,   74,  117,  120,   24,  125,
   23,   19,  119,   19,   89,   94,   37,   61,   66,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   38,    0,    0,
   38,    0,    0,   27,   36,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   49,    0,   49,   49,
   42,   49,   42,   42,   49,   42,    0,    0,    0,    0,
   45,   49,    0,    0,    0,   49,    0,    0,    0,    0,
   46,    0,    0,   46,   47,   48,   49,   47,   48,   49,
    0,   44,    0,   44,   44,    0,   44,    0,    0,   44,
   45,    0,   45,   45,    0,   45,   44,   43,   45,   43,
   43,   46,   43,   46,   46,   45,   46,    0,    0,   46,
    0,    0,    0,    0,    0,    0,   46,
};
static const short yycheck[] = {                         40,
   59,   41,   40,   45,   44,   41,   59,   87,   44,   12,
   41,   40,  104,   40,   24,   25,  261,  262,   13,   59,
   72,   46,  274,   59,   76,  263,  264,  265,   59,  281,
  122,  257,   74,  295,  114,   41,   41,   44,   44,   44,
   50,  265,   40,  267,  295,   41,  270,   57,   44,   59,
   75,   58,   41,   93,   59,   44,   41,   93,  110,   44,
   70,   64,   91,   59,   91,   44,   61,   44,  120,   59,
   59,  295,   58,  125,   59,  265,  295,  267,  258,   58,
  270,   58,  259,  295,  261,  262,   72,   97,   93,   41,
  100,   41,   44,  295,   44,   46,   59,   93,  263,  264,
  265,   59,  273,  106,   93,  295,  266,   91,   93,   40,
   59,  268,  285,  271,  296,   58,   41,   59,   93,  272,
   93,   93,  269,  260,  296,  281,   59,  268,  266,  269,
  266,   58,  110,   59,   69,   73,   20,   37,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  266,   -1,   -1,
  269,   -1,   -1,  266,  273,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  266,   -1,  268,  269,
  266,  271,  268,  269,  274,  271,   -1,   -1,   -1,   -1,
  281,  281,   -1,   -1,   -1,  285,   -1,   -1,   -1,   -1,
  291,   -1,   -1,  291,  295,  296,  297,  295,  296,  297,
   -1,  266,   -1,  268,  269,   -1,  271,   -1,   -1,  274,
  266,   -1,  268,  269,   -1,  271,  281,  266,  274,  268,
  269,  266,  271,  268,  269,  281,  271,   -1,   -1,  274,
   -1,   -1,   -1,   -1,   -1,   -1,  281,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 297
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"DEF","VAR","ARRAY","OF","INTEGRAL","RATIONAL","FUNC","PROC","BBEGIN","END",
"IF","THEN","ELSE","WHILE","DO","DOTDOT","ASSIGNOP","RELOP","LT","LE","GT","GE",
"EQ","NE","ADDOP","PLUS","MINUS","OR","MULOP","STAR","SLASH","DIV","MOD","AND",
"NOT","FUNCTION_CALL","ARRAY_ACCESS","LIST","ID","INUM","RNUM",
};
static const char *yyrule[] = {
"$accept : program",
"program : DEF ID '(' identifier_list ')' ';' declarations subprogram_declarations compound_statement '.'",
"identifier_list : ID",
"identifier_list : identifier_list ',' ID",
"declarations : declarations VAR identifier_list ':' type ';'",
"declarations :",
"type : standard_type",
"type : ARRAY '[' range ']' OF standard_type",
"range : INUM DOTDOT INUM",
"standard_type : INTEGRAL",
"standard_type : RATIONAL",
"subprogram_declarations : subprogram_declarations subprogram_declaration ';'",
"subprogram_declarations :",
"subprogram_declaration : subprogram_header declarations subprogram_declarations compound_statement",
"$$1 :",
"subprogram_header : FUNC ID $$1 arguments ':' standard_type ';'",
"$$2 :",
"subprogram_header : PROC ID $$2 arguments ';'",
"arguments : '(' parameter_list ')'",
"arguments :",
"parameter_list : identifier_list ':' type",
"parameter_list : parameter_list ';' identifier_list ':' type",
"compound_statement : BBEGIN optional_statements END",
"optional_statements : statement_list",
"optional_statements :",
"statement_list : statement",
"statement_list : statement_list ';' statement",
"statement : matched_statement",
"statement : unmatched_statement",
"matched_statement : IF expression THEN matched_statement ELSE matched_statement",
"matched_statement : variable ASSIGNOP expression",
"matched_statement : procedure_statement",
"matched_statement : compound_statement",
"matched_statement : WHILE expression DO matched_statement",
"unmatched_statement : IF expression THEN statement",
"unmatched_statement : IF expression THEN matched_statement ELSE unmatched_statement",
"variable : ID",
"variable : ID '[' expression ']'",
"procedure_statement : ID",
"procedure_statement : ID '(' expression_list ')'",
"expression_list : expression",
"expression_list : expression_list ',' expression",
"expression : simple_expression",
"expression : simple_expression RELOP simple_expression",
"simple_expression : term",
"simple_expression : ADDOP term",
"simple_expression : simple_expression ADDOP term",
"term : factor",
"term : term MULOP factor",
"factor : ID",
"factor : ID '(' expression_list ')'",
"factor : ID '[' expression ']'",
"factor : INUM",
"factor : RNUM",
"factor : '(' expression ')'",
"factor : NOT factor",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 259 "qc.y"

main(){
	
	top_scope = scope_push(top_scope); //should have something in scope before you want to use it 
	yyparse(); /*entry point for parser*/
	//gencode_start($$);

}
#line 383 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 80 "qc.y"
	{ id_ptr = scope_insert( top_scope, yystack.l_mark[0].sval ); 
		   yyval.tval = make_id( id_ptr );}
break;
case 3:
#line 83 "qc.y"
	{ /*fprintf(stderr, "this is $3 %s \n", $3) ;*/ 
		 id_ptr = scope_insert( top_scope, yystack.l_mark[0].sval );
		fprintf(stderr, "this is list %d\n", LIST); 
		 yyval.tval =  make_tree(LIST, yystack.l_mark[-2].tval, make_id(id_ptr)); }
break;
case 4:
#line 91 "qc.y"
	{ semantic_set_type( yystack.l_mark[-3].tval, yystack.l_mark[-1].ival ); }
break;
case 6:
#line 95 "qc.y"
	{ yyval.ival = yystack.l_mark[0].ival; }
break;
case 7:
#line 97 "qc.y"
	{ yyval.ival = -1; }
break;
case 9:
#line 103 "qc.y"
	{ yyval.ival = INTEGRAL; }
break;
case 10:
#line 104 "qc.y"
	{ yyval.ival = RATIONAL; }
break;
case 13:
#line 116 "qc.y"
	{ top_scope = scope_pop( top_scope ); }
break;
case 14:
#line 120 "qc.y"
	{ /* do we need a tree here */  
			id_ptr = scope_insert( top_scope, yystack.l_mark[0].sval ); /* record function ID in current scope */
			top_scope = scope_push(top_scope);  /* create a new scope */
		}
break;
case 16:
#line 125 "qc.y"
	{ 
			id_ptr = scope_insert( top_scope, yystack.l_mark[0].sval ); /* record procedure ID in current scope */
			top_scope = scope_push(top_scope);  /* create a new scope */
		}
break;
case 20:
#line 135 "qc.y"
	{semantic_set_type( yystack.l_mark[-2].tval , yystack.l_mark[0].ival ); }
break;
case 21:
#line 136 "qc.y"
	{semantic_set_type( yystack.l_mark[-2].tval , yystack.l_mark[0].ival );}
break;
case 22:
#line 142 "qc.y"
	{ yyval.tval = yystack.l_mark[-1].tval; }
break;
case 23:
#line 145 "qc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 24:
#line 146 "qc.y"
	{ yyval.tval = NULL; }
break;
case 25:
#line 150 "qc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 26:
#line 152 "qc.y"
	{ yyval.tval = make_tree( LIST, yystack.l_mark[-2].tval, yystack.l_mark[0].tval ); }
break;
case 27:
#line 156 "qc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 28:
#line 158 "qc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 29:
#line 162 "qc.y"
	{
			yyval.tval = make_tree( IF, yystack.l_mark[-4].tval, make_tree( THEN, yystack.l_mark[-2].tval, yystack.l_mark[0].tval ));
		}
break;
case 30:
#line 166 "qc.y"
	{ 
			if (type_of(yystack.l_mark[-2].tval) != type_of(yystack.l_mark[0].tval) ){
				fprintf(stderr, "1 ERROR: mismatch in assignment type\n");
				exit(1);
			}
			yyval.tval = make_tree( ASSIGNOP, yystack.l_mark[-2].tval, yystack.l_mark[0].tval );
			
		}
break;
case 31:
#line 175 "qc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 32:
#line 177 "qc.y"
	{yyval.tval = yystack.l_mark[0].tval;}
break;
case 33:
#line 179 "qc.y"
	{yyval.tval = make_tree( WHILE, yystack.l_mark[-2].tval, yystack.l_mark[0].tval ); }
break;
case 34:
#line 183 "qc.y"
	{ yyval.tval = make_tree( IF, yystack.l_mark[-2].tval, yystack.l_mark[0].tval); }
break;
case 35:
#line 185 "qc.y"
	{ yyval.tval = make_tree(IF, yystack.l_mark[-4].tval, make_tree(THEN, yystack.l_mark[-2].tval, yystack.l_mark[0].tval)); }
break;
case 36:
#line 189 "qc.y"
	{
			id_ptr = semantic_lookup(top_scope, yystack.l_mark[0].sval);
			yyval.tval = make_id( id_ptr ); /*can make this a one liner*/
		}
break;
case 37:
#line 194 "qc.y"
	{
			id_ptr = semantic_lookup(top_scope, yystack.l_mark[-3].sval); /*change all of these with errors to lookup*/
			yyval.tval = make_tree( ARRAY_ACCESS, make_id (id_ptr), yystack.l_mark[-1].tval );
		}
break;
case 38:
#line 202 "qc.y"
	{ 
			id_ptr = semantic_lookup( top_scope, yystack.l_mark[0].sval);
			yyval.tval = make_id( id_ptr ); 
		}
break;
case 39:
#line 207 "qc.y"
	{ yyval.tval = make_tree( FUNCTION_CALL, make_id( semantic_lookup( top_scope, yystack.l_mark[-3].sval ) ) , yystack.l_mark[-1].tval); }
break;
case 40:
#line 211 "qc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 41:
#line 213 "qc.y"
	{ yyval.tval = make_tree( LIST, yystack.l_mark[-2].tval, yystack.l_mark[0].tval ); }
break;
case 42:
#line 217 "qc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 43:
#line 219 "qc.y"
	{ yyval.tval = make_tree( RELOP, yystack.l_mark[-2].tval, yystack.l_mark[0].tval ); yyval.tval->attribute.opval = yystack.l_mark[-1].opval; }
break;
case 44:
#line 223 "qc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 45:
#line 225 "qc.y"
	{ yyval.tval = make_tree( ADDOP, yystack.l_mark[0].tval, NULL ); yyval.tval->attribute.opval = yystack.l_mark[-1].opval; }
break;
case 46:
#line 227 "qc.y"
	{ yyval.tval = make_tree( ADDOP, yystack.l_mark[-2].tval, yystack.l_mark[0].tval); yyval.tval->attribute.opval = yystack.l_mark[-1].opval; }
break;
case 47:
#line 231 "qc.y"
	{ yyval.tval = yystack.l_mark[0].tval; }
break;
case 48:
#line 233 "qc.y"
	{ 
			yyval.tval = make_tree( MULOP, yystack.l_mark[-2].tval, yystack.l_mark[0].tval); 
			yyval.tval->attribute.opval = yystack.l_mark[-1].opval;
		}
break;
case 49:
#line 240 "qc.y"
	{ 
			id_ptr = semantic_lookup( top_scope, yystack.l_mark[0].sval);
			yyval.tval = make_id( id_ptr ); 
		}
break;
case 50:
#line 245 "qc.y"
	{ yyval.tval = make_tree( FUNCTION_CALL, make_id( semantic_lookup( top_scope, yystack.l_mark[-3].sval ) ) , yystack.l_mark[-1].tval); }
break;
case 51:
#line 247 "qc.y"
	{ yyval.tval = make_tree( ARRAY_ACCESS, make_id( semantic_lookup( top_scope, yystack.l_mark[-3].sval ) ), yystack.l_mark[-1].tval); }
break;
case 52:
#line 249 "qc.y"
	{ yyval.tval = make_inum( yystack.l_mark[0].ival ); }
break;
case 53:
#line 251 "qc.y"
	{ yyval.tval = make_rnum( yystack.l_mark[0].rval ); }
break;
case 54:
#line 253 "qc.y"
	{ yyval.tval = yystack.l_mark[-1].tval; }
break;
case 55:
#line 255 "qc.y"
	{ yyval.tval = make_tree( NOT, yystack.l_mark[0].tval, NULL ); }
break;
#line 807 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
