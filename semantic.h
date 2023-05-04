#ifndef SEMANTIC_H
#define SEMANTIC_H

#define TYPE_ERROR -1

list_t *semantic_lookup( scope_t *top_scope, char *name);
void semantic_set_type( tree_t *id_list, int type_val);
int type_of( tree_t *t );

#endif
