include ../global.mk

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %, $(SRCS))

.cc:
	$(CC) $(CC_FLAGS) -o $@ $< -ldl
	@if [ ! -d ../bin/ ];then mkdir ../bin/;fi
	cp $@ ../bin/
	@echo


all: $(BUILD)

install:

clean:
	rm -f $(BUILD)
