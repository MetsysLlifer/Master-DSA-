CC = clang
TARGET = merge
OBJS = main.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# This pattern handles compiling the .c files into .o files
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

# automatically run the system after compiling
run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)