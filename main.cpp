#include <iostream>
#include <vector>
#include "Ingredient.h"
#include "Angajat.h"
#include "Produs.h"
#include "Cofetarie.h"

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
    vector<Angajat> v2;
    v2.push_back(a1);
    v2.push_back(a2);
    Produs savarina = Produs("savarina", v1, 10.50, 0, 0, 1);
    Produs amandina = Produs("amandina", v1, 9.50, 1, 0, 1);
    vector<Produs> v3;
    v3.push_back(savarina);
    v3.push_back(amandina);
    Cofetarie cofetarie1 = Cofetarie("Bon-Bon", v2, v3);
    std::cout << cofetarie1;


    return 0;
}