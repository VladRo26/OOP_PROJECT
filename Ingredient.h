//
// Created by turis on 11/28/2022.
//

#ifndef OOP_INGREDIENT_H
#define OOP_INGREDIENT_H

#include <iostream>
#include <vector>
#include <utility>

using std::endl;
using std::string;
using std::vector;


class Ingredient {
private:
    string Nume_Ingredient;
    int Cantitate_Ingredient;
public:
    Ingredient(const string &Nume_Ingredient_, int Cantitate_Ingredient_);

    Ingredient(const Ingredient &other) = default;

    Ingredient &operator=(const Ingredient &other) = default;

    friend std::ostream &operator<<(std::ostream &os, Ingredient ingred);

    string Get_Nume() const {
        return Nume_Ingredient;
    }
};


#endif //OOP_INGREDIENT_H
