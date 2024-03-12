#ifndef SD_LAB2_REPOSITORY_H
#define SD_LAB2_REPOSITORY_H

#include "Collection.h"

class Repository{
private:
    vector<Collection> repoCollection;
public:
    Repository();
    void AtribuireColectie(Collection &collection);
    int getSize();
    vector<Collection> getAllElements();
};

#endif //SD_LAB2_REPOSITORY_H
