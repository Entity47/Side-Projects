
CFLAGS = -Wall
CFLAGS += -lboost_system
CFLAGS += -std=c++11

CC = clang++

FILES = *.cpp settings/*.cpp http/*.cpp http/response/*.cpp http/request/*.cpp

build: $(FILES)
	$(CC) $(CFLAGS) $(FILES)
