CC=g++
CFLAGS=-Wall -g -std=c++11 -Iheaders/
LDFLAGS=-L ./SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
INCLUDES=-I ./SFML-2.5.1/include

SFML_DL_LINK=https://www.sfml-dev.org/files/SFML-2.5.1-linux-gcc-64-bit.tar.gz
SFML_FILE_DL=SFML-2.5.1.tar.gz
SFML_DIR=SFML-2.5.1
CC_DIRECTORY=src
BUILD_DIRECTORY=build
OBJ_DIRECTORY=$(BUILD_DIRECTORY)/obj
EXEC_DIRECTORY=$(BUILD_DIRECTORY)
EXEC_NAME=game

EXEC=$(BUILD_DIRECTORY)/$(EXEC_NAME)

NAME_OBJ=entity.o character.o player.o enemy.o shot.o game.o window.o main.o button.o
OBJ=$(patsubst %,$(OBJ_DIRECTORY)/%,$(NAME_OBJ))

all: download_sfml create_dir game

download_sfml: 
	@if [ ! -d $(SFML_DIR) ] ; then\
		echo -e "\n# Downloading SFML";\
		wget -O $(SFML_FILE_DL) $(SFML_DL_LINK);\
		echo -e "\n# Extracting SFML";\
		tar zxvf "$(SFML_FILE_DL)";\
		rm "$(SFML_FILE_DL)";\
	fi

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
	@mkdir -p $(EXEC_DIRECTORY)

re: clean all
