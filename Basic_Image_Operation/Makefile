CC = g++
CXXFLAGS = -g  -Wall
EXEC1 = IO
CVLIB = `pkg-config opencv --cflags --libs`

all: $(EXEC1)

$(EXEC1): $(EXEC1).cpp
	$(CC) $(CXXFLAGS) $+ -o $@ $(CVLIB) 

.PHONY:clean
clean:
	rm -rf *.o $(EXEC1) *.jpg

