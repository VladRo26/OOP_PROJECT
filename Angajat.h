//
// Created by turis on 10/24/2022.
//

#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H

#include <iostream>
#include <vector>

using std::endl;
using std::string;
using std::vector;


class Angajat {
private:
    string Nume_Angajat;
    string Post;
    bool ECalificat;
    float Salariu;
    int Experienta;
public:
    Angajat(const string &nume_, const string &post_, bool ecalificat_, float salariu_, int experienta_);

    Angajat(const Angajat &other);

    Angajat &operator=(const Angajat &other);

    ~Angajat() = default;

    friend std::ostream &operator<<(std::ostream &, const Angajat &);

    bool EligibilMarire(const Angajat &);

    void CereMarireSalariu(Angajat &, float procent);


};


#endif //OOP_ANGAJAT_H
