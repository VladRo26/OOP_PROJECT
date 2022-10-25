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

std::ostream &operator<<(std::ostream &cl, const Client &c1) {
    cl << "Nume Client: " << c1.Nume_Client << " " << "Numar Comenzi: " << c1.Numar_Comenzi << " " << endl;
    return cl;

}

Client::Client(const string &nume_client_, int numar_comenzi_) : Nume_Client{nume_client_},
                                                                 Numar_Comenzi{numar_comenzi_} {

}
