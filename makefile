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


.SUFFIXES: .c .o

all:  link

compile: $(OBJS)

.c.o:
	$(CC) $(OPTIONS) -c $*.c

link: compile
	$(CC) $(OBJS) -o $(EXE)

clean:
	rm $(EXE)
	rm $(OBJS)






