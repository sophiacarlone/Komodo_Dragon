#ifndef LIST_H
#define LIST_H

typedef struct list_s{
	char *name; /*id name */
	int class_; /*(SIMPLE VARIABLE, FUNCTION NAME, PROCEDURE NAME, ARRAY NAME) type of name*/
	int type; /*(INTERGRAL, RATIONAL, ARRAY[LOWER, UPPER] )type info, incomplete */
	/* Additional info
 *	FUNC, PROC : sequence of expected types (which includes num of arguments) develop a list or type structure for this
 *	code generation: offset from stack pointer
 * 	*/
	struct list_s *next;
}list_t;

/*constructor destructor*/
list_t *make_list( char * );
void free_list( list_t * );

list_t *list_insert( list_t *, char *name );
list_t *list_search( list_t *, char *str );

void list_print( list_t * );

#endif
