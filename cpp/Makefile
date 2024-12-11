SOURCE = $(wildcard *.cc)
EXECUTABLE = $(SOURCE:.cc=)
CXX = g++
CXXFLAGS = -std=c++2a -Wall -g

.PHONY: build clean
.DEFAULT_GOAL := build

build: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

%: %.go
	$(CXX) $(CXXFLAGS) -o $@ $^
