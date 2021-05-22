all: Clean BuildMain BuildTests RunTests

BuildMain:
	mkdir -p bin
	gcc -o bin/main main.c c-files/ClintList.c c-files/GoodsList.c -lm

BuildTests:
	gcc -o bin/test c-files/test.c c-files/ClintList.c c-files/GoodsList.c

RunProgram:
	./bin/main.exe

RunTests:
	./bin/test.exe

Clean: 
	rm -rf bin
	rm -rf *.gcda *.gcno