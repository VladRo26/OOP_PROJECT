#include <iostream>
#include <vector>
#include "Cofetarie.h"
#include "Exceptii.h"
#include <memory>

using std::endl;
using std::string;
using std::vector;
using std::array;

int main() {
    try {
        ///Declarare Ingrediente
        Ingredient sare = Ingredient("sare", 100);
        Ingredient zahar = Ingredient("zahar", 200);
        Ingredient faina = Ingredient("faina", 500);
        Ingredient frisca = Ingredient("frisca", 1000);
        ///Declarare Produse
        std::shared_ptr<Produs> p1;
        p1 = std::make_shared<Produs_Dulce>("savarina", 5.5, 0, 20, 1, 3);
        p1->Add_Ingredient(zahar, 10);
        p1->Add_Ingredient(faina, 50);
        p1->Add_Ingredient(frisca, 100);
        std::shared_ptr<Produs> p2;
        p2 = std::make_shared<Produs_Sarat>("saratele", 2.5, 1, 100, 1, 1);
        p2->Add_Ingredient(sare, 20);
        p2->Add_Ingredient(faina, 50);
        vector<std::shared_ptr<Produs>> vec_prod;
        vec_prod.emplace_back(p1);
        vec_prod.emplace_back(p2);
//    std::cout<<saratele;
//    std::cout<<savarina;
        ///Declarare Angajati
        std::shared_ptr<Angajat> a1;
        a1 = std::make_shared<Vanzator>("Vanzator", "Paniti", 0, 20000, 0, 0);
        std::shared_ptr<Angajat> a2;
        a2 = std::make_shared<Cofetar>("Cofetar", "Mihai", 1, 3500, 2, 100);
        vector<std::shared_ptr<Angajat>> vec_ang;
        vec_ang.emplace_back(a1);
        vec_ang.emplace_back(a2);
//    std::cout<<c1;
//    std::cout<<v1;
        ///Declarare Clienti
        std::shared_ptr<Client> c1;
        c1 = std::make_shared<Client_Pers_Fizic>("Willam", 29, 4);
        std::shared_ptr<Client> c2;
        c2 = std::make_shared<Client_Pers_Juridic>("Vincenziu SRL", 100, "RKO10", 123, "Strada Napoli");
        vector<std::shared_ptr<Client>> vec_client;
        vec_client.emplace_back(c1);
        vec_client.emplace_back(c2);
//    std::cout<<cl1;
//    std::cout<<cl2;
        ///Declarare Cofetarie
        Cofetarie cof1 = Cofetarie("Bon-Bon", vec_ang, vec_prod, vec_client, 0, 0, 0);
        std::cout << cof1;
        p1->Descriere_Produs();
        try {
            c1->Comanda_Produs(p1, 70, vec_ang, cof1);
        } catch (null_ptr &err) {
            std::cout << err.what() << endl;
        }
//        c2->Comanda_Produs(p2, 60, vec_ang, cof1);
        a1->Cerere_Marire_Salariu(10);
        a2->Cerere_Marire_Salariu(20);
        cof1.Calculeaza_Profit(p1);
        std::cout << cof1;
    } catch (eroare_constructor &err) {
        std::cout << err.what() << endl;
    }
}