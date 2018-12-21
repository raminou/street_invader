CC=g++
CFLAGS=-Wall -g -std=c++11
CCDIRECTORY=src
EXEC=game
OBJ=entity.o character.o player.o enemy.o shot.o game.o window.o main.o

all: game

game: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(EXEC)

%.o: %.cc
	$(CC) $(CFLAGS) $^ -o $@ -c

clean:
	@rm -f *.o
	@rm -f $(EXEC)

re: clean all
