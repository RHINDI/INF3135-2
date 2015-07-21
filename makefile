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
OBJS = main.o fileManager.o linkedList.o statistics.o
file = 3.txt

.SUFFIXES: .c .o

all: clean start

compile: $(OBJS)

.c.o:
	$(CC) $(OPTIONS) -c $*.c

link: compile
	$(CC) $(OBJS) -o $(EXE)

clean:
	rm $(EXE)
	rm $(OBJS)

start: link
	./$(EXE) $(file)




