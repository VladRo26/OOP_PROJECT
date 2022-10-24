#include <iostream>
#include <vector>

using std::endl;
using std::string;
using std::vector;
class Ingredient;
class Angajat;
class Produs;


class Cofetarie{
private:
    string Nume_Cofetarie;
    vector<Angajat> Angajati;
    vector<Produs> Produse;
public:
    Cofetarie(const string& nume_,const vector<Angajat>& angajati_,const vector<Produs>& produse_):Nume_Cofetarie{nume_},Angajati{angajati_},Produse{produse_}{}
    Cofetarie(const Cofetarie& other):Nume_Cofetarie{other.Nume_Cofetarie},Angajati(other.Angajati),Produse{other.Produse}{
    }
    Cofetarie& operator=(const Cofetarie& other)
    {
        Nume_Cofetarie=other.Nume_Cofetarie;
        Angajati=other.Angajati;
        Produse=other.Produse;
        return *this;
    }
    ~Cofetarie()=default;
    friend std::ostream& operator<<(std::ostream&,const Cofetarie&);

};


class Produs{
private:
    string Nume_Produs;
    vector<Ingredient> Ingrediente;
    float Pret;
    bool DePost;
    bool ESarat;
    bool EDulce;
public:
    Produs(const string& nume_,const vector<Ingredient>& ingrediente_,float pret_,bool depost_,bool esarat_,bool edulce_):Nume_Produs{nume_},Ingrediente{ingrediente_},Pret{pret_},DePost{depost_},ESarat{esarat_},EDulce{edulce_}{}
    Produs(const Produs& other):Nume_Produs{other.Nume_Produs},Ingrediente{other.Ingrediente},Pret{other.Pret},DePost{other.DePost},ESarat{other.ESarat},EDulce{other.EDulce}{}
    Produs& operator=(const Produs& other)
    {
        Nume_Produs=other.Nume_Produs;
        Ingrediente=other.Ingrediente;
        Pret=other.Pret;
        DePost=other.DePost;
        ESarat=other.ESarat;
        EDulce=other.EDulce;
        return *this;
    }
    ~Produs()=default;
    friend std::ostream& operator<<(std::ostream&,const Produs&);


};
class Angajat{
private:
    string Nume_Angajat;
    string Post;
    bool ECalificat;
    float Salariu;
public:
    Angajat(const string& nume_,const string& post_,bool ecalificat_,float salariu_):Nume_Angajat{nume_},Post{post_},ECalificat{ecalificat_},Salariu{salariu_}{}
    Angajat(const Angajat& other):Nume_Angajat(other.Nume_Angajat),Post{other.Post},ECalificat{other.ECalificat},Salariu{other.Salariu}{}
    Angajat& operator=(const Angajat& other)
    {
        Nume_Angajat=other.Nume_Angajat;
        Post=other.Post;
        ECalificat=other.ECalificat;
        Salariu=other.Salariu;
        return *this;
    }
    ~Angajat()=default;
   friend std::ostream & operator<<(std::ostream &,const Angajat&);
   friend std::ostream& operator<<(std::ostream& ,const Cofetarie&);



};

class Ingredient{
private:
    string Nume_Ingredient;
    float Cantitate;
public:
    Ingredient(const string& nume_,float cantitate_):Nume_Ingredient{nume_},Cantitate{cantitate_}{}
    Ingredient(const Ingredient& other):Nume_Ingredient{other.Nume_Ingredient},Cantitate{other.Cantitate}{}
    Ingredient& operator=(const Ingredient& other)
    {
        Nume_Ingredient=other.Nume_Ingredient;
        Cantitate=other.Cantitate;
        return* this;
    }
    ~Ingredient()=default;
    friend std::ostream & operator<<(std::ostream& ing,const Ingredient& i1);

};

std::ostream & operator<<(std::ostream& ing,const Ingredient& i1)
{
    ing<<"Nume ingredient: "<<i1.Nume_Ingredient<<" "<<"Cantitate: "<<i1.Cantitate<<endl;
    return ing;
}

std::ostream & operator<<(std::ostream & ang,const Angajat& a1)
{
    ang<<"Nume angajat:"<<" "<<a1.Nume_Angajat<<" "<<"Post:"<<" "<<a1.Post<<" "<<"Salariu:"<<" "<<a1.Salariu<<" "<<"E calificat?: "<<a1.ECalificat<<endl;
    ang<<endl;
    return ang;
}

std::ostream& operator<<(std::ostream& prod,const Produs& p1)
{
    prod<<"Nume produs:"<<" "<<p1.Nume_Produs<<" "<<"Pret:"<<" "<<p1.Pret<<" "<<"E de post?:"<<" "<<p1.DePost<<" "<<"E sarat?:"<<" "<<p1.ESarat<<" "<<"E dulce?"<<" "<<p1.EDulce<<endl;
    prod<<"Lista ingrediente:"<<endl;
    for(const auto&i:p1.Ingrediente)
    {
        prod<<i;
    }
    prod<<endl;
    return prod;
}

std::ostream& operator<<(std::ostream& cof,const Cofetarie& c1)
{
    cof<<"Nume:"<<c1.Nume_Cofetarie<<endl;
    cof<<"Angajati:"<<endl;
    for(const auto& i:c1.Angajati)
    {
        cof<<i;
    }
    cof<<"Produse:"<<endl;
    for(const auto& j:c1.Produse)
    {
        cof<<j;
    }
    return cof;
}
int main() {
    Ingredient sare= Ingredient("sare",50);
    Ingredient zahar= Ingredient("zahar",100);
    Ingredient sirop1=Ingredient("sirop de ciocolata",100);
    vector<Ingredient> v1;
    v1.push_back(sare);
    v1.push_back(zahar);
    v1.push_back(sirop1);
    Angajat a1= Angajat("Turis","Cofetar",1,5000);
    Angajat a2= Angajat("William","Vanzator",0,3000);
    vector<Angajat> v2;
    v2.push_back(a1);
    v2.push_back(a2);
    Produs savarina= Produs("savarina",v1,10.50,0,0,1);
    Produs amandina= Produs("amandina",v1,9.50,1,0,1);
    vector<Produs> v3;
    v3.push_back(savarina);
    v3.push_back(amandina);
    Cofetarie cofetarie1 = Cofetarie("Bon-Bon",v2,v3);
    std::cout<<cofetarie1;

return 0;
}