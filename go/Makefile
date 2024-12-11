SOURCE = $(wildcard *.go)
EXECUTABLE = $(SOURCE:.go=)

.PHONY: build clean
.DEFAULT_GOAL := build

build: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

%: %.go
	go build -o $@ $^
