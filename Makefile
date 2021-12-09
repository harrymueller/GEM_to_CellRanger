# MAKEFILE TO BUILD DUPLICATES PROJECT
PROJECT	= GEMtoSlideSeq
HEADERS	= main.h discovery.h

OBJ		= main.o discovery.o barcodes.o

CC		= cc
CFLAGS	= -Wall -Werror
#LIBS	= -lstdc++

# MAIN
$(PROJECT) : $(OBJ)
	$(CC) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm $(LIBS)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(LIBS) $<

clean:
	rm -f $(PROJECT) $(OBJ)