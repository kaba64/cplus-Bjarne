CC := g++ -std=c++14 -Wall
TARGET_EXEC := out
CFLAGS  := -Wall
SRCS := main.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET_EXEC): $(OBJS)
	$(CC) $^ -o $@
$(OBJS): $(SRCS)
	$(CC) -c $<
clean:
	rm $(OBJS) $(TARGET_EXEC) *~
run:
	@./$(TARGET_EXEC)
