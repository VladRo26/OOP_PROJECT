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

    ///Declarare Ingrediente
    Ingredient sare("sare", 100);
    Ingredient zahar("zahar", 200);
    Ingredient faina("faina", 500);
    Ingredient frisca("frisca", 1000);
    ///Declarare Produse
    std::shared_ptr<Produs> p1 = std::make_shared<Produs_Dulce>("savarina", 5.5, 0, 20, 1, 3);
    p1->Add_Ingredient(zahar, 10);
    p1->Add_Ingredient(faina, 50);
    p1->Add_Ingredient(frisca, 100);

    try {
        std::shared_ptr<Produs> p2 = std::make_shared<Produs_Sarat>("saratele", 2.5, 1, 100, 1, 1);
        p2->Add_Ingredient(sare, 20);
        p2->Add_Ingredient(faina, 50);

        ///Declarare Angajati
        std::shared_ptr<Angajat> a1 = std::make_shared<Vanzator>("Vanzator", "Paniti", 0, 20000, 0, 0);
        std::shared_ptr<Angajat> a2 = std::make_shared<Cofetar>("Cofetar", "Mihai", 1, 3500, 2, 100);

        ///Declarare Cofetarie
        Cofetarie cof("Bon-Bon");
        cof.Adauga_Prod(p1);
        cof.Adauga_Prod(p2);
        cof.Adauga_Ang(a1);
        cof.Adauga_Ang(a2);

        ///Declarare Clienti
        std::shared_ptr<Client> c1 = std::make_shared<Client_Pers_Fizic>("Willam", 29, 4);
        std::shared_ptr<Client> c2 = std::make_shared<Client_Pers_Juridic>("Vincenziu SRL", 100, "RKO10", 123,
                                                                           "Strada Napoli");
        std::shared_ptr<Client> c3 = std::make_shared<Client_Special>("Iohanis",100,10,10);
        cof.Descriere_Produs("savarina");
        cof.Marire_Salariu_Angajat("Paniti", 20);
        cof.Marire_Salariu_Angajat("Mihai", 10);
        cof.Client_Comanda(c1, "savarina", 10);
        cof.Client_Comanda(c2, "saratele", 200);
        cof.Client_Comanda(c3,"saratele",500);
        std::cout << "Profitul cofetariei este:" << cof.Get_Profit();
    } catch (eroare_pret &err) {
        std::cout << err.what() << endl;
    } catch (eroare_produs &err) {
        std::cout << err.what() << endl;
    } catch (eroare_aplicatie &err) {
        std::cout << err.what() << endl;
    }
}