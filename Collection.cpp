#include "Collection.h"
#include <algorithm>
#include <iostream>

using namespace std;

Collection::Collection() {
    ///
}

int Collection::getAt(int elem) {
    int sizeElements = this->elements.size();
    for(int i = 0; i < sizeElements; i++){
        int elementActual = this->elements[i];
        if(elementActual == elem)
            return i;
    }
    return -1;
}

bool Collection::search(int elem){
    if(getAt(elem) != -1){
        cout << "Am gasit elementul: " << elem << "\n";
        return true;
    }
    cout << "Nu am gasit elementul: " << elem << "\n";
    return false;
}

int Collection::searchByPossition(int position){
    if(this->elements[position] != 0){
        int elemCautat = this->elements[position];
        return elemCautat;
    }
    return -1;
}

int Collection::size(){
    cout << "Size vector:\n";
    return this->elements.size();
}

int Collection::nrOccurrences(int elem){

    int positionElem = getAt(elem);
    if(positionElem != -1){
        cout << elem << " gasit de: " << this->occurrences[positionElem] << " ori.\n";
        return this->occurrences[positionElem];
    }
    else{
        cout << elem << " Nu avem acest element adaugat. \n";
        return 0;
    }
}

bool Collection::remove(int elem) {

    int positionFindElement = getAt(elem);

    if(positionFindElement == -1){
        cout << "Nu avem inca acest element: " << elem << " adaugat \n";
        return 0;
    }
    else{
        cout << "Element gasit pe pozitia: " << positionFindElement << "\n";

        int aparitiiElem = this->occurrences[positionFindElement];
        if(aparitiiElem == 1){
            vector<int>::iterator it;
            it = this->elements.begin() + positionFindElement;
            this->elements.erase(it);
        }
        else{
            this->occurrences[positionFindElement] --;
        }
        return true;
    }
}

void Collection::add(int bancnota, int nrOccurencesDatDeUtilizator){

    int position_elem = this->getAt(bancnota);

    if(position_elem != -1){
        int aparitii_elem = this->occurrences[position_elem];

        aparitii_elem ++;
        this->occurrences[position_elem] = aparitii_elem;
    }
    else{
        this->elements.push_back(bancnota);
        this->occurrences.push_back(nrOccurencesDatDeUtilizator);
    }
}


vector<int> Collection::getAllElements(){
    return this->elements;
}


vector <int> Collection::getAllOccurences(){
    return this->occurrences;
}

void Collection::show_bancnote_occurences(){
    vector<int> bancnote;
    vector<int> occur_bancnote;

    bancnote = getAllElements();
    occur_bancnote = getAllOccurences();

    int size_bancnote = bancnote.size();

    for (int i = 0; i < size_bancnote; i ++)
        cout << bancnote[i] << " " << occur_bancnote[i] << "\n";
}

