

FLAGS = -c -g -iquote inc -Wall
FINAL = -pedantic -Wall

RELOC = obj/main.o

_start_: ./out
	./out
./out: obj ${RELOC}
	g++ ${FINAL} -o ./out ${RELOC}
	rm -r obj

obj/main.o: main.cpp
	g++ ${FLAGS} -o obj/main.o main.cpp


obj:
	mkdir -p obj