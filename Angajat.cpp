//
// Created by turis on 10/24/2022.
//

#include "Angajat.h"


Angajat::Angajat(const string &nume_, const string &post_, bool ecalificat_, float salariu_, int experienta_,
                 int nr_vanzari)
        : Nume_Angajat{nume_}, Post{post_}, ECalificat{ecalificat_}, Salariu{salariu_}, Experienta{experienta_},
          Nr_vanzari{nr_vanzari} {}

Angajat::Angajat(const Angajat &other)
        : Nume_Angajat(other.Nume_Angajat), Post{other.Post}, ECalificat{other.ECalificat}, Salariu{other.Salariu},
          Experienta{other.Experienta}, Nr_vanzari{other.Nr_vanzari} {}

Angajat &Angajat::operator=(const Angajat &other) {
    Nume_Angajat = other.Nume_Angajat;
    Post = other.Post;
    ECalificat = other.ECalificat;
    Salariu = other.Salariu;
    Experienta = other.Experienta;
    Nr_vanzari = other.Nr_vanzari;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Angajat &a1) {
    os << "Nume angajat:" << " " << a1.Nume_Angajat << " " << "Post:" << " " << a1.Post << " " << "Salariu:" << " "
       << a1.Salariu << " " << "E calificat?: " << a1.ECalificat << " " << "Expreienta:" << " " << a1.Experienta
       << "Numar Vanzari:" << " " << a1.Nr_vanzari
       << endl;
    os << endl;
    return os;
}

bool Angajat::EligibilMarire(float &proc) {
    int optiune = 0;
    if (proc <= 10 && Nr_vanzari >= 2)
        return 1;
    else if (proc <= 15 && Nr_vanzari >= 5)
        return 1;
    else if (proc > 15) {
        if (Experienta <= 2 || Nr_vanzari < 10) {
            std::cout << "Nu ai destula experienta capatata, va trebui sa mai astepti " << 2 - Experienta
                      << "ani sau sa mai faci " << 10 - Nr_vanzari << " se poate oferi maxim o marire de 15 procente"
                      << std::endl;
            std::cout << "Accepti marirea de 15 procente? (1.Da/2.Nu)";
            std::cin >> optiune;
            switch (optiune) {
                case 1:
                    proc = 15;
                    return 1;
                case 2:
                    return 0;
            }
        } else if (proc <= 30) {
            return 1;
        } else if (proc > 30 && proc < 50) {
            if (Nr_vanzari >= 20) {
                return 1;
            } else {
                std::cout
                        << "Pentru a se accepta o marire de peste 30 de procente trebuie sa ai mai mult de 20 de vanzari, mai ai de facut "
                        << 20 - Nr_vanzari << " maximul care se poate oferi este de 30 de procente" << std::endl;
                std::cout << "Accepti marirea de 30 de procente? (1.Da/2.Nu)";
                std::cin >> optiune;
                switch (optiune) {
                    case 1:
                        proc = 30;
                        return 1;
                    case 2:
                        return 0;
                    default:
                        break;
                }
            }
        } else if (proc >= 50) {
            if (Experienta <= 5 || Nr_vanzari < 30) {
                std::cout
                        << "Pentru o marire de peste 50 de procente iti trebuie minim 5 ani experienta si minim 30 de vanzari, mai ai de asteptat "
                        << 5 - Experienta << " ani, si de facut " << 30 - Nr_vanzari
                        << " mairea maxima care se poate oferi este de 50 de procente";
                std::cout << "Accepti marirea de 50 de procente? (1.Da/2.Nu)";
                std::cin >> optiune;
                switch (optiune) {
                    case 1:
                        proc = 50;
                        return 1;
                    case 2:
                        return 0;
                    default:
                        break;
                }
            } else
                return 1;
        }
    }
    return 0;
}

void Angajat::CereMarireSalariu(float procent) {
    if (EligibilMarire(procent) == 1) {
        Salariu = Salariu + Salariu * (procent) / 100;
        std::cout << "Noul salariu este:" << Salariu << endl;
    } else {
        std::cout << "Marirea nu a fost facuta!" << endl;
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







