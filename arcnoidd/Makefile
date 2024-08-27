CXX = g++
CC = $(CXX)

# CXXFLAGS = -Wall -Werror -Wconversion -g -Wextra
CXXFLAGS+= -std=c++17
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsqlite3

SRCS := $(wildcard game_arkenoid/*.cpp)
TARGETS := $(notdir $(SRCS:.cpp=))

check: main
	./main

main: main.o Ball.o Block.o BlocksField.o Game.o GlobalObjects.o Paddle.o screen.o score.o
	$(CXX) $(CXXFLAGS) -o main main.o Ball.o Block.o BlocksField.o Game.o GlobalObjects.o Paddle.o screen.o score.o $(LIBS)

all: $(TARGETS)
$(TARGETS): $(STUFF)

clean:
	@echo "cleaning up"
	$(RM)  *.o main
