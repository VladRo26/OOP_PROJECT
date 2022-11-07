//
// Created by turis on 10/24/2022.
//

#include "Cofetarie.h"

using std::endl;
using std::string;
using std::vector;


Cofetarie::Cofetarie(const string &nume_, const vector<Angajat> &angajati_, const vector<Produs> &produse_,
                     const vector<Client> &clienti_)
        : Nume_Cofetarie{nume_}, Angajati{angajati_}, Produse{produse_}, Clienti{clienti_} {}

Cofetarie::Cofetarie(const Cofetarie &other)
        : Nume_Cofetarie{other.Nume_Cofetarie}, Angajati(other.Angajati), Produse{other.Produse},
          Clienti{other.Clienti} {
}

Cofetarie &Cofetarie::operator=(const Cofetarie &other) {
    Nume_Cofetarie = other.Nume_Cofetarie;
    Angajati = other.Angajati;
    Produse = other.Produse;
    Clienti = other.Clienti;
    return *this;
}


std::ostream &operator<<(std::ostream &os, const Cofetarie &c1) {
    os << "Nume:" << c1.Nume_Cofetarie << endl;
    os << "Angajati:" << endl;
    for (const auto &ang: c1.Angajati) {
        os << ang;
    }
    os << "Produse:" << endl;
    for (const auto &prod: c1.Produse) {
        os << prod;
    }
    os << "Clienti:" << endl;
    for (const auto &cli: c1.Clienti) {
        os << cli;
    }
    return os;
}

Produs *Cofetarie::Cauta_Prod(const string &num_) {
    for (auto &element: Produse) {
        if (num_ == element.Get_Nume()) {
            return &element;
        }
    }
    return nullptr;
}



