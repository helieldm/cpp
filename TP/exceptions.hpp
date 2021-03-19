#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>

class NoGrades : public std::exception
{
public:
    virtual const char *what() const noexcept;
};

class BadIndex : public std::exception
{
    size_t index, length;
    std::string str;

public:
    BadIndex(size_t i, size_t l);

    virtual const char *what() const noexcept;
};
#endif