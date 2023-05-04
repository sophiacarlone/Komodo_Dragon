#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "symtab.h"

int hashpjw( char * );

scope_t *make_scope(){
	scope_t *p = (scope_t *)malloc( sizeof(scope_t) );
	assert( p != NULL );
	/* clear array memory */
	for (int i = 0; i < HASH_SIZE; i++) p->table[i] = NULL;
	p->next = NULL;
	return p;
}

void free_scope( scope_t *p ){
	/* buggy */
	free(p);
}

scope_t *scope_push( scope_t *top ){
	scope_t *p = make_scope();
	if ( top != NULL ) {
		p->next = top;
	}
	return p;
}

scope_t *scope_pop( scope_t *top ){
	if ( top != NULL ){
		scope_t *tmp;
		tmp = top -> next;
		free_scope(top);
		return tmp;
	}
	else return NULL;
}

list_t *scope_insert( scope_t *top, char *name ){
	if (top == NULL) return NULL;

	int index = hashpjw(name);
	list_t *start = top->table[index];
	top->table[index] = list_insert( start, name );
	return top->table[index];
}

list_t *scope_search( scope_t *top, char *name ){
	int index = hashpjw(name);

	if (top == NULL ) return NULL;
	list_t *start = top->table[index];
	return list_search( start, name );
}

list_t *global_scope_search( scope_t *top, char *name ){
	scope_t *curr = top;
	list_t *p;
	
	while ( curr != NULL ) { /* searching all scopes */
		p = scope_search( curr, name );
		if ( p != NULL ) /*found*/
			return p;
		curr = curr->next;
	}
	return NULL;
}

int hashpjw( char *s ){
	char *p;
	unsigned h = 0, g;

	for ( p = s; *p != EOS; p++ ){
		h = ( h << 4) + (*p);
		if ( (g = h & 0xf0000000) ){
			h = h ^ ( g >> 24 );
			h = h ^ g;
		}
	}
	
	return h % HASH_SIZE;
}
