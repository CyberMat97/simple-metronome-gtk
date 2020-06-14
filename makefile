# change application name here (executable output name)
TARGET=simple-metronome-gtk

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN= -Wall -pedantic

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

SDLLIB= -lSDL -lSDL_mixer

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) $(SDLLIB) -export-dynamic

OBJS=	main.o audio.o gtk_functions.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)

main.o: src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) $(SDLLIB) -o main.o

audio.o: src/audio.c
	$(CC) -c $(CCFLAGS) src/audio.c $(SDLLIB) -o audio.o

gtk_functions.o: src/gtk_functions.c
	$(CC) -c $(CCFLAGS) src/gtk_functions.c $(GTKLIB) -o gtk_functions.o

clean:
	rm -f *.o $(TARGET)
