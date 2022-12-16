#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED
#include "ouvrage.h"

class Video: public Ouvrage{
  private:
    string editeur;
    float duree;
  public:
    Video();
    Video(string, string, bool, string, float);
    ~Video() {};
    void afficher();
};

#endif // VIDEO_H_INCLUDED
