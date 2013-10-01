CC := gcc
COPTS := -Wall
CFLAGS := -I/usr/local/include -I/usr/local/include/stb
LDFLAGS := -L/usr/local/lib -lSOIL

# OpenGL Framework on OSX or a normal library on *nix
UNAME := $(shell uname -s)
ifeq ($(UNAME),Darwin)
    LDFLAGS += -F/System/Library/Frameworks -F/Library/Frameworks -framework OpenGL -framework CoreFoundation
else
    CXXFLAGS += $(shell pkg-config --cflags gl)
    LDFLAGS += $(shell pkg-config --libs gl)
endif

all:
	$(CC) $(COPTS) $(CFLAGS) $(LDFLAGS) main.c -o soil

clean:
	rm -rf ./soil
	rm -rf ./*.o
