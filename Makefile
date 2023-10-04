all: result

clean:
	rm -rf *.o result

out:
	mkdir out

lex.yy.c: lexer.l
	flex lexer.l

error.o: error.c
	gcc -c -o error.o error.c

grammer.tab.c: grammer.y
	bison -d -t grammer.y

main.o: main.c out
	gcc -c -o main.o main.c

ast.o: ast.c
	gcc -c -o ast.o ast.c

lex.yy.o: lex.yy.c
	gcc -c -o lex.yy.o lex.yy.c

grammer.tab.o: grammer.tab.c
	gcc -c -o grammer.tab.o grammer.tab.c

result: ast.o grammer.tab.o lex.yy.o main.o error.o
	gcc main.o grammer.tab.o lex.yy.o ast.o error.o -o result && chmod +x result

run: result
	./result ./example.a | dot -Tsvg > output.svg