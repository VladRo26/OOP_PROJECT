//
// Created by turis on 10/25/2022.
//
#include <iostream>
#include <vector>

using std::endl;
using std::string;
using std::vector;

#ifndef OOP_CLIENT_H
#define OOP_CLIENT_H


class Client {
private:
    string Nume_Client;
    int Numar_Comenzi;
public:
    Client(const string &nume_client_, int numar_comenzi_ = 0);

    Client(const Client &other);

    Client &operator=(const Client &other);

    friend std::ostream &operator<<(std::ostream &cl, const Client &);


};


#endif //OOP_CLIENT_H
