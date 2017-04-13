CC = gcc
CFLAGS = -W -Wall -ljansson
EXEC = src/tp2
TEST = test/tp2_test
OBJ = src/tp2.c src/

all: $(EXEC) #$(TEST)
	@./$(EXEC) 

$(EXEC): $(OBJ) src/readJson.c
	@$(CC) -o $@ $< $(CFLAGS)

test: $(TEST)
	@./$(TEST)

$(TEST): test/tp2_test.c src/readJson.c
	@$(CC) -o $@ $< -lcunit -ljansson

clean:
	rm -rf *.o $(TEST) $(EXEC)