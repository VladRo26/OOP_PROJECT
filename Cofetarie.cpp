//
// Created by turis on 11/26/2022.
//

#include "Cofetarie.h"

Cofetarie::Cofetarie(const string &Nume_Cofetarie_, vector<std::shared_ptr<Angajat>> Angajati_,
                     vector<std::shared_ptr<Produs>> Produse_, vector<std::shared_ptr<Client>> Clienti_)
        : Nume_Cofetarie(Nume_Cofetarie_), Angajati(std::move(Angajati_)), Produse(std::move(Produse_)),
          Clienti(std::move(Clienti_)) {}

Cofetarie::Cofetarie(const Cofetarie &other) : Nume_Cofetarie(std::move(other.Nume_Cofetarie)) {
    for (const auto &ang: other.Angajati) {
        Angajati.emplace_back(ang->clone());
    }
    for (const auto &prod: other.Produse) {
        Produse.emplace_back(prod->clone());
    }
    for (const auto &client_: other.Clienti) {
        Clienti.emplace_back(client_->clone());
    }
}

Cofetarie &Cofetarie::operator<<(Cofetarie other) {
    swap(*this, other);
    return *this;
}

void swap(Cofetarie &c1, Cofetarie &c2) {
    using std::swap;
    swap(c1.Nume_Cofetarie, c2.Nume_Cofetarie);
    swap(c1.Clienti, c2.Clienti);
    swap(c1.Produse, c2.Produse);
    swap(c1.Angajati, c2.Angajati);
}
