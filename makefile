bin/hello: src/main.c
	gcc -o bin/hello src/main.c -I.
clean:
	rm -f obj/*.o bin/hello
