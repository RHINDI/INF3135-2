#==============================================================
#                    MAKEFILE pour le Tp2...
#
#  @author : Rhindi Youssef
#  @CodePermanent : RHIY20087605
#
#
#==============================================================

# variables
CC = gcc
OPTIONS = -Wall
EXE = Tri
OBJS = Tri.o
file = list.txt

.SUFFIXES: .c .o

all: clean start

compile: $(OBJS)

.c.o:
	$(CC) $(OPTIONS) -c $*.c

link: compile
	$(CC) $(OBJS) -o $(EXE)


#cible : nettoyage

clean:
	rm $(EXE)
	rm $(OBJS)

start: link
	./$(EXE) $(file)





