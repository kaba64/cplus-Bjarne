CC := g++ -std=c++2a -Wall
TARGET_EXEC := out
CFLAGS  := -Wall
SRCS := bad-input.cpp
OBJS=$(SRCS:.cpp=.o)


$(TARGET_EXEC): $(OBJS)
	$(CC) $^ -o $@
bad-input.o: bad-input.cpp
	$(CC) -c $<
clean:
	rm $(OBJS) $(TARGET_EXEC) *~
run:
	@./$(TARGET_EXEC)
