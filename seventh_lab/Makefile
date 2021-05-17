all: Clean BuildMain BuildTests RunTests

BuildMain:
	gcc -c main.c ClintList.c
	gcc -lm main.o ClintList.o -o main

BuildTests:
	gcc -o bin/tests/test -Dmain=_main main.c test.c

RunProgram:
	./main

RunTests:
	./bin/tests/test

Clean: 
	del main.o Clint.o main.exe test.exe