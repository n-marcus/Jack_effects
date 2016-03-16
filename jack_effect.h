#ifndef _EFFECT_H_
#define _EFFECT_H_
#include <iostream>

class Effect
{
public:
  Effect(); // constructor for derived class
  void process(float *inputbuffer,float *outputbuffer, unsigned int nframes);
  void setSamplerate(unsigned int samplerate);
  void test();
protected:
  unsigned int samplerate;
};


#endif // _EFFECT_H_
