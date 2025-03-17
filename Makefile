CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17

TARGET = egzek

SRCS = main.cpp dynamic_array.cpp list.cpp

HEADERS = dynamic_array.hh list.hh

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)