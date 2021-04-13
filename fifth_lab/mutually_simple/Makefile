all: Clean BuildMain BuildTests RunTests

BuildMain:
	mkdir -p bin/program
	g++ -o bin/program/Main Main.cpp -lm

BuildTests:
	mkdir -p bin/tests
	g++ -o bin/tests/tests -Dmain=_main Main.cpp tests.cpp -lm

RunProgram:
	./bin/program/Main

RunTests:
	./bin/tests/tests

Clean: 
	rm -rf bin