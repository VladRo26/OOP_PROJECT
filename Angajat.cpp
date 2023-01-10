//
// Created by turis on 11/26/2022.
//

#include "Angajat.h"

int Angajat::id_max = 1;

std::ostream &operator<<(std::ostream &os, const Angajat &an) {
    os << "ID-ul Angajatului: " << an.id << endl;
    os << "Post: " << an.Post << endl;
    os << "Nume Angajat: " << an.Nume_Angajat << endl;
    os << "E Calificat?: " << an.ECalificat << endl;
    os << "Salariu: " << an.Salariu << endl;
    os << "Experienta: " << an.Expreienta << endl;
    an.Angajat_afisare(os);
    return os;
}

Angajat &Angajat::operator=(const Angajat &other) {
    Post = other.Post;
    Nume_Angajat = other.Nume_Angajat;
    ECalificat = other.ECalificat;
    Salariu = other.Salariu;
    Expreienta = other.Expreienta;
    return *this;
}

Angajat::Angajat(const string &Post_, const string &Nume_Angajat_, bool ECalificat_, float Salariu_, int Experienta_)
        : id(id_max), Post(std::move(Post_)), Nume_Angajat(std::move(Nume_Angajat_)), ECalificat(ECalificat_),
          Salariu(Salariu_), Expreienta(Experienta_) { id_max++; }

//int Angajat::Get_id() {
//    return id_max;
//}

void Angajat::Cerere_Marire_Salariu(float procent_) {
    if (Eligibil_marire(procent_) == 1) {
        Salariu = Salariu + (Salariu * procent_ / 100);
        std::cout << "Noul salariu este: " << Salariu << " lei" << endl;
    } else {
        std::cout << "Ne pare rau, salariul nu se va mari!";
    }
}

bool Angajat::Eligibil_marire(float &proc_) {
    std::cout << "procent: " << proc_;
    return 0;
}

void Cofetar::Angajat_afisare(std::ostream &os) const {
    os << "Numar Prajituri Facute: " << Numar_Prajituri_Facute << endl;
    os << "\n";
}

Cofetar::Cofetar(const string &Post_, const string &Nume_Angajat_, bool ECalificat_, float Salariu_, int Experienta_,
                 int Numar_Prajituri_Facute_) : Angajat(Post_, Nume_Angajat_, ECalificat_, Salariu_, Experienta_),
                                                Numar_Prajituri_Facute(Numar_Prajituri_Facute_) {}

std::shared_ptr<Angajat> Cofetar::clone() const {
    return std::make_shared<Cofetar>(*this);
}

void Cofetar::Lucreaza1(std::shared_ptr<Produs> p, int cantiate_) {
    std::cout << "Cofetarul prepara produsul: " << p->get_Nume() << " in cantiate de " << cantiate_ << endl;
    std::cout << "\n";
    Numar_Prajituri_Facute = Numar_Prajituri_Facute + p->get_Cantiate() + cantiate_;
    p->set_Cantitate(p->get_Cantiate() + cantiate_);
}

bool Cofetar::Eligibil_marire(float &proc_) {
    int optiune = 0;
    if (proc_ <= 10 && Numar_Prajituri_Facute >= 40)
        return 1;
    else if (proc_ <= 15 && Numar_Prajituri_Facute >= 80)
        return 1;
    else if (proc_ > 15) {
        if (Expreienta <= 2 || Numar_Prajituri_Facute < 150) {
            std::cout << "Nu ai destula experienta capatata, va trebui sa mai astepti " << 2 - Expreienta
                      << " ani sau sa mai faci " << 150 - Numar_Prajituri_Facute
                      << " prajituri, se poate oferi maxim o marire de 15 procente"
                      << std::endl;
            std::cout << "Accepti marirea de 15 procente? (1.Da/2.Nu)";
            std::cin >> optiune;
            switch (optiune) {
                case 1:
                    proc_ = 15;
                    return 1;
                case 2:
                    return 0;
            }
        } else if (proc_ <= 30) {
            return 1;
        } else if (proc_ > 30 && proc_ < 50) {
            if (Numar_Prajituri_Facute >= 200 && ECalificat == 1) {
                return 1;
            } else {
                std::cout
                        << "Pentru a se accepta o marire de peste 30 de procente trebuie sa ai mai mult de 200 de prajituri si sa fi calificat, mai ai de facut "
                        << 200 - Numar_Prajituri_Facute
                        << " prajituri sau de facut o facultate de profil,maximul care se poate oferi este de 30 de procente"
                        << std::endl;
                std::cout << "Accepti marirea de 30 de procente? (1.Da/2.Nu)";
                std::cin >> optiune;
                switch (optiune) {
                    case 1:
                        proc_ = 30;
                        return 1;
                    case 2:
                        return 0;
                    default:
                        break;
                }
            }
        } else if (proc_ >= 50) {
            if (Expreienta <= 5 || Numar_Prajituri_Facute < 300 || ECalificat == 0) {
                std::cout
                        << "Pentru o marire de peste 50 de procente iti trebuie minim 5 ani experienta si minim 300 de prajituri facute si sa fi calificat, mai ai de asteptat "
                        << 5 - Expreienta << " ani, sau de facut " << 300 - Numar_Prajituri_Facute
                        << " prajituri, sau de facut o facultate de profil, mairea maxima care se poate oferi este de 50 de procente";
                std::cout << "Accepti marirea de 50 de procente? (1.Da/2.Nu)";
                std::cin >> optiune;
                switch (optiune) {
                    case 1:
                        proc_ = 50;
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

void Vanzator::Angajat_afisare(std::ostream &os) const {
    os << "Numar Vanzari:" << Numar_Vanzari << endl;
    os << "\n";
}

Vanzator::Vanzator(const string &Post_, const string &Nume_Angajat_, bool ECalificat_, float Salariu_, int Experienta_,
                   int Numar_Vanzari_) : Angajat(Post_, Nume_Angajat_, ECalificat_, Salariu_, Experienta_),
                                         Numar_Vanzari(Numar_Vanzari_) {}

std::shared_ptr<Angajat> Vanzator::clone() const {
    return std::make_shared<Vanzator>(*this);
}

void Vanzator::Lucreaza1(std::shared_ptr<Produs> p, int cantiate_) {
    std::cout << "Vanzatorul vinde produsul " << p->get_Nume() << " in cantiatea de " << cantiate_ << endl;
    std::cout << "\n";
    p->set_Cantitate(p->get_Cantiate() - cantiate_);
    Numar_Vanzari++;
}

std::shared_ptr<Produs> Vanzator::Cautare_Produs(const string &nume, Cofetarie &c) {
    auto &produse = c.Get_Produse();
    for (auto &p: produse) {
        if (nume.compare(p->get_Nume()) == 0) {
            return p;
        }
    }
    throw produs_negasit("Produsul cu numele de " + nume + " nu s-a gasit in cofetarie");
}


bool Vanzator::Eligibil_marire(float &proc_) {
    int optiune = 0;
    if (proc_ <= 5 && Numar_Vanzari >= 2)
        return 1;
    else if (proc_ <= 10 && Numar_Vanzari >= 5)
        return 1;
    else if (proc_ > 10) {
        if (Expreienta <= 2 || Numar_Vanzari < 10) {
            std::cout << "Nu ai destula experienta capatata, va trebui sa mai astepti " << 2 - Expreienta
                      << "ani sau sa mai faci " << 10 - Numar_Vanzari << " se poate oferi maxim o marire de 10 procente"
                      << std::endl;
            std::cout << "Accepti marirea de 10 procente? (1.Da/2.Nu)";
            std::cin >> optiune;
            switch (optiune) {
                case 1:
                    proc_ = 10;
                    return 1;
                case 2:
                    return 0;
            }
        } else if (proc_ <= 20) {
            return 1;
        } else if (proc_ > 20 && proc_ < 40) {
            if (Numar_Vanzari >= 30) {
                return 1;
            } else {
                std::cout
                        << "Pentru a se accepta o marire de peste 20 de procente trebuie sa ai mai mult de 30 de vanzari, mai ai de facut "
                        << 30 - Numar_Vanzari << " vanzari,maximul care se poate oferi este de 20 de procente"
                        << std::endl;
                std::cout << "Accepti marirea de 20 de procente? (1.Da/2.Nu)";
                std::cin >> optiune;
                switch (optiune) {
                    case 1:
                        proc_ = 20;
                        return 1;
                    case 2:
                        return 0;
                    default:
                        break;
                }
            }
        } else if (proc_ >= 40) {
            if (Expreienta <= 5 || Numar_Vanzari < 100) {
                std::cout
                        << "Pentru o marire de peste 40 de procente iti trebuie minim 5 ani experienta si minim 100 de vanzari, mai ai de asteptat "
                        << 5 - Expreienta << " ani, si de facut " << 100 - Numar_Vanzari
                        << " vanzari,mairea maxima care se poate oferi este de 40 de procente";
                std::cout << "Accepti marirea de 40 de procente? (1.Da/2.Nu)";
                std::cin >> optiune;
                switch (optiune) {
                    case 1:
                        proc_ = 40;
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






