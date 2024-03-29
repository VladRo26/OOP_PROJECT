//
// Created by turis on 11/26/2022.
//

#include "Cofetarie.h"

//Cofetarie::Cofetarie(const string &Nume_Cofetarie_, vector<std::shared_ptr<Angajat>> Angajati_,
//                     vector<std::shared_ptr<Produs>> Produse_, vector<std::shared_ptr<Client>> Clienti_, float Profit_,
//                     float Cifra_Afaceri_, float Costuri_)
//        : Nume_Cofetarie(Nume_Cofetarie_), Angajati(std::move(Angajati_)), Produse(std::move(Produse_)),
//          Clienti(std::move(Clienti_)), Profit(Profit_), Cifra_Afaceri(Cifra_Afaceri_), Costuri(Costuri_) {}

Cofetarie::Cofetarie(const Cofetarie &other) : Nume_Cofetarie(std::move(other.Nume_Cofetarie)),
                                               Cifra_Afaceri(other.Cifra_Afaceri), Costuri(other.Costuri) {
    for (const auto &ang: other.Angajati) {
        Angajati.emplace_back(ang->clone());
    }
    for (const auto &prod: other.Produse) {
        Produse.emplace_back(prod->clone());
    }
//    for (const auto &client_: other.Clienti) {
//        Clienti.emplace_back(client_->clone());
//    }
}

Cofetarie &Cofetarie::operator=(Cofetarie other) {
    swap(*this, other);
    return *this;
}

void swap(Cofetarie &c1, Cofetarie &c2) {
    using std::swap;
    swap(c1.Nume_Cofetarie, c2.Nume_Cofetarie);
//    swap(c1.Clienti, c2.Clienti);
    swap(c1.Produse, c2.Produse);
    swap(c1.Angajati, c2.Angajati);
    swap(c1.Cifra_Afaceri, c2.Cifra_Afaceri);
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
//    for (const auto &client_: cof.Clienti) {
//        os << *client_ << endl;
//    }

    os << "Cifra afaceri: " << cof.Cifra_Afaceri << " lei" << endl;
    os << "Costuri: " << cof.Costuri << " lei" << endl;
    os << "Profit: " << cof.Get_Profit() << " lei" << endl;
    os << "\n";
    return os;
}


float Cofetarie::Get_Profit() const {
    return Cifra_Afaceri - Costuri;
}

void Cofetarie::Adauga_Ang(std::shared_ptr<Angajat> ang_) {
    Angajati.push_back(ang_);
}

Cofetarie::Cofetarie(const string &Nume_Cofetarie_) : Nume_Cofetarie(Nume_Cofetarie_), Cifra_Afaceri(0), Costuri(0) {}

void Cofetarie::Adauga_Prod(std::shared_ptr<Produs> prod_) {
    Produse.push_back(prod_);
    Costuri += prod_->Get_Cost_Productie() * prod_->get_Cantiate();
}

std::shared_ptr<Vanzator> Cofetarie::Get_Vanzator() {
    std::shared_ptr<Vanzator> vanz_ = nullptr;
    for (const auto &ang_: Angajati) {
        vanz_ = std::dynamic_pointer_cast<Vanzator>(ang_);
        if (vanz_)
            return vanz_;
    }
    throw eroare_angajat("Nu s-a gasit niciun vanzator, printre angajatii confetariei!");
}

std::shared_ptr<Cofetar> Cofetarie::Get_Cofetar() {
    std::shared_ptr<Cofetar> cof_ = nullptr;
    for (const auto &ang_: Angajati) {
        cof_ = std::dynamic_pointer_cast<Cofetar>(ang_);
        if (cof_)
            return cof_;
    }
    throw eroare_angajat("Nu s-a gasit niciun cofetar, printre angajatii confetariei!");
}

std::vector<std::shared_ptr<Produs>> &Cofetarie::Get_Produse() {
    return Produse;
}

void Cofetarie::Add_Cifra_Afaceri(float add) {
    Cifra_Afaceri = Cifra_Afaceri + add;
}

void Cofetarie::adauga_Cost(float cost_) {
    Costuri += cost_;
}

void Cofetarie::Marire_Salariu_Angajat(const std::string &nume_, float proc) {
    for (auto &ang: this->Angajati) {
        if (ang->Get_Nume() == nume_) {
            ang->Cerere_Marire_Salariu(proc);
            return;
        }
    }
    throw eroare_angajat("Nu s-a gasit angajatul printre angajatii cofetariei");
}

void Cofetarie::Client_Comanda(const std::shared_ptr<Client> client_, const string &nume_, int cantitate_) {
    if (client_ != nullptr) {
        client_->Comanda_Produs(nume_, cantitate_, *this);
    } else {
        throw eroare_client("Clientul dat nu exista!");
    }
}

void Cofetarie::Descriere_Produs(const string &nume_) {
    for (auto &prod: this->Produse) {
        if (prod->get_Nume() == nume_) {
            prod->Descriere_Produs();
            return;
        }
    }
    throw eroare_produs("Produsul dat nu exista!");
}

