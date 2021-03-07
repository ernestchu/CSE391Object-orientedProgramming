CC = g++
F = -Wall -std=c++17
T1 = mytar
H1 = tar
H2 = utils
all: clean dep $(T1).cpp
	$(CC) $(F) -c $(T1).cpp
	$(CC) $(F) $(T1).o obj/$(H1).o obj/$(H2).o -o $(T1)
	rm -f $(T1).o
clean:
	rm -rf $(T1) obj
dep: dir lib/$(H1).h lib/$(H1).cpp lib/$(H2).h lib/$(H2).cpp  
	$(CC) $(F) -c lib/$(H1).cpp -o obj/$(H1).o
	$(CC) $(F) -c lib/$(H2).cpp -o obj/$(H2).o
dir:
	mkdir obj
