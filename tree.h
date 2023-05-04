#ifndef TREE_H
#define TREE_H

#define max(a, b) (((a) > (b)) ? (a) : (b))

/* #include "list.h" */ 

typedef struct tree_s {
	int type;	/* token types: ADDOP, MULOP, NUM */
	union {
		int ival;
		float rval;
		list_t *sval; /* pointer to symbol table where id appears */
		int opval;
	} attribute;	/*  */
	struct tree_s *left;
	struct tree_s *right;
	int evaluation;
	int rank; 
} tree_t;

tree_t *make_tree( int v, tree_t *l, tree_t *r ); //a being attribute
void print_tree( tree_t *t );
int eval_tree( tree_t *t );
tree_t *make_id( list_t * );
tree_t *make_inum( int );
tree_t *make_rnum( float );
int rank( tree_t *t, int d );
void gencode_start( tree_t *t );

#endif


