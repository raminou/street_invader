CC=g++
CFLAGS=-Wall -g -std=c++11 -Iheaders/
LDFLAGS=-L ./SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
INCLUDES=-I ./SFML-2.5.1/include

CC_DIRECTORY=src
BUILD_DIRECTORY=build
OBJ_DIRECTORY=$(BUILD_DIRECTORY)/obj
EXEC=$(BUILD_DIRECTORY)/game

NAME_OBJ=entity.o character.o player.o enemy.o shot.o game.o window.o main.o
OBJ=$(patsubst %,$(OBJ_DIRECTORY)/%,$(NAME_OBJ))

all: create_dir game

game: $(OBJ)
	$(CC) $(CFLAGS)  $^ -o $(EXEC) $(LDFLAGS)

$(OBJ_DIRECTORY)/%.o: $(CC_DIRECTORY)/%.cc
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@ -c

clean:
	@rm -f $(OBJ_DIRECTORY)/*.o
	@rm -f $(EXEC)
	@rmdir $(OBJ_DIRECTORY)
	@rmdir $(BUILD_DIRECTORY)

create_dir:
	@mkdir -p $(BUILD_DIRECTORY)
	@mkdir -p $(OBJ_DIRECTORY)
	@mkdir -p $(EXEC)

re: clean all
