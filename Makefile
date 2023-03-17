SRC_DIR := $(PROJECT_PATH)/src
BUILD_DIR := $(PROJECT_PATH)/build

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

CC := cc
CFLAGS := -Wall -Werror -Wextra
POSTCFLAGS := -lm

TARGET := $(BUILD_DIR)/main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(POSTCFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(POSTCFLAGS)

$(BUILD_DIR): ; mkdir -p $(BUILD_DIR)

clean: ; rm -r $(BUILD_DIR)

.PHONY: all clean
