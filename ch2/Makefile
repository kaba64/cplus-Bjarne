CC := g++ -std=c++2a -Wall
TARGET_EXEC := out
CFLAGS  := -Wall
SRCS := hello_world.cpp
OBJS := hello_world.o

$(TARGET_EXEC): $(OBJS)
	$(CC) $^ -o $@
%.o: %.cpp
        $(CC) -c $< -o $@
clean:
	rm $(OBJS) $(TARGET_EXEC) *~
