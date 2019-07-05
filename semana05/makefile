# Declaration of variables
CC = g++
CC_FLAGS = -w -std=c++11 -Wfatal-errors
 
# File names
EXEC = run
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
 
# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)
 
# To obtain object files
%.o: %.cpp
	@echo "\033[1;37mBuilding" $< "\033[0m"
	@$(CC) -c $(CC_FLAGS) $< -o $@
	

#$(*F) deu certo
 
# To remove generated files
clean:
	@echo "Removing executables"
	@rm -f $(EXEC) $(OBJECTS)