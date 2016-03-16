#include "jack_effect.h"

Effect::Effect()
{
  std::cout << "You made an effect class!" << std::endl;
} // Effect()

void Effect::process(float *inputbuffer,float *outputbuffer,unsigned int nframes )
{
  for(unsigned int i=0; i<nframes; i++) outputbuffer[i]=inputbuffer[i];
}

void Effect::setSamplerate(unsigned int samplerate) {
  this->samplerate = samplerate;
}
void Effect::test() {
  std::cout << "Ik ben een Effect en ik werk!" << std::endl;
}
