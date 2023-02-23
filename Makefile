PROJECTNAME := maze

CXX := clang++
CXXOPTIMIZE := -02
CXXFLAGS := -g -Wall -std=c++20
LDFLAGS := -lncurses 

BUILDDIR := ./bin
SOURCEDIR := $(CURDIR)/src

SOURCEFILES  := main.cpp \
				game/game.cpp game/map.cpp \
				screen/screen.cpp \
				entities/player.cpp

SRC :=  $(foreach file, $(SOURCEFILES), $(addprefix $(SOURCEDIR)/, $(file)))

.PHONY: all build clean debug release info

all: build

build:
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(BUILDDIR)/$(PROJECTNAME)

debug: CXXFLAGS += -DDEBUG -g -fsanitize=address
debug: all

release: CXXFLAGS += $(CXXOPTIMIZE)
release: all

clean:
	-@rm -rvf $(BUILDDIR)
