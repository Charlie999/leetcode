SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

all: clean $(PROGS)

.PHONY: clean
clean:
	rm -f $(PROGS)

%: %.c
	$(CC) $(CFLAGS)  -o $@ $<
