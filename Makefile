CC = cc
SRC = src
CFLAGS := -Wall -Werror -Wno-unused-variable -Wno-unused-function -MMD
INC := -I include  
EXE := Test
BIND := bin
BUILD := build

srcs = $(shell find src/ -type f)
objs := $(patsubst src/%, $(BUILD)/%, $(srcs:.c=.o))

all: setup bin/$(EXE)
setup: $(BIND) $(BUILD)
$(BIND):
	mkdir -p $(BIND)
$(BUILD):
	mkdir -p $(BUILD)

bin/$(EXE): $(objs)
	$(CC) $^ -o $@

build/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
.PHONY: clean 
clean: 
	rm -rf bin build