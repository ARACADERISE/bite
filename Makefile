C_FILE = $(wildcard */*/*.c)
H_FILE = $(wildcard */*/*.h)
C = $(wildcard */*.c)
H = $(wildcard */*.h)
COMP = gcc -Wall -o main.o main.c
VALGRIND = valgrind ./main.o
file = null

.PHONY: Bite
.PHONY: clean
.PHONY: Memory_Check

Bite: ${SRC} ${HDR}
	${COMP} ${C_FILE} ${H_FILE} ${C} ${H} && ./main.o

Memory_Check: ${C_FILE} ${C} ${H_FILE} ${H}
	${VALGRIND} ${file}

clean: ${SRC} ${HDR}
	rm *.o