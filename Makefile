CC = g++ -g
CFLAGS = -Wall



all: jack_effect jack_am master_jack 


jack_delay: jack_delay.o
	$(CC) -o $@ $(CFLAGS) jack_delay.o -ljack

jack_echo: jack_echo.o
	$(CC) -o $@ $(CFLAGS) jack_echo.o -ljack

jack_fuzz: jack_fuzz.o
	$(CC) -o $@ $(CFLAGS) jack_fuzz.o -ljack

jack_flanger: jack_flanger.o
	$(CC) -o $@ $(CFLAGS) jack_flanger.o -ljack

jack_am: jack_am.o
	$(CC) -o $@ $(CFLAGS) jack_am.o -ljack

master_jack: master_jack.o  jack_am_class.o
	$(CC) -o $@ $(CFLAGS) master_jack.o jack_am_class.o -ljack

jack_effect: jack_effect.o
	$(CC) -o $@ $(CFLAGS) jack_effect.o -ljack

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`
