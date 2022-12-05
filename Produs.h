//
// Created by turis on 11/28/2022.
//

#ifndef OOP_PRODUS_H
#define OOP_PRODUS_H

#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include "Ingredient.h"

using std::endl;
using std::string;
using std::vector;
using std::pair;


class Produs {
private:
    virtual void Produs_Afisare(std::ostream &) const {};
protected:
    string Nume_Produs;
    float Pret;
    bool DePost;
    int Cantitate_Produs;
    vector<pair<Ingredient, int>> Ingrediente_Produs;
    float Cost_Productie;

    Produs(const Produs &other) = default;

    Produs &operator=(const Produs &other) = default;

public:
    virtual ~Produs() = default;

    virtual std::shared_ptr<Produs> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Produs &prod);

    Produs(const string &Nume_Produs_, float Pret_, bool DePost_, int Cantiate_Produs_);

    void Add_Ingredient(const Ingredient &ing_, int Cantiate_Ingredient_);

    int get_Cantiate();

    string &get_Nume();

    void set_Cantitate(int c);

    float get_Pret();
};

class Produs_Dulce : public Produs {
private:
    bool EDulce;

    void Produs_Afisare(std::ostream &os) const override;

public:
    std::shared_ptr<Produs> clone() const override;

    Produs_Dulce(const string &Nume_Produs_, float Pret_, bool DePost_, int Cantiate_Produs_, bool EDulce_);
};

class Produs_Sarat : public Produs {
private:
    bool ESarat;

    void Produs_Afisare(std::ostream &os) const override;

public:
    std::shared_ptr<Produs> clone() const override;

    Produs_Sarat(const string &Nume_Produs_, float Pret_, bool DePost_, int Cantiate_Produs_, bool ESarat_);
};


#endif //OOP_PRODUS_H
