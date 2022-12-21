//
// Created by turis on 11/28/2022.
//

#include "Ingredient.h"

Ingredient::Ingredient(const string &Nume_Ingredient_, int Cantitate_Ingredient_) : Nume_Ingredient(
        std::move(Nume_Ingredient_)), Cantitate_Ingredient(Cantitate_Ingredient_) {
    if (Cantitate_Ingredient_ <= 0)
        throw eroare_cantitate("Cantitatea unui ingredient nu poate fi 0 sau mai mica de 0!");
}

std::ostream &operator<<(std::ostream &os, Ingredient ingred) {
    os << "Nume Ingredient: " << ingred.Nume_Ingredient << endl;
    os << "Cantiate Ingredient: " << ingred.Cantitate_Ingredient << endl;
    return os;
}

string Ingredient::Get_Nume() const {
    return Nume_Ingredient;
}
