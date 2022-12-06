
#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H

#include <stdexcept>
#include <string>
#include <vector>

class eroare_aplicație : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class input_invalid : public eroare_aplicație {
public:
    input_invalid(const std::string &string_) : eroare_aplicație("Input invalid: " + string_) {}
};

class null_ptr : public eroare_aplicație {
public:
    null_ptr(const std::string &string_) : eroare_aplicație("Pointerul este null: " + string_) {}
};

class eroare_constructor : public input_invalid {
public:
    eroare_constructor(const std::string &string_) : input_invalid("Eroare Constuctor: " + string_) {}
};


#endif //OOP_EXCEPTII_H
