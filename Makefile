# Compiler and flags
CC = g++
CFLAGS = -std=c++20 -Wall -Werror -pedantic -g
LIB_SFML = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
LIB_BOOST = -lboost_unit_test_framework

# Header dependencies
DEPS = FibLFSR.hpp PhotoMagic.hpp

# Object files for the static library (no main here)
LIB_OBJECTS = FibLFSR.o PhotoMagic.o

# Object files for executables with main()
PHOTO_MAGIC_OBJ = main.o
TEST_OBJ = test.o

# Executables
PHOTO_MAGIC = PhotoMagic
TEST = test

.PHONY: all clean lint

# Default target builds everything
all: $(PHOTO_MAGIC) $(TEST) PhotoMagic.a

# Compile .cpp files to .o files
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Build static library from library objects only
PhotoMagic.a: $(LIB_OBJECTS)
	ar rcs $@ $^

# Build PhotoMagic executable
$(PHOTO_MAGIC): $(PHOTO_MAGIC_OBJ) PhotoMagic.a
	$(CC) $(CFLAGS) -o $@ $(PHOTO_MAGIC_OBJ) ./PhotoMagic.a $(LIB_SFML)

# Build test executable
$(TEST): $(TEST_OBJ) PhotoMagic.a
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJ) ./PhotoMagic.a $(LIB_BOOST)

clean:
	rm -f *.o $(PHOTO_MAGIC) $(TEST) PhotoMagic.a

lint:
	cpplint *.cpp *.hpp

