#!/bin/bash
SFML_DL_LINK="https://www.sfml-dev.org/files/SFML-2.5.1-linux-gcc-64-bit.tar.gz"
SFML_FILE_DL="SFML-2.5.1.tar.gz"

# Download SFML
if [ ! -d "SFML-2.5.1" ] ; then
	echo "# Downloading SFML from $SFML_DL_LINK"
	wget "$SFML_DL_LINK" -O "$SFML_FILE_DL"
	tar zxvf "$SFML_FILE_DL"
	rm "$SFML_FILE_DL"
fi

if [ ! -d "build" ] || [ ! -f "build/game" ] ; then
	if [ ! -f "Makefile" ] ; then
		echo -e "\n\n\n# Creating Makefile"
		cmake -G"Unix Makefiles"
	fi
fi

echo -e "\n\n\n# Compiling"
make
echo -e "\n\n\n# Running"
./build/Debug/game
