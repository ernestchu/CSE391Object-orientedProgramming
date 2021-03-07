CPP = g++
F = -Wall -std=c++17
VPATH = lib/ #search directory
EXEC = test
OBJ = Vector.o Trace.o
OBJDIR = obj/
EXECOBJ = $(addprefix $(OBJDIR), $(EXEC).o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))

.PHONY: all clean dep dir link

all: clean dep link

dep: dir $(OBJS)

dir:
	mkdir $(OBJDIR)

link: $(EXECOBJ)
	$(CPP) $(F) $(EXECOBJ) $(OBJS) -o $(EXEC)

$(EXECOBJ): $(EXEC).cpp
	$(CPP) $(F) -c $< -o $@

$(OBJDIR)%.o: %.cpp
	$(CPP) $(F) -c $< -o $@

clean:
	rm -rf ./obj $(EXEC)
