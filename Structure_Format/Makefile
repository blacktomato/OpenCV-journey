CC = g++
CXXFLAGS = -g  -Wall
EXEC = Mat
OBJS = Mat.cpp
CVLIB = `pkg-config opencv --cflags --libs`

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CXXFLAGS) $+ -o $@ $(CVLIB) 

.PHONY:clean
clean:
	@rm -rf *.o $(EXEC)

 

