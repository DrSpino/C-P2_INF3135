CC = gcc
CFLAGS = -W -Wall -ljansson
LDFLAGS = -ljansson
EXEC = bin/tp2
TEST = test/tp2_test
SRC = src/readJson.c src/command.c src/display.c src/tp2.c
OBJ = $(SRC:.c=.o)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

src/%o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

src/tp2.o: src/readJson.h src/command.h src/display.h

test: $(TEST)
	@./$(TEST)

$(TEST): test/tp2_test.c src/readJson.h src/command.h src/display.h
	@$(CC) -o $@ $< $(CFLAGS) -lcunit

clean:
	rm -rf src/*.o $(TEST) $(EXEC)