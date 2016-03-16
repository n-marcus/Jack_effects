#include "jack_distortion.h"
#include <iostream>
#include <math.h>

using namespace std;

Distortion::Distortion()
{
  cout << "Youve made a Distortion object!" << endl;
  this->factor = 5;
}


//The jack process function
void Distortion::process(float *inputbuffer,float *outputbuffer,unsigned int nframes )
{
  //cout << "Distortion class processing samples" << endl;
  for(unsigned int x=0; x<nframes; x++)
  {
    /*
    if (inputbuffer[x] > 0.1) {
      outputbuffer[x] = 0.5;
    }else if (inputbuffer[x] < -0.1) {
      outputbuffer[x] = -0.5;
    }else {
      outputbuffer[x] =inputbuffer[x] ;
    }*/
    outputbuffer[x] =sin(tanh(inputbuffer[x]*factor)) /2;

  }//for loop
} // process()

void Distortion::test() {
  //cout << "Ik ben Distortion en ik werk!" << endl;;
  // /cout << "Samplerate van Distortion = " << samplerate << endl;;
}

void Distortion::setSamplerate(unsigned int samplerate) {
  cout << "Samplerate of Distortion set to " << samplerate << endl;
  this->samplerate = samplerate;
}

void Distortion::setFactor(float factor) {
  cout << "Setting factor to" << factor << endl;
  this->factor = factor;
}
