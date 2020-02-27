# Makefile

#CXX=clang++
CXX=g++

#CXXFLAGS = -std=c++11 =Wall -Wextra -Werror

lab04aTests: lab04aTests.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

lab05aTests: lab05aTests.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

tests: Tests
	./lab04aTests
	./lab05aTests

clean:
	/bin/rm -f *.o


