ctest:
	rm -f tests.exe
	g++ -Wall -std=c++20 tests.cpp -o tests.exe

gtest:
	rm -f tests.exe
	g++ -g -std=c++20 -Wall tests.cpp -o tests.exe -lgtest -lgtest_main -lpthread

runtest:
	./tests.exe

clean:
	rm -f program.exe
	rm -f tests.exe

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./program.exe

leaks:
	leaks --atExit --list -- ./program.exe