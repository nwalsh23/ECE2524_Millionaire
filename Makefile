CXX 		:= g++
CXX_FLAGS 	:= -Wall -g -std=c++0x
#LIBS		:= -lboost_program_options
SRCS		:= main.cpp question_Input.cpp
OBJS 		:= $(SRCS:.cpp=.o)

all: main

main: main.o question_Input.o
	${CXX} $(CXX_FLAGS) -o $@ main.o question_Input.o

include ../make_depend.mk

-include $(SRCS:.cpp=.d)

clean:
	-rm *.o *.d *~
