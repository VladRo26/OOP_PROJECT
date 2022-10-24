//
// Created by turis on 10/24/2022.
//

#include "Angajat.h"

Angajat::Angajat(const string &nume_, const string &post_, bool ecalificat_, float salariu_)
        : Nume_Angajat{nume_}, Post{post_}, ECalificat{ecalificat_}, Salariu{salariu_} {}

Angajat::Angajat(const Angajat &other)
        : Nume_Angajat(other.Nume_Angajat), Post{other.Post}, ECalificat{other.ECalificat}, Salariu{other.Salariu} {}

Angajat &Angajat::operator=(const Angajat &other) {
    Nume_Angajat = other.Nume_Angajat;
    Post = other.Post;
    ECalificat = other.ECalificat;
    Salariu = other.Salariu;
    return *this;
}

std::ostream &operator<<(std::ostream &ang, const Angajat &a1) {
    ang << "Nume angajat:" << " " << a1.Nume_Angajat << " " << "Post:" << " " << a1.Post << " " << "Salariu:" << " "
        << a1.Salariu << " " << "E calificat?: " << a1.ECalificat << endl;
    ang << endl;
    return ang;
}



