all: Clean BuildMain BuildTests RunTests

BuildMain:
	mkdir -p bin/program
	gcc -std=c89 -o bin/program/main main.c

BuildTests:
	mkdir -p bin/tests
	gcc -std=c89 -o bin/tests/tests -Dmain=_main main.c tests.c

RunProgram:
	./bin/program/main

RunTests:
	./bin/tests/tests

Clean: 
	rm -rf bin