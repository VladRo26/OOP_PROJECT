#include <iostream>
#include <vector>
#include "Cofetarie.h"

using std::endl;
using std::string;
using std::vector;


int main() {
    ///Declarare Ingrediente
    Ingredient sare = Ingredient("sare", 100);
    Ingredient zahar = Ingredient("zahar", 200);
    Ingredient faina = Ingredient("faina", 500);
    Ingredient frisca = Ingredient("frisca", 1000);
    ///Declarare Produse
    Produs_Sarat saratele = Produs_Sarat("Saratele", 2.5, 1, 30, 1);
    saratele.Add_Ingredient(sare, 20);
    saratele.Add_Ingredient(faina, 50);
    Produs_Dulce savarina = Produs_Dulce("savarina", 5.5, 0, 20, 1);
    savarina.Add_Ingredient(zahar, 10);
    savarina.Add_Ingredient(faina, 50);
    savarina.Add_Ingredient(frisca, 100);
    vector<std::shared_ptr<Produs>> vec_prod;
    vec_prod.emplace_back(saratele.clone());
    vec_prod.emplace_back(savarina.clone());
//    std::cout<<saratele;
//    std::cout<<savarina;
    ///Declarare Angajati
    Cofetar c1 = Cofetar("Cofetar", "Mihai", 1, 3500, 2, 100);
    Vanzator v1 = Vanzator("Vanzator", "Paniti", 0, 2000, 0, 0);
//    std::cout<<c1;
//    std::cout<<v1;
    ///Declarare Clienti
    Client_Pers_Fizic cl1 = Client_Pers_Fizic("Willam", 0, 0);
    Client_Pers_Juridic cl2 = Client_Pers_Juridic("Vincenziu SRL", 100, "RKO10", 123, "Strada Napoli");
//    std::cout<<cl1;
//    std::cout<<cl2;
    ///Declarare Cofetarie
    Cofetarie cof1 = Cofetarie("Bon-Bon", {c1.clone(), v1.clone()}, vec_prod,
                               {cl1.clone(), cl2.clone()});
    std::cout << cof1;


}