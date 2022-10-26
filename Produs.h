//
// Created by turis on 10/24/2022.
//

#ifndef OOP_PRODUS_H
#define OOP_PRODUS_H

#include <iostream>
#include <vector>
#include "Ingredient.h"
#include "Client.h"

using std::endl;
using std::string;
using std::vector;


class Produs {
private:
    string Nume_Produs;
    vector<Ingredient> Ingrediente;
    float Pret;
    bool DePost;
    bool ESarat;
    bool EDulce;
    int Cantitate;
public:
    Produs(const string &nume_, const vector<Ingredient> &ingrediente_, float pret_, bool depost_, bool esarat_,
           bool edulce_, int cantitate_);

    Produs(const Produs &other);

    Produs &operator=(const Produs &other);

    ~Produs() = default;

    friend std::ostream &operator<<(std::ostream &, const Produs &);
    friend class Client;


};

#endif //OOP_PRODUS_H
