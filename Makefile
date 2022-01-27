CC = gcc
CFLAGS = -Wall -g 
TARGET = betulozturk
PWD = $(shell pwd)

SRCS = 	$(PWD)/betul.c\
		$(PWD)/sum/sum.c\
		$(PWD)/mult/mult.c\
		$(PWD)/print/print.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I/$(PWD)/mult/\
           -I/$(PWD)/sum/\
           -I/$(PWD)/print/


all: $(TARGET) 
	@echo  Simple compiler named betulozturk has been compiled
	
$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)
	
clean:
	$(RM) betulozturk *.o *~ $(OBJS)