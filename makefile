# Compiler
COMPILER = -g++
VERSION = -std=c++2a
CC = $(COMPILER) $(VERSION)

# Compiler Flags
# -Wall: Enable all flags
# -fPIC: Force Positional Independant Code
CF = -Wall -fPIC

# Libraries Path
LIBRARIES = lib/lib*

# Source Path
SOURCE = src/main.cpp

# Build Path
BUILD = build

# Build Target
TARGET = MatrixTester

$(TARGET) : MATRIX
	mkdir -p $(BUILD)
	$(CC) $(CF) $(SOURCE) $(LIBRARIES) -o $(BUILD)/$(TARGET)

MATRIX:
	$(CC) $(CF) -c src/matrix.cpp -o lib/libmatrix.so