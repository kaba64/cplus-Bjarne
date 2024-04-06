CC := g++ -std=c++14 -Wall -g
CFLAGS  := -lfltk -lfltk_images -lfltk_forms -lfltk_gl -lfltk_cairo
LIBS := -L/usr/lib/x86_64-linux-gnu/
SRC_DIR := .
UTILS_DIR := ./../utils
OBJ_DIR := obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
UTILS_FILES = $(wildcard $(UTILS_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES)) $(patsubst $(UTILS_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(UTILS_FILES))

EXECUTABLE := myprogram

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $^ -o $@ $(LIBS) $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r $(OBJ_DIR) $(EXECUTABLE) *~
run:
	@./$(EXECUTABLE)
