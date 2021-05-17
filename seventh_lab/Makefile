all: Clean BuildMain BuildTests RunTests

BuildMain:
	gcc -c main.c ClintList.c
	gcc -lm main.o ClintList.o -o main.exe

BuildTests:
	gcc test.c ClintList.c -o test

RunProgram:
	./main.exe

RunTests:
	./test.exe

Clean: 
	rm *.exe *.o