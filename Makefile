CC = gcc
CFLAGS = -Iinclude -Wall -g

SRC = src/main.c src/memory_tracker.c src/logger.c src/shadow_memory.c src/security_checks.c src/visualization.c
OBJ = $(SRC:.c=.o)

BIN = mem_leak_detector

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)

run: all
	./$(BIN)
