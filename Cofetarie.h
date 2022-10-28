//
// Created by turis on 10/24/2022.
//

#ifndef OOP_COFETARIE_H
#define OOP_COFETARIE_H

#include <iostream>
#include <vector>
#include "Ingredient.h"
#include "Angajat.h"
#include "Produs.h"
#include "Client.h"

class Client;

class Angajat;

class Produs;

class Cofetarie {
private:
    string Nume_Cofetarie;
    vector<Angajat *> Angajati;
    vector<Produs *> Produse;
    vector<Client *> Clienti;
public:
    Cofetarie(const string &nume_, const vector<Angajat *> &angajati_, const vector<Produs *> &produse_,
              const vector<Client *> &clienti_);

    Cofetarie(const Cofetarie &other);

    Cofetarie &operator=(const Cofetarie &other);

    ~Cofetarie() = default;

    friend std::ostream &operator<<(std::ostream &, const Cofetarie &);

    Produs *Cauta_Prod(const string &num_);


};


#endif //OOP_COFETARIE_H
