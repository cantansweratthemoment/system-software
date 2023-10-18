all: clean install

clean:
	rm -rf *.o spo-ast lex.yy.c grammer.tab.c grammer.tab.h

lex.yy.c: utils/lexer.l
	flex utils/lexer.l

error.o: structures/error.c
	gcc -c -o error.o structures/error.c

grammer.tab.c: utils/grammer.y
	bison -d -t utils/grammer.y

ast.o: structures/abstract_syntax_tree.c
	gcc -c -o ast.o structures/abstract_syntax_tree.c

list.o: structures/operation_tree.c
	gcc -c -o list.o structures/operation_tree.c

graph.o: structures/control_flow_graph.c
	gcc -c -o graph.o structures/control_flow_graph.c

main.o: main.c
	gcc -c -o main.o main.c

lex.yy.o: lex.yy.c
	gcc -c -o lex.yy.o lex.yy.c

grammer.tab.o: grammer.tab.c
	gcc -c -o grammer.tab.o grammer.tab.c

install: ast.o graph.o list.o grammer.tab.o lex.yy.o main.o error.o
	gcc ast.o graph.o list.o  grammer.tab.o lex.yy.o main.o error.o -o spo-ast && chmod +x spo-ast

run_ast: install
	./spo-ast example.a ast | dot -Tsvg > ast.svg

run_cfg: install
	./spo-ast example.a cfg | dot -Tsvg > cfg.svg