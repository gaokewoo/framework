include ../global.mk

SRCS = $(wildcard *.cpp)
BUILD = $(patsubst %.cpp, %.o, $(SRCS))

LIB_NAME=libsealcontainer.so

all: $(LIB_NAME)
OBJS=$(BUILD)

$(LIB_NAME):$(OBJS)
	$(CC) -shared -o $@ $(OBJS)
	@if [ ! -d ../lib/ ];then mkdir ../lib/;fi
	mv -f $@ ../lib/
	@echo "### $@ loaded ###\n"

.cpp.o:
	$(CC) $(CC_FLAGS) -c $<

install:

clean:
	rm -f *.o

