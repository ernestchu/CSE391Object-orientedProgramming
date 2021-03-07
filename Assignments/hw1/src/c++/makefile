CC = g++
T1 = main
T2 = main2
H1 = stack
all: clean dep $(T1).cpp $(T2).cpp
	$(CC) -c $(T1).cpp $(T2).cpp
	$(CC) $(T1).o $(H1).o -o $(T1)
	$(CC) $(T2).o $(H1).o -o $(T2)
	rm -f $(T1).o $(H1).o $(T2).o
clean:
	rm -f $(T1) $(T2) $(H1).o $(T1).o $(T2).o
dep: $(H1).cpp $(H1).h
	$(CC) -c $(H1).cpp
