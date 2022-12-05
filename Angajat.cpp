//
// Created by turis on 11/26/2022.
//

#include "Angajat.h"

int Angajat::id_max = 1;

std::ostream &operator<<(std::ostream &os, const Angajat &an) {
    os << "ID-ul Angajatului: " << an.id << endl;
    os << "Post: " << an.Post << endl;
    os << "Nume Angajat: " << an.Post << endl;
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
    std::cout << "Cofetarul prepara produsul: " << p->get_Nume() << "in cantiate de " << cantiate_;
    p->set_Cantitate(cantiate_);
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
    std::cout << "Vanzatorul vinde produsul " << p->get_Nume() << "in cantiatea de " << cantiate_;
    p->set_Cantitate(cantiate_);
}

std::shared_ptr<Produs> Vanzator::Cautare_Produs(const string &nume, Cofetarie &c) {
    return c.Cof_Cauta_Produs(nume);
}






