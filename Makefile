all: bin/IrregularVerbs

bin/IrregularVerbs: build/src/main.o build/src/IrregularVerbs.o
	gcc -Wall -Werror build/src/main.o build/src/IrregularVerbs.o -o bin/IrregularVerbs 

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/IrregularVerbs.o: src/IrregularVerbs.c
	gcc -Wall -Werror -c src/IrregularVerbs.c -o build/src/IrregularVerbs.o


.PHONY: clean
clean:
	rm -rf build/src/*.o bin/IrregularVerbs
	rm -rf build/test/*.o bin/test
