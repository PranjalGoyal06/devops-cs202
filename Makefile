CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = calculator
OBJECTS = main.o mathfuncs.o ranfuncs.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp mathfuncs.h randfuncs.h
mathfuncs.o: mathfuncs.cpp mathfuncs.h
ranfuncs.o: ranfuncs.cpp randfuncs.h

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)