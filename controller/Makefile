include ../global.mk

SRCS = $(wildcard *.cpp)
BUILD = $(patsubst %.cpp, %, $(SRCS))

.cpp:
	$(CC) $(CC_FLAGS) -rdynamic -o $@ $< $(CC_INCLDIR) $(LIBS)
	@if [ ! -d ../bin/ ];then mkdir ../bin/;fi
	cp $@ ../bin/
	@echo


all: $(BUILD)

install:

clean:
	rm -f $(BUILD)
