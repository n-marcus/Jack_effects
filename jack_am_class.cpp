#include "jack_am_class.h"
#include <iostream>
#include <math.h>

using namespace std;

AM::AM()
{
  mod_depth=0.5;
  mod_freq=20.0;
  mod_phase=0;
  cout << "Youve made a AM object!" << endl;
  cout << "What frequency do you want this AM object to modulate with?" << endl;
  cin >> mod_freq;
  cout << "What depth do you want this AM object to have?" << endl;
  cin >> mod_depth;
}

void AM::set_modulation_depth(float mod_depth)
{
  this->mod_depth=mod_depth;
}

//The jack process function
void AM::process(float *inputbuffer,float *outputbuffer,unsigned int nframes )
{
  cout << "AM class processing samples" << endl;
  for(unsigned int x=0; x<nframes; x++)
  {
    outputbuffer[x] = inputbuffer[x] * (sin(mod_phase) * mod_depth);
    mod_phase+=mod_freq*2*M_PI/samplerate;
  }
} // process()

void AM::test() {
  cout << "Ik ben AM en ik werk!" << endl;;
}

void AM::setSamplerate(unsigned int samplerate) {
  cout << "Samplerate of AM set to " << samplerate << endl;
  this->samplerate = samplerate;
}
