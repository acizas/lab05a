# Makefile

#CXX=clang++
CXX=g++

#CXXFLAGS = -std=c++11 =Wall -Wextra -Werror

lab04aTests: lab04aTests.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

tests: lab04aTests
	./lab04aTests

clean:
	/bin/rm -f *.o


