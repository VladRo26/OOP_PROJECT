#include <string>
#include <iostream>

class Student {
    std::string nume;
    int an;
public:
    Student(const std::string& nume_, int an_) : nume{nume_}, an{an_} {
        std::cout << "Constr de inițializare Student\n";
        std::cout<<nume_<<std::endl;
        std::cout<<an_<<std::endl;
    }
//    Student(const std::string& nume_="a", int an_=2)
//    {
//    nume=nume_;
//    an=an_;
//    }

    Student(const Student& other) : nume{other.nume}, an{other.an} {
        std::cout << "Constr de copiere Student\n";
        std::cout<<nume<<"\n";
        std::cout<<an<<"\n";
    }

    Student& operator=(const Student& other) {
        nume = other.nume;
        an = other.an;
        std::cout << "operator= copiere Student\n";
        return *this;
    }
};

class Facultate {
    std::string nume;
    Student stud;
public:

//    Facultate(const std::string& nume_,const Student& stud_) {
//        nume = nume_;
//        stud=stud_;
//        std::cout << "constructor de initializare FACULTATE";
//    }

    Facultate(const std::string& nume_, const Student& stud_):nume{nume_},stud{stud_}{
        std::cout << "MCMARIUS" << std::endl;
        std::cout<<"constructor de initializare FACULTATE";
    }


    Facultate(const Facultate& other):nume{other.nume},stud{other.stud}{
    std::cout<<"Constructor copiere facultate";
    }

    Facultate& operator=(const Facultate& other) {
        nume = other.nume;
        stud = other.stud;
        std::cout << "operator= copiere Facultatet\n";
        return *this;
    }
};

int main() {
  Facultate f1{"fmi",Student{"s1", 1}};
    //Student{"s1", 1};

//    Facultate f1;
//    nume_=&fmi;
//    stud_=&student

}