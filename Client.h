//
// Created by turis on 10/25/2022.
//


#ifndef OOP_CLIENT_H
#define OOP_CLIENT_H

#include <iostream>
#include <vector>
#include "Produs.h"

using std::endl;
using std::string;
using std::vector;
class Produs;


class Client {
private:
    string Nume_Client;
    int Numar_Comenzi;
public:
    Client(const string &nume_client_, int numar_comenzi_);

    Client(const Client &other);

    Client &operator=(const Client &other);

    ~Client() = default;

    void Comanda_produs(Produs &prod, int cantitate_);

    friend std::ostream &operator<<(std::ostream &, const Client &);

};


#endif //OOP_CLIENT_H
