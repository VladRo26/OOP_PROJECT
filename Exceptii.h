
#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H

#include <stdexcept>
#include <string>
#include <vector>

class eroare_aplicatie : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class input_invalid : public eroare_aplicatie {
public:
    input_invalid(const std::string &string_) : eroare_aplicatie("Input invalid: " + string_) {}
};

class null_ptr : public eroare_aplicatie {
public:
    null_ptr(const std::string &string_) : eroare_aplicatie("Pointerul este null: " + string_) {}
};

class eroare_constructor : public input_invalid {
public:
    eroare_constructor(const std::string &string_) : input_invalid("Eroare Constuctor: " + string_) {}
};


#endif //OOP_EXCEPTII_H
