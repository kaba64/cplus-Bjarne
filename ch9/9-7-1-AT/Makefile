CC := g++ -std=c++20 -Wall -fmax-errors=3
TARGET_EXEC := out
SRCS := argumentType.cpp
OBJS=$(SRCS:.cpp=.o)


$(TARGET_EXEC): $(OBJS)
	$(CC) $^ -o $@
%.o: %.cpp
	$(CC) -c $< -o $@
clean:
	rm $(OBJS) $(TARGET_EXEC) *~
run:
	@./$(TARGET_EXEC)
