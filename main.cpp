#include <iostream>
#include "Collection.h"
#include "Tranzactie.h"
#include "ATM.h"
#include "Repository.h"

using namespace std;

Collection optiune1(){
    Collection collection;

    int bancnota1 = 500, bancnota2 = 200, bancnota3 = 100, bancnota4 = 50, bancnota5 = 10;
    int occ1 = 2, occ2 = 5, occ3 = 5, occ4 = 20, occ5 = 50;

    collection.add(bancnota1, occ1);
    collection.add(bancnota2, occ2);
    collection.add(bancnota3, occ3);
    collection.add(bancnota4, occ4);
    collection.add(bancnota5, occ5);

    return collection;
}

void optiune2(Collection collection){
    int sumaCareTrebuiePlatita;

    int id = 0;

    cout << "Introduceti suma: ";
    cin >> sumaCareTrebuiePlatita;

    ATM atm1(sumaCareTrebuiePlatita);

    vector<int> bancnote = collection.getAllElements();
    vector<int> occur_bancnote = collection.getAllOccurences();

    int sizeBancnote = bancnote.size();

    vector<Tranzactie> tranzactiiDeStocat;

    int suma = 0;
    for(int i = 0; i < sizeBancnote; i++){
        int nrBancnoteFolosite = 0;
        while(suma + bancnote[i] <= sumaCareTrebuiePlatita){
            suma += bancnote[i];
            string bancnotaFolosita = to_string(bancnote[i]);
            nrBancnoteFolosite++;
            tranzactiiDeStocat.push_back(Tranzactie(++id, bancnote[i], bancnotaFolosita, nrBancnoteFolosite));
            occur_bancnote[i]--;
        }
    }
    for(int i = 0; i < tranzactiiDeStocat.size(); i++){
        cout << tranzactiiDeStocat[i] << "\n";
    }
    cout << "apasati 1 pentru salvare sau 0 pentru stergere: ";
    bool ok;
    cin >> ok;
    if(ok == 1)
        cout << "ati ales sa platiti.\n";
    else {
        cout << "ati ales sa nu platiti.\n";
        tranzactiiDeStocat.clear();
    }

}

void menu(){
    cout << "1. Adaugati o colectie de bancnote.\n";
    cout << "2. Adaugati suma de platit.\n";
    cout << "3. Afisare tranzactii.\n";
}

int main(){
    Repository repoCollection;


    while(true){
        menu();
        cout << "Alegeti o optiune:";

        int optiune = 0;
        cin >> optiune;

        if(optiune == 1){
            cout << "Toate bancnotele introduse de la tastatura: " << '\n';

            Collection collection = optiune1();

            repoCollection.AtribuireColectie(collection);

            vector<Collection> collectionFromRepo = repoCollection.getAllElements();
            for(int i = 0; i < collectionFromRepo.size(); i++){

                vector<int> auxElements = collectionFromRepo[i].getAllElements();
                vector<int> auxOccurences = collectionFromRepo[i].getAllOccurences();

                for(int j = 0; j < auxElements.size(); j++){
                    cout << auxElements[j] << " " << auxOccurences[j] << "\n";
                }
            }
        }
        else if(optiune == 2){

            Collection collection = optiune1();
            optiune2(collection);
        }
        else if(optiune == 3){

            Collection collection = optiune1();
            optiune2(collection);
        }
        else
            break;
    }
}