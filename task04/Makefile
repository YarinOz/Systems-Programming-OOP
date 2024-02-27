CXX = g++	# the compiler
CXXFLAGS = -std=c++11	# the compiler flags

SRC_EXE = assignment2.cpp 
SRC_OBJ = Menu.cpp SavingsAccount.cpp CheckingAccount.cpp Account.cpp # the OBJ files
OBJ := $(patsubst %.cpp,%.o,$(SRC_OBJ))    # obj
EXEC = task4.out	# executable

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