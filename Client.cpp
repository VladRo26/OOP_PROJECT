//
// Created by turis on 11/28/2022.
//

#include "Client.h"


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
