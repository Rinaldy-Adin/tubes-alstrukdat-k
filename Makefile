TARGET = main

CC = gcc

DATADIR = ./data
# SUBDIR = semihost stream arg_parser
DIR_OBJ = ./obj

INCS = $(shell find . -name '*.h')
SRCS = $(shell find . -name '*.c')
NODIR_SRC = $(notdir $(SRCS))
OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:c=o))

.PHONY: clean echoes

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

$(DIR_OBJ)/%.o: %.c $(INCS)
	mkdir -p $(@D)
	$(CC) -o $@ -c $<

clean:
	rm $(TARGET)
	rm -rf $(DIR_OBJ)/*

echoes:
	@echo "INC files: $(INCS)"  
	@echo "SRC files: $(SRCS)"
	@echo "OBJ files: $(OBJS)"