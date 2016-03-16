#ifndef _Distortion_H_
#define _Distortion_H_
#include <iostream>
using namespace std;
#include <math.h>
#include "jack_effect.h"

class Distortion : public Effect
{
public:
  Distortion(); // constructor for derived class
  void process(float *inputbuffer,float *outputbuffer, unsigned int nframes);
  void test();
  void setSamplerate(unsigned int samplerate);
  void setFactor(float factor);
private:
  double mod_depth, mod_freq,mod_phase;
  unsigned int samplerate;
  float factor;
};


#endif // Distortion_H
