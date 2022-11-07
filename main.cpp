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
    Ingredient frisca = Ingredient("frisca", 500);
    Ingredient faina = Ingredient("faina", 100);
    vector<Ingredient> v1;
    v1.push_back(zahar);
    v1.push_back(frisca);
    v1.push_back(faina);
    vector<Ingredient> v1_1;
    v1_1.push_back(sare);
    v1_1.push_back(sirop1);
    v1_1.push_back(faina);
    vector<Ingredient> v1_2;
    v1_2.push_back(sare);
    v1_2.push_back(faina);
    ///Initializare ingrediente si vector ingrediente
    Angajat a1 = Angajat("Turis", "Cofetar", 1, 5000, 1, 5);
    Angajat a2 = Angajat("William", "Vanzator", 0, 3000, 1, 0);
    Angajat a3 = Angajat("Tudor", "Ajutor bucatar", 0, 2000, 1, 0);
    vector<Angajat *> v2;
    v2.push_back(&a1);
    v2.push_back(&a2);
    v2.push_back(&a3);
    ///Initializare angajati si vector angajati
    Produs savarina = Produs("savarina", v1, 10.50, 1, 0, 1, 20);
    Produs amandina = Produs("amandina", v1_1, 9.50, 0, 0, 1, 0);
    Produs saratele = Produs("saratele", v1_2, 5.50, 1, 1, 0, 30);
    vector<Produs *> v3;
    v3.push_back(&savarina);
    v3.push_back(&amandina);
    v3.push_back(&saratele);
    ///Initializare produse si vector de produse
    Client c1 = Client("Levi", 0);
    Client c2 = Client("Mihai", 0);
    Client c3 = Client("Paniti", 0);
    vector<Client *> v4;
    v4.push_back(&c1);
    v4.push_back(&c2);
    v4.push_back(&c3);
    ///Afisare Cofetarie la inceputul afacerii
    std::cout << endl;
    Cofetarie cofetarie1 = Cofetarie("Bon-Bon", v2, v3, v4);
//    std::cout << cofetarie1;
    a1.Gestiune_Stoc_Produs(amandina);
//    a1.CereMarireSalariu(60);
//    c1.Comanda_produs(savarina, 90, cofetarie1);


    return 0;
}