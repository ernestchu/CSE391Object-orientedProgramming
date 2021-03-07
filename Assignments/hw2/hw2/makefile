CC = g++
F = -Wall -std=c++17
T1 = mytar
H1 = tar
H2 = utils
all:  $(T1).cpp
	$(CC) $(F) -c $(T1).cpp
	$(CC) $(F) $(T1).o lib/bin/$(H1).o lib/bin/$(H2).o -o $(T1)
	rm -f $(T1).o
clean:
	rm -f $(T1) lib/bin/$(H1).o lib/bin/$(H2).o
dep:
	$(CC) $(F) -c lib/$(H1).cpp -o lib/bin/$(H1).o
	$(CC) $(F) -c lib/$(H2).cpp -o lib/bin/$(H2).o
