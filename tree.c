#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "tree.h"
#include "y.tab.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))

FILE *fptr;

void aux_print_tree( tree_t *, int );
void gencode( tree_t *t, int *registers, int start, int r);
void gencode_statements( tree_t *t, int *registers, int start, int r);
void gencode_expressions( tree_t *t, int *registers, int start, int r);
void swap_top(int *arr);

/* basic constructor */
tree_t *make_tree( int type, tree_t *l, tree_t *r )
{
	tree_t *p = (tree_t *)malloc( sizeof(tree_t) );
	assert( p != NULL );
	p->type = type;
	p->left = l;
	p->right = r;
	return p;
}

tree_t *make_id( list_t *name ){
	tree_t *p = make_tree( ID, NULL, NULL );
	p->attribute.sval = name;
	return p;
}

tree_t *make_inum( int val ){
	tree_t *p = make_tree( INUM, NULL, NULL );
	p->attribute.ival = val;
	return p;
}

tree_t *make_rnum( float val ){
	tree_t *p = make_tree( RNUM, NULL, NULL );
	p->attribute.rval = val;
	return p;
}

/* pre-order tree traversal */
void print_tree( tree_t *t )
{
	aux_print_tree( t, 0 ); //for spacing purposes
}

void aux_print_tree( tree_t *t, int spaces )
{
	if ( t == NULL ) return;

	/* indenting for visual effects */
	for (int i=0; i<spaces; i++)
		fprintf( stderr, " " );

	switch( t->type ) {
	case ASSIGNOP:
		//fprintf(stderr, "hit\n");
		fprintf( stderr, "[ASSIGNOP:%d]\n", t->attribute.sval ); 
		aux_print_tree( t->left, spaces+4 ); //should be variable that is getting assigned
		aux_print_tree( t->right, spaces+4 ); //what variable is being assigned to
		break;

	case RELOP: /*this is the first thing to change*/
		fprintf( stderr, "[RELOP:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case ADDOP: /*this is the first thing to change*/
		fprintf( stderr, "[ADDOP:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case MULOP:
		fprintf( stderr, "[MULOP:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case ID: /*need RNUM*/
		fprintf( stderr, "[ID:%s]\n", t->attribute.sval );
		break;
	case INUM: /*need RNUM*/
		fprintf( stderr, "[INUM:%d]\n", t->attribute.ival );
		break;
	case RNUM: /*need RNUM*/
		fprintf( stderr, "[RNUM:%f]\n", t->attribute.rval );
		break;
	default:
		fprintf( stderr, "Error: print_tree, unknown type\n" );
		exit(1);
	}

/*	case LT:  //LE GT GE EQ NE PLUS MINUS OR STAR SLASH DIV MOD AND NOT 
		fprintf( stderr, "[LT:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case LE: 
		fprintf( stderr, "[LE:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case GT: 
		fprintf( stderr, "[GT:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case GE: 
		fprintf( stderr, "[GE:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case EQ: 
		fprintf( stderr, "[EQ:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case NE: 
		fprintf( stderr, "[NE:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case PLUS: 
		fprintf( stderr, "[PLUS:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case MINUS: 
		fprintf( stderr, "[MINUS:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case OR: 
		fprintf( stderr, "[OR:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case STAR: 
		fprintf( stderr, "[STAR:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case SLASH: 
		fprintf( stderr, "[SLASH:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case DIV: 
		fprintf( stderr, "[DIV:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case MOD: 
		fprintf( stderr, "[MOD:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case AND: 
		fprintf( stderr, "[AND:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
	case NOT: 
		fprintf( stderr, "[NOT:%d]\n", t->attribute.opval );
		aux_print_tree( t->left, spaces+4 );
		aux_print_tree( t->right, spaces+4 );
		break;
*/
}

/* evaluate the tree */
int eval_tree( tree_t *t )
{
	if ( t == NULL ){
		return -1;
		fprintf(stderr, "Panic in eval_tree\n");
		exit(1);
	} 

        switch( t->type ) {
        case ADDOP:
		switch(t->attribute.opval){
			case PLUS:
		                t->evaluation = eval_tree(t->left) + eval_tree(t->right);
				break;
			case MINUS:
		                t->evaluation = eval_tree(t->left) - eval_tree(t->right);
				break;
			case OR:
		                t->evaluation = eval_tree(t->left) ^ eval_tree(t->right);
				break;
		        default:
                		fprintf( stderr, "Error: eval_tree, unknown type\n" );
                		exit(1);
		}
                //t->evaluation = eval_tree(t->left) + eval_tree(t->right);
		//break;

        case MULOP:
 		switch(t->attribute.opval){
			case STAR:
		                t->evaluation = eval_tree(t->left) * eval_tree(t->right);
				break;
			case SLASH:
		                t->evaluation = eval_tree(t->left) / eval_tree(t->right);
				break;
			case DIV:
		                t->evaluation = eval_tree(t->left) / eval_tree(t->right);
				break;
			case MOD:
		                t->evaluation = eval_tree(t->left) % eval_tree(t->right);
				break;
			case AND:
		                t->evaluation = eval_tree(t->left) & eval_tree(t->right);
				break;
		        default:
                		fprintf( stderr, "Error: eval_tree, unknown type\n" );
                		exit(1);
		}

                //t->evaluation = eval_tree(t->left) * eval_tree(t->right);
		//break;
        case RELOP:
 		switch(t->attribute.opval){
			case LT:
		                t->evaluation = eval_tree(t->left) < eval_tree(t->right);
				break;
			case LE:
		                t->evaluation = eval_tree(t->left) <= eval_tree(t->right);
				break;
			case GT:
		                t->evaluation = eval_tree(t->left) > eval_tree(t->right);
				break;
			case GE:
		                t->evaluation = eval_tree(t->left) >= eval_tree(t->right);
				break;
			case EQ:
		                t->evaluation = eval_tree(t->left) == eval_tree(t->right);
				break;
			case NE:
		                t->evaluation = eval_tree(t->left) != eval_tree(t->right);
				break;
		        default:
                		fprintf( stderr, "Error: eval_tree, unknown type\n" );
                		exit(1);
		}
                //t->evaluation = eval_tree(t->left) + eval_tree(t->right);
		//break;
        case INUM:
                t->evaluation = t->attribute.ival; //how to get the value out of NUM?
		break;
        case RNUM:
                t->evaluation = t->attribute.rval; //how to get the value out of NUM?
		break;
       default:
                fprintf( stderr, "Error: eval_tree, unknown type\n" );
                exit(1);
        }
	return(t->evaluation);
}

/*rank of tree*/
int rank( tree_t *t, int d)
{
	int left, right;

	if( (t->left == NULL) && (t->right == NULL) )
		t->rank = d;	

	else{
	left = rank( t->left, 1);
	right = rank( t->right, 0);

	if(left != right)
		t->rank = max(left, right);
	else
		t->rank = 1 + left;
	}
	
	return t->rank;
}

void gencode_start( tree_t *t ){

 	fptr = fopen("assembly.s","w"); //test 1

   	if(fptr == NULL){
      		printf("Error with file");   
      		exit(1);             
   	}	

/*	t->rank = rank(t, 1);
	int* stack_registers = (int*) malloc(t->rank * sizeof(int));
	//int stack_registers[t->rank];
	int i;
	for( i = 0; i < t->rank; i++)
		stack_registers[i] = i;
	int start = 0;
	gencode( t, stack_registers, start, t->rank); */
}

//generation of assembley code 
void gencode( tree_t *t, int *registers, int start, int r){
 //separate out what is a statement and what is an expression
 //if expression
 //	gencode_expressions( tree_t *t, int *registers, int start, int r );
 //else 
 //	gencode_statements( tree_t *t, int *registers, int start, int r );
}

//generation of code for statements
void gencode_statements( tree_t *t, int *registers, int start, int r){

}

//generation of code for expressions
void gencode_expressions( tree_t *t, int *registers, int start, int r){
	int popped = 0;
	int right_rank = 0;
	int left_rank = 0;

	/* case 0 */
	if( (t->left == NULL) && (t->right == NULL) && (t->rank == 1) ){
		fprintf(fptr, "MOV %d, R%d\n", t->attribute, registers[start]);
	}
	else if( (t->left != NULL) || (t->right != NULL)){
		right_rank = rank(t->right, 0);
		left_rank = rank(t->left, 1);
		
		/* case 1 */
		if ( right_rank == 0 ){
			gencode(t->left, registers, start, r);
			if(t->type == ADDOP)
				//can we do a switch case statement based on what type of ADDOP value?
				fprintf(fptr, "ADD %d, R%d\n", t->right->attribute, registers[start]);
			else
				fprintf(fptr, "MUL %d, R%d\n", t->right->attribute, registers[start]);
			//continue?
		}
		/* case 2 */
		else if (( 1 <= left_rank )&&( left_rank < right_rank )
			&& ( left_rank < r )) { //r is the number of registers
			swap_top(registers);
			gencode(t->right, registers, start, r);
			popped = registers[start];
			start++;
			gencode(t->left, registers, start, r);
			//make these all into a function
			if(t->type == '+')
				fprintf(fptr, "ADD R%d, R%d\n", popped, registers[start]); //can also make pop registers[start-1]
			else
				fprintf(fptr, "MUL R%d, R%d\n", popped, registers[start]);
			start--;
			swap_top(registers);
		}

		/* case 3 */
		else if (( 1 <= right_rank ) && ( right_rank <= left_rank )
			&& (right_rank < r)){
			gencode(t->left, registers, start, r);
			//pop
			popped = registers[start];
			start++;
			gencode(t->right, registers, start, r);
			if(t->type == '+')
				fprintf(fptr, "ADD R%d, R%d\n", registers[start], popped);
			else
				fprintf(fptr, "MUL R%d, R%d\n", registers[start], popped);
			//push
			start--;
		}
		else
			fprintf(stderr, "falling through");
		/* not doing case 4 yet? */
	}
}

void swap_top(int *arr){
	int temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}




