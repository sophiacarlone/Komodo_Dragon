#ifndef SYMTAB_H
#define SYMTAB_H

#include "list.h"

#define HASH_SIZE 	211
#define EOS 		'\0'

typedef struct scope_s{ //stackable scope
	list_t *table[HASH_SIZE]; //hash table
	struct scope_s *next;
} scope_t;

scope_t *make_scope();
void free_scope( scope_t * );

scope_t *scope_push( scope_t *top );
scope_t *scope_pop( scope_t *top );

list_t *scope_insert( scope_t *top, char *name );
list_t *scope_search( scope_t *top, char *name );
list_t *global_scope_search( scope_t *top, char *name );

#endif
