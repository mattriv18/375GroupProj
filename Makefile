H = heapDijkstras
L = lazyheapDijkstras
M = matrixDijkstras

all: $(H) $(L) $(M)

testcases: testcases.o
    g++ testcases.o -o testcases

testcases.o: testcases.cpp
    g++ -c -g testcases.cpp

$(H): $(H).o
	g++ -g $(H).o -o $(H)
$(H).o: $(H).cpp Graph.h MinHeap.h
	g++ -g -c $(H).cpp -o $(H).o
$(L): $(L).o
	g++ -g $(L).o -o $(L)
$(L).o: $(L).cpp
	g++ -g -c $(L).cpp -o $(L).o
$(M): $(M).o
	g++ -g $(M).o -o $(M)
$(M).o: $(M).cpp
	g++ -g -c $(M).cpp -o $(M).o

run: all
	./$(H) testinput.txt
	./$(L) testinput.txt
	./$(M) testinput.txt
runheap: $(H)
	./$(H) testinput.txt
runlazyheap: $(L)
	./$(L) testinput.txt
runmatrix: $(M)
	./$(M) testinput.txt
clean:
	rm *.o $(H) $(L) $(M) testcases
memcheckheap: $(H)
	valgrind --leak-check=full ./$(H) testinput.txt
memchecklazyheap: $(L)
	valgrind --leak-check=full ./$(L) testinput.txt
memcheckmatrix: $(M)
	valgrind --leak-check=full ./$(M) testinput.txt
	
