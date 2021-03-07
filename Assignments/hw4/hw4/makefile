CPP = g++
F = -Wall -std=c++17
VPATH = lib/ #search directory
EXEC = scanner
OBJ = Lexer.o Num.o Real.o Tag.o Token.o Type.o Word.o
OBJDIR = obj/
EXECOBJ = $(addprefix $(OBJDIR), $(EXEC).o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))

.PHONY: all clean dep obj link

all: clean dep link

dep: obj $(OBJS)

obj:
	mkdir $(OBJDIR)

link: $(EXECOBJ)
	$(CPP) $(F) $(EXECOBJ) $(OBJS) -o $(EXEC)

$(EXECOBJ): $(EXEC).cpp
	$(CPP) $(F) -c $< -o $@

$(OBJDIR)%.o: %.cpp
	$(CPP) $(F) -c $< -o $@

clean:
	rm -rf obj $(EXEC)
