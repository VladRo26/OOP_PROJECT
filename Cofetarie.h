//
// Created by turis on 11/26/2022.
//

#ifndef OOP_COFETARIE_H
#define OOP_COFETARIE_H

#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include "Angajat.h"
#include "Produs.h"
#include "Client.h"

using std::endl;
using std::string;
using std::vector;

class Cofetarie {
private:
    string Nume_Cofetarie;
    vector<std::shared_ptr<Angajat>> Angajati;
    vector<std::shared_ptr<Produs>> Produse;
    vector<std::shared_ptr<Client>> Clienti;
public:
    Cofetarie(const string &Nume_Cofetarie_, vector<std::shared_ptr<Angajat>> Angajati_,
              vector<std::shared_ptr<Produs>> Produse_, vector<std::shared_ptr<Client>> Clienti_);

    Cofetarie(const Cofetarie &other);

    Cofetarie &operator<<(Cofetarie other);

    friend void swap(Cofetarie &c1, Cofetarie &c2);

    friend std::ostream &operator<<(std::ostream &os, const Cofetarie &cof) {
        os << "Nume cofetarie: " << cof.Nume_Cofetarie << endl;
        os << "Angajati: " << endl;
        for (const auto &ang: cof.Angajati) {
            os << *ang << endl;
        }
        for (const auto &prod: cof.Produse) {
            os << *prod << endl;
        }
        for (const auto &client_: cof.Clienti) {
            os << *client_ << endl;
        }
        return os;
    }
};


#endif //OOP_COFETARIE_H
