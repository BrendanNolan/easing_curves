#include <fstream>
#include <iostream>

#include "UltraLeapEasingCurveIOHandler.h"
#include "UltraLeapEasingCurveStringFactory.h"

int main()
{
    UltraLeapEasingCurveIOHandler ioHandler{
        std::cin,
        std::cout,
        std::make_shared<UltraLeapEasingCurveStringFactory>() };
    
    ioHandler.run();
}
