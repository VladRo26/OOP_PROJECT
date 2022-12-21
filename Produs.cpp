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

Produs::Produs(const string &Nume_Produs_, float Pret_, bool DePost_, int Cantiate_Produs_, float Cost_Productie_)
        : Nume_Produs(std::move(Nume_Produs_)), Pret(Pret_), DePost(DePost_), Cantitate_Produs(Cantiate_Produs_),
          Cost_Productie(Cost_Productie_) {
//    if (Pret <= 0 && Pret < Cost_Productie)
//        throw eroare_constructor("Pretul pentru produs nu poate fi 0 sau mai mic decat costul productiei");
    if (Cantiate_Produs_ <= 0)
        throw eroare_cantitate("Cantitatea produsului nu poate fi mai mica sau egala cu 0");
}

void Produs::Add_Ingredient(const Ingredient &ing_, int Cantiate_Ingredient_) {
    Ingrediente_Produs.push_back(std::make_pair(ing_, Cantiate_Ingredient_));
}

int Produs::get_Cantiate() {
    return Cantitate_Produs;
}

string &Produs::get_Nume() {
    return Nume_Produs;
}

void Produs::set_Cantitate(int c) {
    Cantitate_Produs = c;
}

float Produs::get_Pret() {
    return Pret;
}

float Produs::Get_Cost_Productie() {
    return Cost_Productie;
}


std::shared_ptr<Produs> Produs_Dulce::clone() const {
    return std::make_shared<Produs_Dulce>(*this);
}

Produs_Dulce::Produs_Dulce(const string &Nume_Produs_, float Pret_, bool DePost_, int Cantiate_Produs_, bool EDulce_,
                           float Cost_Productie_)
        : Produs(Nume_Produs_, Pret_, DePost_, Cantiate_Produs_, Cost_Productie_), EDulce(EDulce_) {}

void Produs_Dulce::Produs_Afisare(std::ostream &os) const {
    os << "E dulce?: " << EDulce << endl;
    os << "\n";
}

void Produs_Dulce::Descriere_Produs() {
    std::cout << "Produsul cu numele: " << Nume_Produs << " contine zahar si nu este recomandat pentru diabetici!"
              << endl;
    std::cout << "De asemenea are si un numar ridicat de calorii" << endl;
    std::cout << "\n\n";
}

std::shared_ptr<Produs> Produs_Sarat::clone() const {
    return std::make_shared<Produs_Sarat>(*this);
}

void Produs_Sarat::Produs_Afisare(std::ostream &os) const {
    os << "E sarat?: " << ESarat << endl;
    os << "\n";
}

Produs_Sarat::Produs_Sarat(const string &Nume_Produs_, float Pret_, bool DePost_, int Cantiate_Produs_, bool ESarat_,
                           float Cost_Productie_)
        : Produs(Nume_Produs_, Pret_, DePost_, Cantiate_Produs_, Cost_Productie_), ESarat(ESarat_) {}

void Produs_Sarat::Descriere_Produs() {
    std::cout << "Produsul cu numele: " << Nume_Produs << " nu contine zahar si poate fi consumat si de diabetici!"
              << endl;
    std::cout << "Acesta contine un numar mai scazut de calorii si mai multi carbohidrati" << endl;
    std::cout << "\n\n";
}
