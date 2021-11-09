SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))
CFLAGS = -lm

all: clean $(PROGS)

.PHONY: clean
clean:
	rm -f $(PROGS)

%: %.c
	$(CC) -o $@ $< $(CFLAGS)
