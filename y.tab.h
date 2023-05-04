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
extern YYSTYPE yylval;
