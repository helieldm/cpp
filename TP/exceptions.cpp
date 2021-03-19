#include "exceptions.hpp"

const char *NoGrades::what() const noexcept
{
    return "No grades were entered.";
}

BadIndex::BadIndex(size_t i, size_t l) : index(i), length(l)
{
    str = "Index " + std::to_string(index) + " out of range [0," + std::to_string(length - 1) + "].";
}
const char *BadIndex::what() const noexcept
{
    return str.c_str();
}