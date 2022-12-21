//
// Created by turis on 11/28/2022.
//

#include "Client.h"

//sa fac ceva sa aflu profitablitatea cofetariei si sa am si un cotabil angaja

std::ostream &operator<<(std::ostream &os, const Client &client_) {
    os << "Nume Client: " << client_.Nume_Client << endl;
    os << "Numar Comenzi:" << client_.Numar_Comenzi << endl;
    client_.Client_afisare(os);
    os << "\n";
    return os;
}

Client::Client(const string &Nume_, int Numar_com_) : Nume_Client(std::move(Nume_)), Numar_Comenzi(Numar_com_) {}

Client_Pers_Fizic::Client_Pers_Fizic(const string &Nume_, int Numar_com, int Vechime_) : Client(Nume_, Numar_com),
                                                                                         Vechime_Client(Vechime_) {}

std::shared_ptr<Client> Client_Pers_Fizic::clone() const { return std::make_shared<Client_Pers_Fizic>(*this); }

void Client_Pers_Fizic::Comanda_Produs(string nume_, int cantitate_, Cofetarie &cof) {
    std::shared_ptr<Vanzator> vanz = cof.Get_Vanzator();
    std::shared_ptr<Produs> p = vanz->Cautare_Produs(nume_, cof);
    if (cantitate_ > p->get_Cantiate()) {
        std::cout << "Nu avem destule produse pe stoc pentru aceasta comanda! Numarul maxim este de: "
                  << p->get_Cantiate() << endl;
        std::cout << "Doriti sa comandati alt produs sau doriti cantiatea ramasa de: " << p->get_Cantiate() << endl;
        std::cout << "1.Alt Produs/2.Cantiatea ramasa" << endl;
        int optiune_ = 0;
        int can = 0;
        std::cin >> optiune_;
        switch (optiune_) {
            case 1:
                std::cout << "Ce produs doriti sa comandati?" << endl;
                std::cout << "Nume produs: " << std::endl;
                std::getline(std::cin, nume_);
                std::getline(std::cin, nume_);
                while (nume_.empty() || nume_.length() < 5) {
                    std::cout << "Nume produs: " << std::endl;
                    std::getline(std::cin, nume_);
                }

                std::cout << "Cantiatea dorita: " << std::endl;
                std::cin >> can;
                if (can < 1) {
                    throw eroare_cantitate("Cantiatea data nu poate fi negativa!!");
                }
                p = vanz->Cautare_Produs(nume_, cof);
                Comanda_Produs(nume_, can, cof);
                break;
            case 2:
                Comanda_Produs(nume_, p->get_Cantiate(), cof);
                break;
            default:
                break;
        }
    } else {
        vanz->Lucreaza1(p, cantitate_);
        Reducere_Comadna_Produs(p, cantitate_, cof);
    }
}

void Client_Pers_Fizic::Reducere_Comadna_Produs(std::shared_ptr<Produs> p, int cantitate_, Cofetarie &c) {
    float cifra_afaceri = 0;
    if (Vechime_Client >= 3 && Vechime_Client <= 5 && Numar_Comenzi >= 10 && Numar_Comenzi < 30) {
        std::cout << "Aveti o reducere de 10% pentru ca sunteti client fidel de nivelul 1! " << endl;
        std::cout << "Totalul de plata este: " << 0.9 * (p->get_Pret() * float(cantitate_)) << endl;
        cifra_afaceri = cifra_afaceri + 0.9 * (p->get_Pret() * float(cantitate_));
        c.Set_Cifra_Afaceri(cifra_afaceri);
        std::cout << "\n";
        Numar_Comenzi++;
    } else if (Numar_Comenzi >= 30 && Numar_Comenzi <= 50) {
        std::cout << "Aveti o reducere de 20% pentru ca sunteti fidel de niveul 2! " << endl;
        std::cout << "Totalul de plata este: " << 0.8 * (p->get_Pret() * float(cantitate_)) << endl;
        cifra_afaceri = cifra_afaceri + 0.8 * (p->get_Pret() * float(cantitate_));
        c.Set_Cifra_Afaceri(cifra_afaceri);
        std::cout << "\n";
        Numar_Comenzi++;
    } else if (Vechime_Client >= 6 && Numar_Comenzi > 50) {
        std::cout << "Felicitari! Esti unul dintre cei mai fideli clienti! Pentru asta obtii o reducere de 40%%!!! "
                  << endl;
        std::cout << "Totalul de plata este: " << 0.6 * (p->get_Pret() * float(cantitate_)) << endl;
        cifra_afaceri = cifra_afaceri + 0.6 * (p->get_Pret() * float(cantitate_));
        c.Set_Cifra_Afaceri(cifra_afaceri);
        std::cout << "\n";
        Numar_Comenzi++;
    } else {
        Numar_Comenzi++;
        cifra_afaceri = cifra_afaceri + (p->get_Pret() * float(cantitate_));
        c.Set_Cifra_Afaceri(cifra_afaceri);
        std::cout << "Totalul de plata este: " << p->get_Pret() * float(cantitate_) << endl;
        std::cout << "\n";
    }
}

void Client_Pers_Juridic::Client_afisare(std::ostream &os) const {
    os << "Numar Ingregistrare: " << Nr_Inregistrare << endl;
    os << "Cod Unic: " << Cod_Unic << endl;
    os << "Adresa: " << Adresa << endl;

}

Client_Pers_Juridic::Client_Pers_Juridic(const string &Nume, int Numar_com, const string &Nr_Inrgistrare_,
                                         int Cod_Unic_,
                                         const string &Adresa_) : Client(Nume, Numar_com),
                                                                  Nr_Inregistrare(Nr_Inrgistrare_), Cod_Unic(Cod_Unic_),
                                                                  Adresa(Adresa_) {}

std::shared_ptr<Client> Client_Pers_Juridic::clone() const { return std::make_shared<Client_Pers_Juridic>(*this); }


void Client_Pers_Juridic::Comanda_Produs(string nume_, int cantitate_, Cofetarie &cof) {
    if (cantitate_ < 30) {
        std::cout << "Comanda pe Persoana Juridica trebuie sa aiba minim 30 de bucati! " << endl;
        std::cout << "Doriti sa comandati contiuati cu mai mult de 30 de bucati? 1.Da/2.Nu " << endl;
        int optiune = 0;
        std::cin >> optiune;
        switch (optiune) {
            case 1:
                std::cout << "Ce cantiate doriti?: " << endl;
                std::cin >> cantitate_;
                Comanda_Produs(nume_, cantitate_, cof);
                break;
            case 2:
                std::cout << "Va uram o zi buna! Va mai asteptam! " << endl;
                std::cout << "\n";
                break;
            default:
                break;
        }
    } else {
        std::shared_ptr<Vanzator> vanz = cof.Get_Vanzator();
        std::shared_ptr<Cofetar> cofetar = cof.Get_Cofetar();
        std::shared_ptr<Produs> p = vanz->Cautare_Produs(nume_, cof);
        if (cantitate_ > p->get_Cantiate()) {
            std::cout << "Nu avem cantitatea dorita, vom plasa comanda la cofetar! " << endl;
            cofetar->Lucreaza1(p, cantitate_ - p->get_Cantiate());
            cof.adauga_Cost((cantitate_ - p->get_Cantiate()) * p->Get_Cost_Productie());
            Comanda_Produs(nume_, cantitate_, cof);
        } else {
            vanz->Lucreaza1(p, cantitate_);
            Reducere_Comadna_Produs(p, cantitate_, cof);
        }
    }
}

void Client_Pers_Juridic::Reducere_Comadna_Produs(std::shared_ptr<Produs> p, int cantitate_, Cofetarie &c) {
    float cifra_afaceri = 0;
    if (cantitate_ > 40 && cantitate_ < 60 && Numar_Comenzi > 5 && Numar_Comenzi < 15) {
        std::cout
                << "Deoarece numarul de produse comandate este intre 40 si 50 si numarul de comenzi este mai mare de 5, veti beneficia de o reducere de 20% "
                << endl;
        std::cout << "Totalul de plata este: " << 0.8 * (p->get_Pret() * float(cantitate_)) << endl;
        cifra_afaceri = cifra_afaceri + 0.8 * (p->get_Pret() * float(cantitate_));
        c.Set_Cifra_Afaceri(cifra_afaceri);
        Numar_Comenzi++;
    } else if (cantitate_ >= 60 && cantitate_ <= 100 && Numar_Comenzi >= 15 && Numar_Comenzi < 30) {
        std::cout
                << "Deoarece numarul de produse comandate este intre 60 si 100 si numarul de comenzi este mai mare de 15,veti beneficia de o reducere de 30% "
                << endl;
        std::cout << "Totalul de plata este: " << 0.7 * (p->get_Pret() * float(cantitate_)) << endl;
        cifra_afaceri = cifra_afaceri + 0.7 * (p->get_Pret() * float(cantitate_));
        c.Set_Cifra_Afaceri(cifra_afaceri);
        Numar_Comenzi++;
    } else if (cantitate_ >= 100 && Numar_Comenzi > 30) {
        std::cout
                << "Deoarece numarul de produse comandate este mai mare de 100 si numarul de comenzi este mai mare de 30 veti beneficia de o reducere de 50% "
                << endl;
        std::cout << "Totalul de plata este: " << 0.5 * (p->get_Pret() * float(cantitate_)) << endl;
        cifra_afaceri = cifra_afaceri + 0.5 * (p->get_Pret() * float(cantitate_));
        c.Set_Cifra_Afaceri(cifra_afaceri);
        Numar_Comenzi++;
    } else {
        std::cout << "Totalul de plata este: " << p->get_Pret() * float(cantitate_) << endl;
        cifra_afaceri = cifra_afaceri + (p->get_Pret() * float(cantitate_));
        c.Set_Cifra_Afaceri(cifra_afaceri);
        Numar_Comenzi++;
    }
}
