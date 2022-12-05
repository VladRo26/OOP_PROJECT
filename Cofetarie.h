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

class Angajat;

class Client;

class Cofetarie;

class Cofetarie {
private:
    string Nume_Cofetarie;
    vector<std::shared_ptr<Angajat>> Angajati;
    vector<std::shared_ptr<Produs>> Produse;
    vector<std::shared_ptr<Client>> Clienti;
    float Profit;
    float Cifra_Afaceri;
public:
    Cofetarie(const string &Nume_Cofetarie_, vector<std::shared_ptr<Angajat>> Angajati_,
              vector<std::shared_ptr<Produs>> Produse_, vector<std::shared_ptr<Client>> Clienti_, float Profit_,
              float Cifra_Afaceri_);

    Cofetarie(const Cofetarie &other);

    Cofetarie &operator<<(Cofetarie other);

    friend void swap(Cofetarie &c1, Cofetarie &c2);

    friend std::ostream &operator<<(std::ostream &os, const Cofetarie &cof);

    std::shared_ptr<Produs> Cof_Cauta_Produs(const string &nume);

};


#endif //OOP_COFETARIE_H
