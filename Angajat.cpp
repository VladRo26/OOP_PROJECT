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

bool Angajat::EligibilMarire() {
    if (Experienta > 2) {
        return true;
    } else { return false; }
}

void Angajat::CereMarireSalariu(float procent) {
    if (EligibilMarire() == 1) {
        Salariu = Salariu + Salariu * (procent) / 100;
        std::cout << "Noul salariu este:" << Salariu << endl;
    } else {
        std::cout << "Nu se accepta marirea!" << endl;
    }
}

void Angajat::Verificare_Stock_Produs(Produs &prod_) {
    if (prod_.Get_Cantitate() > 0) {
        std::cout << "Mai avem pe stock " << prod_.Get_Cantitate() << " bucati" << endl;
    }
    if (prod_.Get_Cantitate() == 0) {
        std::cout << prod_.Get_Nume() << " nu mai este pe stock!" << endl;
        std::cout << "Doriti sa lansez o comanda la furnizor? (Da 1/Nu 2)" << endl;
        int Optiune;
        std::cin >> Optiune;
        int cantitate_;
        switch (Optiune) {
            case 1:
                std::cout << "Ce cantitate doriti?" << endl;
                std::cin >> cantitate_;
                prod_.Set_Cantitate(cantitate_);
                std::cout << "S-a comandat produsul " << prod_.Get_Nume() << " " << "in cantiate de " << cantitate_
                          << endl;
                break;
            case 2:
                std::cout << "Mai asteptam pana vom primi din nou produsul!";
        }
    }


}







