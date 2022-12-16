#include "NoteManager.h"

NoteManager::NoteManager(const NoteManager &x)
{
    Note * n;
    vector<Note*>::const_iterator it;
    for(it=x.V.begin(); it!=x.V.end(); it++){
        if(typeid(Note) == typeid(**it)){
            n = new Note(**it);
        }else{
            n = new Tag(static_cast<const Tag&>(**it));
        }
        V.push_back(n);
    }
}

NoteManager::~NoteManager()
{
    for(vector<Note*>::iterator it=V.begin(); it!=V.end(); it++){
        delete(*it);
    }
}

NoteManager& NoteManager::operator=(const NoteManager &x)
{
    vector<Note*>::const_iterator it;
    for(it=V.begin(); it!=V.end(); it++){
        delete(*it);
    }
    Note * n;
    for(it=x.V.begin(); it!=x.V.end(); it++){
        if(typeid(Note) == typeid(**it)){
            n = new Note(**it);
        }else{
            n = new Tag(static_cast<const Tag&>(**it));
        }
        V.push_back(n);
    }
}

vector<Note*>::iterator NoteManager::rechercher(int a)
{
    vector<Note*>::iterator it;
    for(it=V.begin(); it!=V.end(); it++){
        if((*it)->getID() == a)
            return it;
    }
    return V.end();
  }

void NoteManager::ajouter(const Note &x)
{
    try{
        vector<Note*>::iterator it = rechercher(x.getID());
        if(it == V.end()){
            Note * p = new Note(x);
            V.push_back(p);
        }else{
            throw string("erreur");
        }
    }
    catch (const string &ch){
        cerr << ch;
    }
}

void NoteManager::ajouter(const Tag &x)
{
    try{
        vector<Note*>::iterator it = rechercher(x.getID());
        if(it == V.end()){
            Note * p = new Tag(x);
            V.push_back(p);
        }else{
            throw string("erreur");
        }
    }
    catch (const string &ch){
        cerr << ch;
    }
}

void NoteManager::afficher(string obj)
{
    for(vector<Note*>::iterator it=V.begin(); it!=V.end(); it++){
        if((*it)->getOBJ() == obj)
            cout << (*it)->getDesc();
    }
}

void NoteManager::enregistrer(string obj)
{
    vector<Note*>::iterator it;
    ofstream file;

    file.open(obj + ".txt", ios::app);
    if(file){
        for(it=V.begin(); it!=V.end(); it++){
            if((*it)->getOBJ() == obj){
                file << (*it)->getOBJ();
                file << (*it)->getDesc();
            }
        }
    }else
        cout << "Error." << endl;
}


void NoteManager::charger(string obj)
{
    vector<Note*>::iterator it;
    ifstream file;

    file.open(obj + ".txt");
    if(file){
        string obj, desc;
        while(file >> obj >> desc;)
            cout << obj << desc;
    }else
        cout << "Error." << endl;
}
