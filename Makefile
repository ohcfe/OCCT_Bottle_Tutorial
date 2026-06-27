# Compiler configuration
CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -O2

# Arch Linux OCCT installation paths
INCLUDES := -I/usr/include/opencascade

# Required Open CASCADE Toolkit libraries
LIBS     := -lTKDESTEP -lTKXSBase  -lTKPrim  -lTKTopAlgo -lTKG3d -lTKMath -lTKBRep -lTKernel

# Build targets and files
TARGET   := occt_box_example
SRC      := main.cpp
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean run

# Default target to build the binary
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LIBS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Run the program directly
run: all
	./$(TARGET)

# Clean up build artifacts and generated STEP outputs
clean:
	rm -f $(OBJ) $(TARGET) minimal_box.stp
