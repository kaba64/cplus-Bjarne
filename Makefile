CC := g++ -std=c++2a
TARGET_EXEC := out
CFLAGS  := -Wall
SRCS := vector1.cpp
OBJS := vector1.o

$(TARGET_EXEC): $(OBJS)
	$(CC) $^ -o $@
$(OBJS): $(SRCS)
	$(CC) -c $<
clean:
	rm $(OBJS) $(TARGET_EXEC) *~
