CC := g++ -std=c++20
TARGET_EXEC := myprogram
CFLAGS  := -Wall -g
SRC_DIR = .
OBJ_DIR = obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
EXECUTABLE = myprogram

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if [ ! -d $(dir $@) ];then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FILES): vector.h vector.hpp

clean:
	rm -r $(OBJ_DIR) $(EXECUTABLE) *~
run:
	@./$(EXECUTABLE)
