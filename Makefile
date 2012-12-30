TARGET = three

ROOT_DIR = .

SRC_DIR        = $(ROOT_DIR)
BUILD_DIR      = $(ROOT_DIR)/lib

$(TARGET):
	@cc include/three.h vector.c matrix.c tests.c internal.h

all: $(TARGET)

test:
	./a.out

clean:
	rm -rf $(BUILD_DIR)