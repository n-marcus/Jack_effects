#include "jack_effect.h"


Effect::Effect()
{
  cout << "You made an effect class!" << endl; 
} // Effect()

void Effect::process_samples(float *inputbuffer,float *outputbuffer,unsigned int nframes )
{
  for(unsigned int i=0; i<nframes; i++) outputbuffer[i]=inputbuffer[i];
}

void Effect::setSamplerate(unsigned int samplerate) {
  this->samplerate = samplerate;
}
