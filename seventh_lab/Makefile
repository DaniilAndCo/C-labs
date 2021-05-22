all: Clean BuildMain BuildTests RunTests

BuildMain:
	mkdir -p bin
	gcc -o bin/main main.c ClintList.c GoodsList.c -lm

BuildTests:
	gcc -o bin/test test.c ClintList.c GoodsList.c

RunProgram:
	./bin/main.exe

RunTests:
	./bin/test.exe

Clean: 
	rm -rf bin
	rm -rf *.gcda *.gcno