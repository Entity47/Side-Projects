
CFLAGS = -Wall
CFLAGS += -lboost_system
CFLAGS += -std=c++11

CC = clang++

FILES = main.cpp server.cpp response/response.cpp response/responseService.cpp

build: $(FILES)
	$(CC) $(CFLAGS) $(FILES)
