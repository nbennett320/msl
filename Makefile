CXX = g++
CXXFLAGS = -std=c++17 -m32 -fno-pie -fno-stack-protector -fno-exceptions -fno-rtti -ffreestanding -nostdlib -O2 -Wall -Wextra $(INCLUDE)
LDFLAGS =
INCLUDE = -I include
VPATH = src/

CPP = \
	Array_Base.cpp\
	Array.cpp\
	Fixed_Array.cpp\
	List_Base.cpp\
	Node.cpp\
	Queue.cpp\
	Stack.cpp\
	String.cpp\

OBJ = $(addprefix bin/, $(CPP:.cpp=.o))

all: lib test

bin/%.o: %.cpp
	echo "prefix bin"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# %.o: %.s
# 	$(AS) -f elf32 $< -o $@

lib:
	echo "in lib"
	$(MAKE) $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: test
test:
	echo "in test"
	$(MAKE) -C test

.PHONY: clean
clean:
	rm -rf *.o *.bin *.iso
	rm -rf iso
	$(MAKE) -C lib clean
	$(MAKE) -C test clean
