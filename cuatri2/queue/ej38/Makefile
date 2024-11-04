SRC_DIR = src
LIB_DIR= lib
BUILD_DIR = build

SRC = $(wildcard $(SRC_DIR)/*.c)
SRC += main.c

OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRC)))

CC = gcc
CFLAGS = -I./$(LIB_DIR)

TARGET = main

$(shell mkdir -p build)

all:$(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o:main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(BUILD_DIR)
