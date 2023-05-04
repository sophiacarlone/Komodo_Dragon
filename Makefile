qc: y.tab.o lex.yy.o semantic.o tree.o symtab.o list.o 
	gcc -g -o qc y.tab.o lex.yy.o semantic.o tree.o symtab.o list.o -ly -ll -std=c11

y.tab.o: y.tab.c
	gcc -g -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -g -c lex.yy.c

semantic.o: semantic.c
	gcc -g -c semantic.c -std=c11

tree.o: tree.c
	gcc -g -c tree.c -std=c11

symtab.o: symtab.c
	gcc -g -c symtab.c -std=c11

list.o: list.c
	gcc -g -c list.c -std=c11

y.tab.c: qc.y
	yacc -dv qc.y

lex.yy.c: qc.l
	lex -l qc.l

clean:
	rm -f y.tab.* lex.yy.* *.o qc
