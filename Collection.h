#ifndef SD_LAB2_COLLECTION_H
#define SD_LAB2_COLLECTION_H

#include <iostream>
#include <vector>

using namespace std;

class Collection {
private:
    vector<int> elements;
    vector<int> occurrences;

public:
    Collection();

    void add(int elem, int nrOccurencesDatDeUtilizator);
    bool remove(int elem);
    bool search(int elem);
    int searchByPossition(int position);
    int size();
    int nrOccurrences(int elem);

    vector<int> getAllElements();
    vector<int> getAllOccurences();

    int getAt(int position);
    void show_bancnote_occurences();

    friend ostream &operator<<(ostream& os, Collection& collection){
        for(int i = 0; i < collection.elements.size(); i++)
            os << collection.elements[i] << " " << collection.occurrences[i] << "\n";
        return os;
    }
};

#endif //SD_LAB2_COLLECTION_H
