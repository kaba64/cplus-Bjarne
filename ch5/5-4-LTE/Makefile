CC := g++ -std=c++2a -Wall
TARGET_EXEC := out
CFLAGS  := -Wall
SRCS := link-time-error.cpp area.cpp
OBJS=$(SRCS:.cpp=.o)


$(TARGET_EXEC): $(OBJS)
	$(CC) $^ -o $@
link-time-error.o: link-time-error.cpp
	$(CC) -c $<
area.o: area.cpp
	$(CC) -c $<
clean:
	rm $(OBJS) $(TARGET_EXEC) *~
run:
	@./$(TARGET_EXEC)
