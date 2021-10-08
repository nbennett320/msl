CXX = g++
AR = ar
CXXFLAGS = -std=c++17 -m32 -fno-pie -fno-stack-protector -fno-exceptions -fno-rtti -ffreestanding -nostdlib -O2 -Wall -Wextra $(INCLUDE)
INCLUDE = -I ./include -I ../../include -I ../libc
LIB = msl.a
# VPATH = src/

CPP = \
	src/Array_Base.cpp\
	src/Array.cpp\
	src/Fixed_Array.cpp\
	src/List_Base.cpp\
	src/Node.cpp\
	src/Queue.cpp\
	src/Stack.cpp\
	src/String.cpp\
	src/Matrix.cpp\
	src/msl.cpp\

OBJ = $(CPP:.cpp=.o)

all: $(LIB)

$(LIB): $(OBJ)
	$(AR) rcs $(LIB) $(OBJ)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

# bin/%.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# %.o: %.s
# 	$(AS) -f elf32 $< -o $@

# lib:
# 	$(MAKE) $(OBJ)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# .PHONY: test
# test:
# 	$(MAKE) -C test

.PHONY: clean
clean:
	rm *.o $(LIB)
