#include <iostream>
#include "list.hpp"
#include "student.hpp"
#include "exceptions.hpp"

int main(int argc, char **argv)
{

    List<float> l1;
    List<float> l2;
    std::cout << l1 << std::endl;
    l1.push(23);
    l1.push(21);
    l1.push(2);
    l1.push(2);
    l1.push(2);
    l1.push(2);
    l1.push(2);
    l1.push(2);

    std::cout << l1[1] << std::endl;

    try
    {
        float var = l1[7];
    }
    catch (const BadIndex &e)
    {
        const char *str = e.what();
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << l1 << std::endl;
}