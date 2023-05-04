#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "symtab.h"

#define MAX_LEN 32

int main(){
	int choice;
	scope_t *top = NULL;
	list_t *p = NULL;
	char buffer[MAX_LEN];

	while (1) {
		printf( "0.insert 1.search 2.search_all 3.push 4.pop\n" );
		scanf( "%d", &choice );
		switch (choice){
		case 0:
			printf( "insert name = " );
			scanf( "%s", buffer );
			p = scope_insert( top, buffer);
			if ( p != NULL)
				printf( "inserted\n" );
			else printf("not inserted\n");
			break;
		case 1:
			printf( "search name = " );
			scanf( "%s", buffer );
			p = scope_search( top, buffer);
			if ( p != NULL ) printf( "found\n");
			else printf( "not found\n" );	
			break;
		case 2:
			printf( "global search name = " );
			scanf( "%s", buffer );
			p = global_scope_search( top, buffer);
			if ( p != NULL ) printf( "found\n");
			else printf( "not found\n" );	
			break;
		case 3: 
			top = scope_push( top );
			break;
		case 4:
			top = scope_pop( top );
			break;
		default:
			printf( "Error option: %d\n", choice);
		} 
	}
}
