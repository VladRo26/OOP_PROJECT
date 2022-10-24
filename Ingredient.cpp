//
// Created by turis on 10/24/2022.
//

#include "Ingredient.h"

Ingredient::Ingredient(const string &nume_, float cantitate_) : Nume_Ingredient{nume_}, Cantitate{cantitate_} {}

Ingredient::Ingredient(const Ingredient &other) : Nume_Ingredient{other.Nume_Ingredient}, Cantitate{other.Cantitate} {}

Ingredient &Ingredient::operator=(const Ingredient &other) {
    Nume_Ingredient = other.Nume_Ingredient;
    Cantitate = other.Cantitate;
    return *this;
}

std::ostream &operator<<(std::ostream &ing, const Ingredient &i1) {
    ing << "Nume ingredient: " << i1.Nume_Ingredient << " " << "Cantitate: " << i1.Cantitate << endl;
    return ing;
}


