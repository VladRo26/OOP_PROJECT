//
// Created by turis on 10/24/2022.
//

#include "Angajat.h"

Angajat::Angajat(const string &nume_, const string &post_, bool ecalificat_, float salariu_, int experienta_)
        : Nume_Angajat{nume_}, Post{post_}, ECalificat{ecalificat_}, Salariu{salariu_}, Experienta{experienta_} {}

Angajat::Angajat(const Angajat &other)
        : Nume_Angajat(other.Nume_Angajat), Post{other.Post}, ECalificat{other.ECalificat}, Salariu{other.Salariu},
          Experienta{other.Experienta} {}

Angajat &Angajat::operator=(const Angajat &other) {
    Nume_Angajat = other.Nume_Angajat;
    Post = other.Post;
    ECalificat = other.ECalificat;
    Salariu = other.Salariu;
    Experienta = other.Experienta;
    return *this;
}

std::ostream &operator<<(std::ostream &ang, const Angajat &a1) {
    ang << "Nume angajat:" << " " << a1.Nume_Angajat << " " << "Post:" << " " << a1.Post << " " << "Salariu:" << " "
        << a1.Salariu << " " << "E calificat?: " << a1.ECalificat << " " << "Expreienta:" << " " << a1.Experienta
        << endl;
    ang << endl;
    return ang;
}

bool Angajat::EligibilMarire(const Angajat &other) {
    if (other.Experienta > 2) {
        return 1;
    } else
        return 0;
}

void Angajat::CereMarireSalariu(Angajat &other, float procent) {
    if (EligibilMarire(other) == 1) {
        other.Salariu = other.Salariu + other.Salariu * (procent) / 100;
    } else {
        std::cout << "Nu se accepta marirea!";
    }


}








