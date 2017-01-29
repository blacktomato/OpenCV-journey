CC = g++
CXXFLAGS = -g  -Wall
EXEC1 = Mat
EXEC2 = basic_structure
EXEC3 = IO
CVLIB = `pkg-config opencv --cflags --libs`

all: $(EXEC1) $(EXEC2) $(EXEC3)

$(EXEC1): $(EXEC1).cpp
	$(CC) $(CXXFLAGS) $+ -o $@ $(CVLIB) 

$(EXEC2): $(EXEC2).cpp
	$(CC) $(CXXFLAGS) $+ -o $@ $(CVLIB) 
	 
$(EXEC3): $(EXEC3).cpp
	$(CC) $(CXXFLAGS) $+ -o $@ $(CVLIB) 

.PHONY:clean
clean:
	rm -rf *.o $(EXEC1) $(EXEC2) $(EXEC3)

 

