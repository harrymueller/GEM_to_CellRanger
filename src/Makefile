# MAKEFILE TO BUILD DUPLICATES PROJECT
PROJECT	= GEMtoCellRanger
HEADERS	= main.h general.h process.h

OBJ		= main.o barcodes.o counts.o discovery.o genes.o process.o

CC		= cc
CFLAGS	= -Wall -Werror
#LIBS	= -lstdc++

# MAIN
$(PROJECT) : $(OBJ)
	$(CC) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm $(LIBS)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(LIBS) $<

clean:
	rm -f $(OBJ)