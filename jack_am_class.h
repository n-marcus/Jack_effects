#ifndef _AM_H_
#define _AM_H_
#include <iostream>
using namespace std;
#include <math.h>


class AM
{
public:
  AM(); // constructor for derived class
  void set_modulation_depth(float mod_depth);
  void process(float *inputbuffer,float *outputbuffer, unsigned int nframes);
  void test();
  void setSamplerate(unsigned int samplerate);
private:
  double mod_depth, mod_freq,mod_phase;
  unsigned int samplerate;
  //int FRAMESPERBUFFER;
};


#endif // _AM_H