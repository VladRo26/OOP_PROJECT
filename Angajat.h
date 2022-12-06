//
// Created by turis on 11/26/2022.
//

#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H

#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include "Produs.h"
#include "Cofetarie.h"

using std::endl;
using std::string;
using std::vector;

class Cofetarie;

class Angajat {
private:
    virtual void Angajat_afisare(std::ostream &) const {}

    virtual bool Eligibil_marire(float proc_) {}

    =0;

protected:
    static int id_max;
    const int id;
    string Post;
    string Nume_Angajat;
    bool ECalificat;
    float Salariu;
    int Expreienta;

    Angajat(const Angajat &other) = default;

    Angajat &operator=(const Angajat &other);

public:
    virtual ~Angajat() = default;

    virtual std::shared_ptr<Angajat> clone() const = 0;

    Angajat(const string &Post_, const string &Nume_Angajat_, bool ECalificat_, float Salariu_, int Experienta_);

    friend std::ostream &operator<<(std::ostream &os, const Angajat &an);

    virtual void Lucreaza1(std::shared_ptr<Produs>, int) = 0;

    void Cerere_Marire_Salariu(float procent_);

    static int Get_id();
};

class Cofetar : public Angajat {
private:
    int Numar_Prajituri_Facute;

    void Angajat_afisare(std::ostream &os) const override;

    bool Eligibil_Marire(float proc_) override;

public:
    Cofetar(const string &Post_, const string &Nume_Angajat_, bool ECalificat_, float Salariu_, int Experienta_,
            int Numar_Prajituri_Facute_);

    std::shared_ptr<Angajat> clone() const override;

    void Lucreaza1(std::shared_ptr<Produs>, int) override;


};

class Vanzator : public Angajat {
private:
    int Numar_Vanzari;

    void Angajat_afisare(std::ostream &os) const override;

    bool Eligibil_Marire(float proc_) override;

public:
    Vanzator(const string &Post_, const string &Nume_Angajat_, bool ECalificat_, float Salariu_, int Experienta_,
             int Numar_Vanzari_);

    std::shared_ptr<Angajat> clone() const override;

    void Lucreaza1(std::shared_ptr<Produs>, int) override;

    std::shared_ptr<Produs> Cautare_Produs(const string &nume, Cofetarie &C);

};


#endif //OOP_ANGAJAT_H
