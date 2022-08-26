CC=clang
CFLAGS=-Wall -Wextra -std=c11 -pedantic --target=wasm32 -nostdlib

main.wasm: main.o
	$(CC) $(CFLAGS) -Wl,--export-all,--no-entry,--allow-undefined -o main.wasm main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
