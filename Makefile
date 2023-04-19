CC = gcc
CFLAGS = -Wall -Werror

all: decode codecA

decode: decode.c codecA
	$(CC) $(CFLAGS)  decode.c -ldl -o decode

codecA: codecA.c
	$(CC) $(CFLAGS) -shared -o libcodecA.so codecA.c

# decode: decode.o codecA.so codecB.so
# 	$(CC) $(CFLAGS) decode.o codecA.so codecB.so -o decode 

# encode: encode.o codecA.so codecB.so
# 	$(CC) $(CFLAGS) encode.o codecA.so codecB.so -o encode 


# codecA.so: codecA.o
# 	$(CC) -shared codecA.o -o codecA.so

# codecB.so: codecB.o
# 	$(CC) -shared codecB.o -o codecB.so

# codecA.o: codecA.c
# 	$(CC) $(FLAGS) -fPIC -c codecA.c -o codecA.o

# codecB.o: codecB.c 
# 	$(CC) $(FLAGS) -fPIC -c codecB.c -o codecB.o

# encode.o: encode.c
# 	$(CC) $(FLAGS) -c encode.c -ldl -o encode.o

# decode.o: decode.c
# 	$(CC) $(FLAGS) -c decode.c -ldl -o decode.o


clean:
	rm -f *.o *.so decode

.PHONY: clean
