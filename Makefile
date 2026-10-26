OBJ = $(patsubst %.c,%.o,$(wildcard *.c))

inverted_search: $(OBJ)
	gcc -o $@ $^

clean:
	rm -f *.o inverted_search