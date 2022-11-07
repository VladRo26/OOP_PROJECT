//
// Created by turis on 10/25/2022.
//

#include "Client.h"


using std::endl;
using std::string;
using std::vector;

Client::Client(const Client &other) : Nume_Client{other.Nume_Client}, Numar_Comenzi{other.Numar_Comenzi} {}

Client &Client::operator=(const Client &other) {
    Nume_Client = other.Nume_Client;
    Numar_Comenzi = other.Numar_Comenzi;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Client &c1) {
    os << "Nume Client: " << c1.Nume_Client << " " << "Numar Comenzi: " << c1.Numar_Comenzi << " " << endl;
    return os;
}

Client::Client(const string &nume_client_, int numar_comenzi_) : Nume_Client{nume_client_},
                                                                 Numar_Comenzi{numar_comenzi_} {

}


void Client::Comanda_produs(Produs &prod_, int cantitate_, Cofetarie &c1) {
    if (cantitate_ > prod_.Get_Cantitate()) {
        std::cout << "Nu avem destule produse pe stock pentru aceasta comanda! Numarul maxim este de :"
                  << prod_.Get_Cantitate() << endl;
        std::cout << "Doriti sa comandati alt produs sau doriti cantitatea de " << prod_.Get_Cantitate() << endl
                  << "1.Alt Produs/2.Cantitatea ramasa" << endl;
        string num;
        int optiune_ = 0;
        int can = 0;
        Produs *p1 = nullptr;
        std::cin >> optiune_;
        switch (optiune_) {
            case 1:
                std::cout << "Ce produs doriti sa comandati?" << endl;
                std::cout << "Nume produs: " << std::endl;
                std::cin >> num;
                std::cout << "Caintiatea dorita: " << std::endl;
                std::cin >> can;
                p1 = c1.Cauta_Prod(num);
                if (p1 == nullptr) {
                    std::cout << "Nu s-a gasit produsul";
                    return;
                }
                Comanda_produs(*p1, can, c1);
                break;
            case 2:
                Comanda_produs(prod_, prod_.Get_Cantitate(), c1);
                break;
        }
    } else {
        prod_.Set_Cantitate(prod_.Get_Cantitate() - cantitate_);
        Numar_Comenzi++;
        std::cout << "Totalul de plata este: " << prod_.Get_Pret() * float(cantitate_) << endl;
    }
}



