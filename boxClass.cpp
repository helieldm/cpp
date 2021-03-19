#include <iostream>
class Box
{
    float width, height, depth;

public:
    Box(float w, float h, float d) : width(w), height(h), depth(d) {}

    Box(float cubeSize) : Box(cubeSize, cubeSize, cubeSize)
    {
        std::cout << "OUAIS LE CONSTRUCTEUqsdqsdqsR OUAIIIS" << std::endl;
    }
    
    Box() : Box(5)
    {
        std::cout << "OUAIS LE CONSTRUCTEUR OUAIIIS" << std::endl;
    }

    float getVolume()
    {
        return width * height * depth;
    }

    bool canContain(Box &other)
    {
        return (
            this->width > other.width && this->height > other.height && this->depth > other.depth);
    }
};

int main(int argc, char **argv)
{
    Box b1;
    Box b2(4);
    std::cout << "B1 a un volume de " << b1.getVolume() << "cm3" << std::endl;
    std::cout << "B2 a un volume de " << b2.getVolume() << "cm3" << std::endl;
    if (b1.canContain(b2))
    {
        std::cout << "b1 est plus grand que b2" << std::endl;
    }
    else
    {

        std::cout << "b1 n'est pas plus grand que b2" << std::endl;
    }
}