//
// Created by turis on 11/28/2022.
//

#ifndef OOP_CLIENT_H
#define OOP_CLIENT_H

#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include <utility>

using std::endl;
using std::string;
using std::vector;


class Client {
private:
    virtual void Client_afisare(std::ostream &) const {};
protected:
    string Nume_Client;
    int Numar_Comenzi;

    Client(const Client &other) = default;

    Client &operator=(const Client &other) = default;

public:
    virtual ~Client() = default;

    virtual std::shared_ptr<Client> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Client &client_);

    Client(const string &Nume_, int Numar_com_);

};

class Client_Pers_Fizic : public Client {
private:
    int Vechime_Client;

    void Client_afisare(std::ostream &os) const override {
        os << "Vechime Client: " << Vechime_Client << endl;
    }

public:
    Client_Pers_Fizic(const string &Nume_, int Numar_com, int Vechime_);

    std::shared_ptr<Client> clone() const override;

};

class Client_Pers_Juridic : public Client {
private:
    string Nr_Inregistrare;
    int Cod_Unic;
    string Adresa;

    void Client_afisare(std::ostream &os) const override;

public:
    Client_Pers_Juridic(const string &Nume, int Numar_com, const string &Nr_Inrgistrare_, int Cod_Unic_,
                        const string &Adresa_);

    std::shared_ptr<Client> clone() const override;

};


#endif //OOP_CLIENT_H
