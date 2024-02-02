CC := g++ -std=c++2a -Wall
TARGET_EXEC := out
CFLAGS  := -Wall
SRCS := constant-expression.cpp
OBJS := constant-expression.o

$(TARGET_EXEC): $(OBJS)
	$(CC) $^ -o $@
%.o: %.cpp
        $(CC) -c $< -o $@
clean:
	rm $(OBJS) $(TARGET_EXEC) *~
run:
	@./$(TARGET_EXEC)
