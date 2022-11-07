//
// Created by turis on 10/24/2022.
//

#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H

#include <iostream>
#include <vector>
#include "Produs.h"

using std::endl;
using std::string;
using std::vector;

class Produs;


class Angajat {
private:
    string Nume_Angajat;
    string Post;
    bool ECalificat;
    float Salariu;
    int Experienta;
    int Nr_vanzari = 0;
public:
    Angajat(const string &nume_, const string &post_, bool ecalificat_, float salariu_, int experienta_,
            int nr_vanzari);

    Angajat(const Angajat &other);

    Angajat &operator=(const Angajat &other);

    ~Angajat() = default;

    friend std::ostream &operator<<(std::ostream &, const Angajat &);

    bool EligibilMarire(float &proc);

    void CereMarireSalariu(float procent);

    void Gestiune_Stoc_Produs(Produs &prod_);

    void Comanda_Furnizor(Produs &prod_);

};


#endif //OOP_ANGAJAT_H
