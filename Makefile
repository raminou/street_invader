CC=g++
CFLAGS=-Wall -g -std=c++11
LDFLAGS=-L ./SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
INCLUDES=-I ./SFML-2.5.1/include
CCDIRECTORY=src
EXEC=game
OBJ=entity.o character.o player.o enemy.o shot.o game.o window.o main.o

all: game

game: $(OBJ)
	$(CC) $(CFLAGS)  $^ -o $(EXEC) $(LDFLAGS)

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@ -c

clean:
	@rm -f *.o
	@rm -f $(EXEC)

re: clean all
