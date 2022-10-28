CC = gcc

ifdef OS
	TARGETS = $(patsubst "%", %,$(shell forfiles /s /m main.c /c "cmd /c echo @relpath")) $(patsubst "%", %,$(shell forfiles /s /m driver_*.c /c "cmd /c echo @relpath"))
	INCS = $(patsubst "%", %,$(shell forfiles /s /m *.h /c "cmd /c echo @relpath"))
	SRCS = $(filter-out $(TARGETS), $(patsubst "%", %,$(shell forfiles /s /m *.c /c "cmd /c echo @relpath")))
else
	ifeq ($(shell uname), Linux)
		TARGETS = ./main.c $(shell find . -name 'driver_*.c')
		INCS = $(shell find . -name '*.h')
		SRCS = $(filter-out $(TARGETS), $(shell find . -name '*.c'))
	endif
endif

.PHONY: clean echoes

all: $(basename $(TARGETS))

$(basename $(TARGETS)): $(SRCS)
	$(CC) -o $@ $(SRCS) $(addsuffix .c, $@)

echoes:
	@echo "TARGET files: $(basename $(TARGETS))"  
	@echo "INC files: $(INCS)"  
	@echo "SRC files: $(SRCS)"
	@echo "OBJ files: $(OBJS)"