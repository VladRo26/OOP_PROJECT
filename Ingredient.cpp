//
// Created by turis on 11/28/2022.
//

#include "Ingredient.h"

Ingredient::Ingredient(const string &Nume_Ingredient_, int Cantitate_Ingredient_) : Nume_Ingredient(
        std::move(Nume_Ingredient_)), Cantitate_Ingredient(Cantitate_Ingredient_) {}

std::ostream &operator<<(std::ostream &os, Ingredient ingred) {
    os << "Nume Ingredient: " << ingred.Nume_Ingredient << endl;
    os << "Cantiate Ingredient: " << ingred.Cantitate_Ingredient << endl;
    return os;
}
