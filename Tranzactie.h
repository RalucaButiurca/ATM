#ifndef SD_LAB2_TRANZACTIE_H
#define SD_LAB2_TRANZACTIE_H

#include <vector>
#include <iostream>

using namespace std;

class Tranzactie{
private:
    int idTranzactie;
    int suma;
    string tipBancnote;
    int nrBancnote_tipBancnota;
public:
    Tranzactie();
    Tranzactie(int idTranzactieAtribuire, int sumaAtribuire, string tipBancnota, int nrBancnote_tipBancnota);
    ~Tranzactie();

    friend ostream &operator<<(ostream &os, Tranzactie &tranzactie);
};

#endif //SD_LAB2_TRANZACTIE_H
