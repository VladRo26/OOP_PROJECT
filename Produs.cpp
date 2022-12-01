//
// Created by turis on 11/28/2022.
//

#include "Produs.h"

std::ostream &operator<<(std::ostream &os, const Produs &prod) {
    os << "Nume Produs:" << prod.Nume_Produs << endl;
    os << "Pret: " << prod.Pret << endl;
    os << "E de Post?: " << prod.DePost << endl;
    os << "Cantitate: " << prod.Cantitate_Produs << endl;
    for (const auto &pair: prod.Ingrediente_Produs) {
        os << "Ingredient: " << pair.first.Get_Nume() << endl;
        os << "Cantiate utilizata: " << pair.second << endl;
    }
    prod.Produs_Afisare(os);
    return os;
}

Produs::Produs(const string &Nume_Produs_, float Pret_, bool DePost_, int Cantiate_Produs_)
        : Nume_Produs(std::move(Nume_Produs_)), Pret(Pret_), DePost(DePost_), Cantitate_Produs(Cantiate_Produs_) {}

void Produs::Add_Ingredient(const Ingredient &ing_, int Cantiate_Ingredient_) {
    Ingrediente_Produs.push_back(std::make_pair(ing_, Cantiate_Ingredient_));


}

std::shared_ptr<Produs> Produs_Dulce::clone() const {
    return std::make_shared<Produs_Dulce>(*this);
}

Produs_Dulce::Produs_Dulce(const string &Nume_Produs_, float Pret_, bool DePost_, int Cantiate_Produs_, bool EDulce_)
        : Produs(Nume_Produs_, Pret_, DePost_, Cantiate_Produs_), EDulce(EDulce_) {}

void Produs_Dulce::Produs_Afisare(std::ostream &os) const {
    os << "E dulce?: " << EDulce << endl;
    os << "\n";
}

std::shared_ptr<Produs> Produs_Sarat::clone() const {
    return std::make_shared<Produs_Sarat>(*this);
}

void Produs_Sarat::Produs_Afisare(std::ostream &os) const {
    os << "E sarat?: " << ESarat << endl;
    os << "\n";
}

Produs_Sarat::Produs_Sarat(const string &Nume_Produs_, float Pret_, bool DePost_, int Cantiate_Produs_, bool ESarat_)
        : Produs(Nume_Produs_, Pret_, DePost_, Cantiate_Produs_), ESarat(ESarat_) {}
