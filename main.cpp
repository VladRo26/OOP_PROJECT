#include <iostream>
#include <vector>
#include "Ingredient.h"
#include "Angajat.h"
#include "Produs.h"
#include "Cofetarie.h"
#include "Client.h"


using std::endl;
using std::string;
using std::vector;


int main() {
    Ingredient sare = Ingredient("sare", 50);
    Ingredient zahar = Ingredient("zahar", 100);
    Ingredient sirop1 = Ingredient("sirop de ciocolata", 100);
    vector<Ingredient> v1;
    v1.push_back(sare);
    v1.push_back(zahar);
    v1.push_back(sirop1);
    Angajat a1 = Angajat("Turis", "Cofetar", 1, 5000, 3);
    Angajat a2 = Angajat("William", "Vanzator", 0, 3000, 1);
    vector<Angajat *> v2;
    v2.push_back(&a1);
    v2.push_back(&a2);
    Produs savarina = Produs("savarina", v1, 10.50, 0, 0, 1, 10);
    Produs amandina = Produs("amandina", v1, 9.50, 1, 0, 1, 9);
    vector<Produs *> v3;
    v3.push_back(&savarina);
    v3.push_back(&amandina);
    a1.CereMarireSalariu(10);
    a2.CereMarireSalariu(90);
    Client c1 = Client("Levi", 0);
    Client c2 = Client("Mihai", 0);
    vector<Client *> v4;
    v4.push_back(&c1);
    v4.push_back(&c2);
    Cofetarie cofetarie1 = Cofetarie("Bon-Bon", v2, v3, v4);
    std::cout << cofetarie1;
    c1.Comanda_produs(savarina, 5);
    c1.Comanda_produs(savarina, 5);
    c1.Comanda_produs(savarina, 5);
//    for(auto &i:v3)
//    {
//        std::cout<<*i;
//    }
//    std::cout<<savarina;
//    std::cout << cofetarie1;
    Cofetarie cofetarie2(cofetarie1);


    return 0;
}