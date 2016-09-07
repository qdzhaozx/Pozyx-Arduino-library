
CROSS_COMPILE = arm-v7a-linux-gnueabihf-
CC=$(CROSS_COMPILE)g++
CFLAGS += -g -O0 -Wall -fno-omit-frame-pointer
CFLAGS += -Wfloat-equal -Wundef -Waggregate-return 
CFLAGS += -D_REENTRANT -fpic
LDFLAGS += -lm #-rdynamic

EXEC = Pozyx
OBJS = Pozyx_core.o Pozyx_lib.o serial.o ready_to_localize.o wire.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

$(OBJS): %.o: %.cpp
	$(CC)  $(CFLAGS) -c $< -o $@

clean:
	-rm -f *.o *.elf *.gdb *.o $(EXEC)

