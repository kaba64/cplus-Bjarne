CC := g++ -std=c++20 -Wall -g
SRC_DIR := .
OBJ_DIR := obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

EXECUTABLE := myprogram

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $^ -o $@ $(LIBS) $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -r $(OBJ_DIR) $(EXECUTABLE) *~
run:
	@./$(EXECUTABLE)
