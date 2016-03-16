CC = g++ -g
CFLAGS = -Wall

all: master_jack

jack_effect: jack_effect.o
	$(CC) -o $@ $(CFLAGS) jack_effect.o -ljack

jack_am: jack_am.o
	$(CC) -o $@ $(CFLAGS) jack_am.o jack_effect.o -ljack


master_jack: master_jack.o  jack_am_class.o jack_effect.o
	$(CC) -o $@ $(CFLAGS) master_jack.o jack_am_class.o jack_effect.o -ljack

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`
