CC := g++ -std=c++2a -Wall
TARGET_EXEC := out
CFLAGS  := -Wall
<<<<<<< HEAD
SRCS := namespace.cpp
OBJS := namespace.o
=======
SRCS := branch-linux.cpp
OBJS := branch-linux.o
>>>>>>> ch8-linux

$(TARGET_EXEC): $(OBJS)
	$(CC) $^ -o $@
$(OBJS): $(SRCS)
	$(CC) -c $<
clean:
	rm $(OBJS) $(TARGET_EXEC) *~
