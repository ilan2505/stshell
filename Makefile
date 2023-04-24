CC = gcc
CFLAGS = -Wall -Werror
DFLAGS = -L. -Wl,-rpath,.

# .PHONY: all clean

all: decode encode codecA codecB cmp 

cmp: cmp.c
	$(CC) $(CFLAGS) cmp.c -o cmp

# copy: copy.c
# 	$(CC) $(CFLAGS) copy.c -o copy

encode: encode.c codecA codecB
	$(CC) $(CFLAGS) $(DFLAGS)  encode.c -ldl -o encode

decode: decode.c codecA codecB
	$(CC) $(CFLAGS) $(DFLAGS)  decode.c -ldl -o decode

codecA: codecA.c
	$(CC) $(CFLAGS) -shared -fPIC -o codecA codecA.c

codecB: codecB.c 
	$(CC) $(CFLAGS) -shared -fPIC -o codecB codecB.c

clean:
	rm -f *.o *.so decode encode codecA codecB cmp 

.PHONY: all clean
