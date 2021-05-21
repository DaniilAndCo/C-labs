all: Clean BuildMain BuildTests RunTests

BuildMain:
	gcc -c main.c ClintList.c GoodsList.c
	gcc -lm main.o ClintList.o GoodsList.o -o main.exe

BuildTests:
	gcc test.c ClintList.c GoodsList.c -o test

RunProgram:
	./main.exe

RunTests:
	./test.exe

Clean: 
	rm -rf *.exe *.o *.gcda *.gcno