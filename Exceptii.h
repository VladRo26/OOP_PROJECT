
#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H

#include <stdexcept>
#include <string>
#include <vector>

class eroare_aplicatie : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class eroare_produs : public eroare_aplicatie {
public:
    explicit eroare_produs(const std::string &string_) : eroare_aplicatie("Eroare produs! " + string_) {}
};

class eroare_client : public eroare_aplicatie {
public:
    explicit eroare_client(const std::string &string_) : eroare_aplicatie("Eroare client! " + string_) {}
};

class eroare_cantitate : public eroare_aplicatie {
public:
    explicit eroare_cantitate(const std::string &string_) : eroare_aplicatie("Eroare cantitate! " + string_) {}
};

class eroare_pret : public eroare_aplicatie {
public:
    explicit eroare_pret(const std::string &string_) : eroare_aplicatie("Eroare pret! " + string_) {}
};

class eroare_angajat : public eroare_aplicatie {
public:
    explicit eroare_angajat(const std::string &string_) : eroare_aplicatie("Eroare agnajat " + string_) {}
};


#endif //OOP_EXCEPTII_H
