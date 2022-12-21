
#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H

#include <stdexcept>
#include <string>
#include <vector>

class eroare_aplicatie : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class produs_negasit : public eroare_aplicatie {
public:
    explicit produs_negasit(const std::string &string_) : eroare_aplicatie("Eroare produs negasit!   " + string_) {}
};

class eroare_cantitate : public eroare_aplicatie {
public:
    explicit eroare_cantitate(const std::string &string_) : eroare_aplicatie("Eroare cantitate " + string_) {}
};

class eroare_vanzator : public eroare_aplicatie {
public:
    explicit eroare_vanzator(const std::string &string_) : eroare_aplicatie("Eroare vanzator " + string_) {}
};

class eroare_cofetar : public eroare_aplicatie {
public:
    explicit eroare_cofetar(const std::string &string_) : eroare_aplicatie("Eroare cofetar " + string_) {}
};


#endif //OOP_EXCEPTII_H
