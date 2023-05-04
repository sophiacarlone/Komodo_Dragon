#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h" //order matters
#include "tree.h"
#include "symtab.h"
#include "semantic.h"
#include "y.tab.h" //list of constants

// check that an identifier exists when used
list_t *semantic_lookup( scope_t *top_scope, char *name ){
	list_t *p = global_scope_search( top_scope, name );
	if ( p == NULL ){
		fprintf( stderr, "ERROR: name(%s) used but undeclared\n", name );
		exit(1);
	}
	return p;
}

//Set all types in a list of identifiers
void semantic_set_type( tree_t *id_list, int type_val ){ //visit all leaves, and insert
	if ( id_list == NULL ) return;
	
	tree_t *left, *right;
	left = id_list->left;
	right = id_list->right;

	if (left == NULL && right == NULL ){ //bottom node
		id_list->attribute.sval->type = type_val; //pointer into symbol table
		fprintf( stderr, "[SET_TYPE: %s, %d]\n", id_list->attribute.sval->name, id_list->attribute.sval->type );
	}
	//set type of right child (ID)
	else if( right != NULL ){
		right->attribute.sval->type = type_val; //pointer into symbol table
		fprintf( stderr, "[SET_TYPE: %s, %d]\n", right->attribute.sval->name, right->attribute.sval->type );
		semantic_set_type(left, type_val );
	}
}

//returns the type of a tree
int type_of( tree_t *t ){
	if( t == NULL ) return TYPE_ERROR; 

	int left_type, right_type;

	switch( t->type ){
	case ID:
		return t->attribute.sval->type; //not recommended
		break;

	//could be ADDOP, MULOP, etc

	case INUM:
		return INTEGRAL;
		break;

	case RNUM:
		return RATIONAL;
		break;

	case ADDOP:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in ADDOP\n");
			exit(1);
		}
		return left_type;

	case MULOP:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in MULOP\n");
			exit(1);
		}
		return left_type;

	case RELOP:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in RELOP\n");
			exit(1);
		}
		return left_type;
/*
	case LT:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in LT\n");
			exit(1);
		}
		return left_type;

	case LE:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in LE\n");
			exit(1);
		}
		return left_type;

	case GT:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in GT\n");
			exit(1);
		}
		return left_type;

	case GE:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in GE\n");
			exit(1);
		}
		return left_type;

	case EQ:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in EQ\n");
			exit(1);
		}
		return left_type;

	case NE:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in NE\n");
			exit(1);
		}
		return left_type;

	case PLUS:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in PLUS\n");
			exit(1);
		}
		return left_type;

	case MINUS:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in MINUS\n");
			exit(1);
		}
		return left_type;

	case OR:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in OR\n");
			exit(1);
		}
		return left_type;

	case STAR:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in STAR\n");
			exit(1);
		}
		return left_type;

	case SLASH:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in SLASH\n");
			exit(1);
		}
		return left_type;

	case DIV:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in DIV\n");
			exit(1);
		}
		return left_type;

	case MOD:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in MOD\n");
			exit(1);
		}
		return left_type;

	case AND:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in AND\n");
			exit(1);
		}
		return left_type;

	case NOT:
		left_type = type_of(t->left);
		right_type = type_of(t->right);

		if ( left_type != right_type ){
			fprintf( stderr, "ERROR: type mismatch in NOT\n");
			exit(1);
		}
		return left_type;
*/
	default:
		return TYPE_ERROR;
		break;
	}
}
