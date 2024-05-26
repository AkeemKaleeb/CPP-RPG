CC := g++
CFLAGS := -std=c++20 -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion
TARGET := RPG
SRCDIR := src
SRCS := $(wildcard $(SRCDIR)/*.cpp)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean:
	find . -type f | xargs touch
	rm -rf $(TARGET)

.PHONY: all clean

# sudo date -s "$(wget -qSO- --max-redirect=0 google.com 2>&1 | grep Date: | cut -d' ' -f5-8)Z"
