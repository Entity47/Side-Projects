
CFLAGS = -Wall
CFLAGS += -lboost_system
CFLAGS += -std=c++11

CC = clang++

FILES = main.cpp server.cpp response/response.cpp response/metadata.cpp response/contentType.cpp response/statusCode.cpp

build: $(FILES)
	$(CC) $(CFLAGS) $(FILES)
