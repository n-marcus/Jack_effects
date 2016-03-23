CC = g++ -g
CFLAGS = -Wall
##LIBB= /home/nathan/Downloads/liblo-0.28
#CFLAGS += -I$(LIBINCLUDE)
LDFLAGS= -L/usr/local/lib -llo -lpthread
OBJ= master_jack.o jack_am_class.o jack_distortion.o jack_effect.o -ljack osc.o

all: master_jack

jack_effect: jack_effect.o
	$(CC) -o $@ $(CFLAGS) jack_effect.o -ljack

jack_am: jack_am.o
	$(CC) -o $@ $(CFLAGS) jack_am.o jack_effect.o -ljack


jack_distortion: jack_distortion.o
	$(CC) -o $@ $(CFLAGS) jack_distortion.o jack_effect.o -ljack

master_jack: master_jack.o jack_distortion.o jack_am_class.o jack_effect.o osc.o
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`
