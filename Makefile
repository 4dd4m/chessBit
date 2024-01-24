# this makefile is bad, not in use
SRC_DIR := .
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

CFLAGS := -Wall -Wextra

all: chess

chess: $(OBJS)
	@gcc $(CFLAGS) chess.c myconstants.c pawn.c knight.c king.c bishop.c rook.c -o chess

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o chess.exe