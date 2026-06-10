SOURCES = \
	src/main.cpp \
	src/common.cpp \
	src/compress.cpp \
	src/decompress.cpp
HEADERS = \
	src/common.h \
	src/compress.h \
	src/decompress.h
TARGET = sc
CXX = clang++
CXXFLAGS = -O3
LINT = cpplint
LINTFLAGS = --root

.PHONY: lint build clear

all: build

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

lint: $(SOURCES) $(HEADERS)
	$(LINT) $(LINTFLAGS) $^

build: $(TARGET)

clear:
	rm -f $(TARGET)
