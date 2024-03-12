#include "Repository.h"

Repository::Repository(){
    ///
}

void Repository::AtribuireColectie(Collection &collection){
    this->repoCollection.push_back(collection);
}

int Repository::getSize(){
    return this->repoCollection.size();
}

vector <Collection> Repository::getAllElements(){
    return this->repoCollection;
}