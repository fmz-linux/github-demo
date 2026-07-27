CC = gcc

CFLAGS	= -Wall -wextra -I$(INC_DIR) -MMD
LDFLAGS =
RM		= rm -rf
MKDIR	= mkdir -p 

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

SRCS 	= $(shell find $(SRC_DIR) -name "*.c")
OBJS 	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS 	= $(OBJS:.o = .d)
TARGET 	= $(BIN_DIR)/main

-include $(DEPS)

all:$(TARGET)

$(TARGET):$(OBJS) | $(OBJ_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(BIN_DIR):
	$(MKDIR) $@

run:$(TARGET)
	./$(TARGET)

clean:
	$(RM) $(OBJS) $(DEPS) $(TARGET)

rebuild: clean all

.PHONY all run clear rebuild