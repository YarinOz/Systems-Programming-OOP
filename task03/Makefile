CXX = g++	# the compiler
CXXFLAGS = -std=c++11	# the compiler flags

SRC_EXE = assignment1.cpp 
SRC_OBJ = Menu.cpp StackNode.cpp Stack.cpp MyQueue.cpp # the OBJ files
OBJ := $(patsubst %.cpp,%.o,$(SRC_OBJ))    # obj
EXEC = task3.out	# executable

all: $(EXEC) clean_obj 

%.o: %.cpp	# compile to obj
	$(CXX) $(CXXFLAGS) -c $< -o $@ 	

$(EXEC): $(OBJ)	# link to executable
	$(CXX) $(CXXFLAGS) $(SRC_EXE) $^ -o $@

clean_obj:
	rm -f $(OBJ)

run: 
	./$(EXEC)

clean:
	rm -f $(EXEC)

.PHONY: clean