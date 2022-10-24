//
// Created by turis on 10/24/2022.
//

#ifndef OOP_INGREDIENT_H
#define OOP_INGREDIENT_H

#include <iostream>
#include <vector>

using std::endl;
using std::string;
using std::vector;


class Ingredient {
private:
    string Nume_Ingredient;
    float Cantitate;
public:
    Ingredient(const string &nume_, float cantitate_);

    Ingredient(const Ingredient &other);

    Ingredient &operator=(const Ingredient &other);

    ~Ingredient() = default;

    friend std::ostream &operator<<(std::ostream &ing, const Ingredient &i1);

};

#endif //OOP_INGREDIENT_H
