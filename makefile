CC = gcc
CFLAGS = -W -Wall -ljansson
EXEC = bin/tp2
TEST = test/tp2_test
SRC = src/tp2.c src/readJson.h

$(EXEC): $(SRC)
	@$(CC) -o $@ $< $(CFLAGS)

test: $(TEST)
	@./$(TEST)

$(TEST): test/tp2_test.c src/readJson.h
	@$(CC) -o $@ $< $(CFLAGS) -lcunit

clean:
	rm -rf *.o $(TEST) $(EXEC)