//
// Created by turis on 11/26/2022.
//

#include "Cofetarie.h"

Cofetarie::Cofetarie(const string &Nume_Cofetarie_, vector<std::shared_ptr<Angajat>> Angajati_,
                     vector<std::shared_ptr<Produs>> Produse_, vector<std::shared_ptr<Client>> Clienti_, float Profit_,
                     float Cifra_Afaceri_, float Costuri_)
        : Nume_Cofetarie(Nume_Cofetarie_), Angajati(std::move(Angajati_)), Produse(std::move(Produse_)),
          Clienti(std::move(Clienti_)), Profit(Profit_), Cifra_Afaceri(Cifra_Afaceri_), Costuri(Costuri_) {}

Cofetarie::Cofetarie(const Cofetarie &other) : Nume_Cofetarie(std::move(other.Nume_Cofetarie)), Profit(other.Profit),
                                               Cifra_Afaceri(other.Cifra_Afaceri), Costuri(other.Costuri) {
    for (const auto &ang: other.Angajati) {
        Angajati.emplace_back(ang->clone());
    }
    for (const auto &prod: other.Produse) {
        Produse.emplace_back(prod->clone());
    }
    for (const auto &client_: other.Clienti) {
        Clienti.emplace_back(client_->clone());
    }
}

Cofetarie &Cofetarie::operator<<(Cofetarie other) {
    swap(*this, other);
    return *this;
}

void swap(Cofetarie &c1, Cofetarie &c2) {
    using std::swap;
    swap(c1.Nume_Cofetarie, c2.Nume_Cofetarie);
    swap(c1.Clienti, c2.Clienti);
    swap(c1.Produse, c2.Produse);
    swap(c1.Angajati, c2.Angajati);
    swap(c1.Cifra_Afaceri, c2.Cifra_Afaceri);
    swap(c1.Profit, c2.Profit);
    swap(c1.Costuri, c2.Costuri);
}

std::ostream &operator<<(std::ostream &os, const Cofetarie &cof) {
    os << "Nume cofetarie: " << cof.Nume_Cofetarie << endl;
    os << "Angajati: " << endl;
    for (const auto &ang: cof.Angajati) {
        os << *ang << endl;
    }
    for (const auto &prod: cof.Produse) {
        os << *prod << endl;
    }
    for (const auto &client_: cof.Clienti) {
        os << *client_ << endl;
    }

    os << "Cifra afaceri: " << cof.Cifra_Afaceri << " lei" << endl;
    os << "Costuri: " << cof.Costuri << " lei" << endl;
    os << "Profit: " << cof.Profit << " lei" << endl;
    return os;
}

std::shared_ptr<Produs> Cofetarie::Cof_Cauta_Produs(const string &nume) {
    try {
        if (nume.empty() || nume.size() < 7)
            throw input_invalid("Inputul din functia cauta produs nu a fost introdus cum trebuie");
        for (auto &prod: Produse) {
            if (nume.compare(prod->get_Nume()) == 0)
                return prod;
        }
    } catch (input_invalid &err) {
        std::cout << err.what() << endl;
    }
    return nullptr;
}

float Cofetarie::Get_Profit() {
    return Profit;
}

float Cofetarie::Get_Cifra_Afaceri() {
    return Cifra_Afaceri;
}

float Cofetarie::Get_Costuri() {
    return Costuri;
}

void Cofetarie::Set_Profit(float profit_) {
    Profit = profit_;
}

void Cofetarie::Set_Cifra_Afaceri(float cifra_afaceri_) {
    Cifra_Afaceri = cifra_afaceri_;
}

void Cofetarie::Set_Costuri(float costuri_) {
    Costuri = costuri_;
}

//Momentan las doar costurile produselor, as putea sa pun si salarile angajatiilor
void Cofetarie::Calculeaza_Costuri(std::shared_ptr<Produs> p) {
    Costuri = p->Get_Cost_Total();
}

void Cofetarie::Calculeaza_Profit(std::shared_ptr<Produs> p) {
    Calculeaza_Costuri(p);
    Profit = Cifra_Afaceri - Costuri;
}
