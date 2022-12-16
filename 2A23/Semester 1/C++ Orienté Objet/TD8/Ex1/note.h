#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED
#include <iostream>
using namespace std;
#include <string>

class Note{
  protected:
    int id;
    string obj;
    string desc;
    string date_prise;
  public:
    Note();
    Note(int, string, string, string);
    virtual ~Note(){};
    int getID() const{return id;};
    string getOBJ() const {return obj;};
    string getDesc() const {return desc;};
    virtual void afficher();
};

#endif // NOTE_H_INCLUDED
