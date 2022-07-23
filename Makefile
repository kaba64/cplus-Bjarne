CC := g++ -std=c++2a
TARGET_EXEC := out
CFLAGS  := -Wall
SRCS := free-store-pointer.cpp
OBJS := free-store-pointer.o

$(TARGET_EXEC): $(OBJS)
	$(CC) $^ -o $@
$(OBJS): $(SRCS)
	$(CC) -c $<
clean:
	rm $(OBJS) $(TARGET_EXEC) *~
