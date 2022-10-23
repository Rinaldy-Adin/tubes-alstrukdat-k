CC = gcc

DATADIR = ./data
DIR_OBJ = ./obj

TARGETS = ./main.c $(shell find . -name 'driver_*.c')
INCS = $(shell find . -name '*.h')
SRCS = $(filter-out $(TARGETS), $(shell find . -name '*.c'))
NODIR_SRC = $(notdir $(SRCS))
OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:c=o))

.PHONY: clean echoes

all: $(basename $(TARGETS))

$(basename $(TARGETS)): $(SRCS)
	$(CC) -o $@ $(SRCS) $(addsuffix .c, $@)

clean:
	rm -f $(basename $(TARGETS))
	rm -rf $(DIR_OBJ)/*

echoes:
	@echo "TARGET files: $(basename $(TARGETS))"  
	@echo "INC files: $(INCS)"  
	@echo "SRC files: $(SRCS)"
	@echo "OBJ files: $(OBJS)"