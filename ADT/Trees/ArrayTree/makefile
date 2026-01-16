CC = clang
OUT = system
OBJS = main.o 

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUT)

%.o: %.c
	$(CC) -c $< -o $@

run: $(OUT)
	./$(OUT)

clean:
	rm -f *.o $(OUT)