all: LinkedStack_test ResizingArrayStack_test

LinkedStack_test : LinkedStack_test.o
	g++ -o LinkedStack_test LinkedStack_test.o

LinkedStack_test.o : LinkedStack_test.cpp LinkedStack.h
	g++ -c LinkedStack_test.cpp

ResizingArrayStack_test: ResizingArrayStack_test.o
	g++ -o ResizingArrayStack_test ResizingArrayStack_test.o

ResizingArrayStack_test.o : ResizingArrayStack_test.cpp ResizingArrayStack.h
	g++ -c ResizingArrayStack_test.cpp

clean :
	rm *.o LinkedStack_test ResizingArrayStack_test
