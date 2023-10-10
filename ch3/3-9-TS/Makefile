CC := g++ -std=c++2a -Wall
TARGET_EXEC := out
CFLAGS  := -Wall
SRCS := type-safety.cpp
OBJS := type-safety.o

$(TARGET_EXEC): $(OBJS)
	$(CC) $^ -o $@
$(OBJS): $(SRCS)
	$(CC) -c $<
clean:
	rm $(OBJS) $(TARGET_EXEC) *~
run:
	@./$(TARGET_EXEC)
