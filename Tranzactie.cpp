#include "Tranzactie.h"

Tranzactie::Tranzactie(){
    this->idTranzactie = 0;
    this->suma = 0;
}

Tranzactie::Tranzactie(int idTranzactieAtribuire, int sumaAtribuire, string tipBancnota, int nrBancnote_tipBancnota){
    this->idTranzactie = idTranzactieAtribuire;
    this->suma = sumaAtribuire;
    this->tipBancnote = tipBancnota;
    this->nrBancnote_tipBancnota = nrBancnote_tipBancnota;
}

Tranzactie::~Tranzactie() {
    ///
}

ostream &operator<<(ostream &os, Tranzactie &tranzactie){
    os << "idTranzactie: " << " " << tranzactie.idTranzactie << "\n";
    os << "suma platita: " << " " << tranzactie.suma << "\n";
    os << "tipBancnote: " << " " << tranzactie.tipBancnote << "\n";
    os << "nrBancnote de tipBancnota folosite: " << " " << tranzactie.nrBancnote_tipBancnota << "\n";
    return os;
}
