SRC_DIR=.
BUILD_DIR=build

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

CFLAGS=-Wall -Wextra
CC=gcc

all: chess

chess: $(OBJS)
	@$(CC) $(CFLAGS) chess.c myconstants.c pawn.c knight.c king.c bishop.c rook.c helpers.c \
 	random.c -o chess
	./chess.exe

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o chess.exe
	rm -rf *.o