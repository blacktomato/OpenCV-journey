CC = g++
CXXFLAGS = -g  -Wall
EXEC1 = Mat
EXEC2 = basic_structure
OBJS1 = Mat.cpp
OBJS2 = basic_structure.cpp
CVLIB = `pkg-config opencv --cflags --libs`

all: $(EXEC1) $(EXEC2)

$(EXEC1): $(OBJS1)
	$(CC) $(CXXFLAGS) $+ -o $@ $(CVLIB) 

$(EXEC2): $(OBJS2)
	$(CC) $(CXXFLAGS) $+ -o $@ $(CVLIB) 

.PHONY:clean
clean:
	@rm -rf *.o $(EXEC1) $(EXEC2)

 

