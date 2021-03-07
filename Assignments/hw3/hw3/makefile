CC = g++
F = -Wall -std=c++17
T1 = main
H1 = Complex
all:  $(T1).cpp
	$(CC) $(F) -c $(T1).cpp
	$(CC) $(F) $(T1).o $(H1).o -o $(T1)
	rm -f $(T1).o $(H1).o
clean:
	rm -f $(T1)
dep:
	$(CC) $(F) -c $(H1).cpp -o $(H1).o
