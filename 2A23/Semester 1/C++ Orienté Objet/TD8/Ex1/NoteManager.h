#ifndef NOTEMANAGER_H_INCLUDED
#define NOTEMANAGER_H_INCLUDED
#include <vector>
#include <typeinfo>
#include <fstream>
#include "note.h"
#include "tag.h"

class NoteManager{
  private:
    vector<Note*> V;
  public:
    NoteManager(){};
    ~NoteManager();
    NoteManager(const NoteManager&);
    NoteManager& operator=(const NoteManager&);
    vector<Note*>::iterator rechercher(int);
    void ajouter(const Note&);
    void ajouter(const Tag&);
    void afficher(string);
    void enregistrer(string);
    void charger(string);
};

#endif // NOTEMANAGER_H_INCLUDED
