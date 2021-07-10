CXX=clang-omp++
#CXXFLAGS=-Wall -I. -O2 -DNDEBUG
CXXFLAGS=-fopenmp -Wall -I. 
OBJS=Graph.o floyd_parallel.o
PROGS=floyd_parallel
NAME=floyd_parallel
floyd_parallel: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
all: $(PROGS)
clean:
	rm -f *.o $(PROGS)
