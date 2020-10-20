#include <fstream>
#include <iostream>

#include "UltraLeapEasingCurveIOHandler.h"
#include "UltraLeapEasingCurveStringFactory.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
        return -1;

    std::ifstream inFile{argv[1]};

    UltraLeapEasingCurveIOHandler ioHandler{
        inFile,
        std::cout,
        std::make_shared<UltraLeapEasingCurveStringFactory>() };
    
    ioHandler.run();

    return 0;
}
