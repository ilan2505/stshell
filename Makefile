CC = gcc
CFLAGS = -Wall -Werror
DFLAGS = -L. -Wl,-rpath,.


all: decode encode codecA codecB cmp copy

cmp: cmp.c
	$(CC) $(CFLAGS) cmp.c -o cmp

copy: copy.c
	$(CC) $(CFLAGS) copy.c -o copy

encode: encode.c codecA codecB
	$(CC) $(CFLAGS) $(DFLAGS)  encode.c -ldl -o encode

decode: decode.c codecA codecB
	$(CC) $(CFLAGS) $(DFLAGS)  decode.c -ldl -o decode

codecA: codecA.c codec.h
	$(CC) $(CFLAGS) -shared -fPIC -o codecA codecA.c

codecB: codecB.c codec.h
	$(CC) $(CFLAGS) -shared -fPIC -o codecB codecB.c

clean:
	rm -f *.o *.so decode encode codecA codecB cmp copy

.PHONY: all clean
