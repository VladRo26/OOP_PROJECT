//
// Created by turis on 10/24/2022.
//

#include "Cofetarie.h"

using std::endl;
using std::string;
using std::vector;


Cofetarie::Cofetarie(const string &nume_, const vector<Angajat> &angajati_, const vector<Produs> &produse_)
        : Nume_Cofetarie{nume_}, Angajati{angajati_}, Produse{produse_} {}

Cofetarie::Cofetarie(const Cofetarie &other)
        : Nume_Cofetarie{other.Nume_Cofetarie}, Angajati(other.Angajati), Produse{other.Produse} {
}

Cofetarie &Cofetarie::operator=(const Cofetarie &other) {
    Nume_Cofetarie = other.Nume_Cofetarie;
    Angajati = other.Angajati;
    Produse = other.Produse;
    return *this;
}


std::ostream &operator<<(std::ostream &cof, const Cofetarie &c1) {
    cof << "Nume:" << c1.Nume_Cofetarie << endl;
    cof << "Angajati:" << endl;
    for (const auto &i: c1.Angajati) {
        cof << i;
    }
    cof << "Produse:" << endl;
    for (const auto &j: c1.Produse) {
        cof << j;
    }
    return cof;
}

