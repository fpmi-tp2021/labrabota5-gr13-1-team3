# Create by Roman Doskoch.
CC=gcc
CFLAGS=-c -o
OBJECTS=obj/main.o obj/MusicManager.o

bin/MusicSalon: $(OBJECTS)
	$(CC) -o bin/MusicSalon $(OBJECTS)

obj/main.o: src/main.c
	$(CC) $(CFLAGS) obj/main.o src/main.c

obj/MusicManager.o: src/MusicManager.c
	$(CC) $(CFLAGS) obj/MusicManager.o src/MusicManager.c

clean:
	rm -rf obj/*.o bin/MusicSalon