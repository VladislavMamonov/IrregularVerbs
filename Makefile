all: bin/IrregularVerbs

bin/IrregularVerbs: build/src/main.o build/src/IrregularVerbs.o
	gcc -Wall -Werror -g build/src/main.o build/src/IrregularVerbs.o -o bin/IrregularVerbs 

build/src/main.o: src/main.c
	gcc -Wall -Werror -c -g src/main.c -o build/src/main.o

build/src/IrregularVerbs.o: src/IrregularVerbs.c
	gcc -Wall -Werror -c -g src/IrregularVerbs.c -o build/src/IrregularVerbs.o


test: bin/IrregularVerbs_test

bin/IrregularVerbs_test: build/test/main.o build/test/IrregularVerbs.o
	gcc -Wall -Werror build/test/main.o build/test/IrregularVerbs.o -o bin/IrregularVerbs_test

build/test/main.o: test/main.c
	gcc -Wall -Werror -c -I thirdparty -I src test/main.c -o build/test/main.o

build/test/IrregularVerbs.o: src/IrregularVerbs.c src/IrregularVerbs.h
	gcc -Wall -Werror -c -I thirdparty -I src src/IrregularVerbs.c -o build/test/IrregularVerbs.o


.PHONY: clean
clean:
	rm -rf build/src/*.o bin/IrregularVerbs
	rm -rf build/test/*.o bin/IrregularVerbs_test
