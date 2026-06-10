SOURCES = \
	src/main.cpp \
	src/compress.cpp \
	src/decompress.cpp
TARGET = simple-compressor
CXX = clang++
CXXFLAGS = -O3

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@
