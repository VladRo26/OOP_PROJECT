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


class Cofetarie {
private:
    string Nume_Cofetarie;
    vector<Angajat> Angajati;
    vector<Produs> Produse;
public:
    Cofetarie(const string &nume_, const vector<Angajat> &angajati_, const vector<Produs> &produse_);

    Cofetarie(const Cofetarie &other);

    Cofetarie &operator=(const Cofetarie &other);

    ~Cofetarie() = default;

    friend std::ostream &operator<<(std::ostream &, const Cofetarie &);
};


#endif //OOP_COFETARIE_H
