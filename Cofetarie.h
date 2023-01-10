//
// Created by turis on 11/26/2022.
//

#ifndef OOP_COFETARIE_H
#define OOP_COFETARIE_H

#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include "Angajat.h"
#include "Produs.h"
#include "Client.h"
#include "Exceptii.h"

using std::endl;
using std::string;
using std::vector;

class Angajat;

class Vanzator;

class Cofetar;

class Client;

class Cofetarie;

class Cofetarie {
private:
    string Nume_Cofetarie;
    vector<std::shared_ptr<Angajat>> Angajati;
    vector<std::shared_ptr<Produs>> Produse;
    //vector<std::shared_ptr<Client>> Clienti;
    float Cifra_Afaceri;
    float Costuri;

    float Get_Profit() const;
public:
//    Cofetarie(const string &Nume_Cofetarie_, vector<std::shared_ptr<Angajat>> Angajati_,
//              vector<std::shared_ptr<Produs>> Produse_, vector<std::shared_ptr<Client>> Clienti_, float Profit_,
//              float Cifra_Afaceri_, float Costuri_);

    explicit Cofetarie(const string &Nume_Cofetarie_);

    Cofetarie(const Cofetarie &other);

    Cofetarie &operator<<(Cofetarie other);

    friend void swap(Cofetarie &c1, Cofetarie &c2);

    friend std::ostream &operator<<(std::ostream &os, const Cofetarie &cof);

    void Adauga_Ang(std::shared_ptr<Angajat>);

    void Adauga_Prod(std::shared_ptr<Produs>);

    std::shared_ptr<Vanzator> Get_Vanzator();

    std::shared_ptr<Cofetar> Get_Cofetar();

    std::vector<std::shared_ptr<Produs>> &Get_Produse();

    void Set_Cifra_Afaceri(float cifra_afaceri_);
    //e publica deoarece e folosita in functia ReducereComanda din angajat


    void adauga_Cost(float cost_) {
        Costuri += cost_;
    }
    // void Functii_Produs()
    //{

    //}

};


#endif //OOP_COFETARIE_H
