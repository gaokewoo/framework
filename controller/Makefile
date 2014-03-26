include ../global.mk

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %, $(SRCS))

.cc:
	$(CC) $(CC_FLAGS) -o $@ $< $(CC_INCLDIR) $(LIBS)
	@if [ ! -d ../bin/ ];then mkdir ../bin/;fi
	cp $@ ../bin/
	@echo


all: $(BUILD)

install:

clean:
	rm -f $(BUILD)
