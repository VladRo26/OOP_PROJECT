//
// Created by turis on 10/24/2022.
//

#include "Produs.h"

Produs::Produs(const string &nume_, const vector<Ingredient> &ingrediente_, float pret_, bool depost_, bool esarat_,
               bool edulce_, int cantitate_)
        : Nume_Produs{nume_}, Ingrediente{ingrediente_}, Pret{pret_}, DePost{depost_}, ESarat{esarat_},
          EDulce{edulce_}, Cantitate{cantitate_} {}

Produs::Produs(const Produs &other)
        : Nume_Produs{other.Nume_Produs}, Ingrediente{other.Ingrediente}, Pret{other.Pret}, DePost{other.DePost},
          ESarat{other.ESarat}, EDulce{other.EDulce}, Cantitate{other.Cantitate} {}

Produs &Produs::operator=(const Produs &other) {
    Nume_Produs = other.Nume_Produs;
    Ingrediente = other.Ingrediente;
    Pret = other.Pret;
    DePost = other.DePost;
    ESarat = other.ESarat;
    EDulce = other.EDulce;
    Cantitate = other.Cantitate;
    return *this;
}

std::ostream &operator<<(std::ostream &prod, const Produs &p1) {
    prod << "Nume produs:" << " " << p1.Nume_Produs << " " << "Pret:" << " " << p1.Pret << " " << "E de post?:" << " "
         << p1.DePost << " " << "E sarat?:" << " " << p1.ESarat << " " << "E dulce?" << " " << p1.EDulce << " "
         << "Cantitate:" << " " << p1.Cantitate << endl;
    prod << "Lista ingrediente:" << endl;
    for (const auto &i: p1.Ingrediente) {
        prod << i;
    }
    prod << endl;
    return prod;
}

