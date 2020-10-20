#ifndef ULTRALEAPEASINGCURVEIOHANDLER_H
#define ULTRALEAPEASINGCURVEIOHANDLER_H

#include <istream>
#include <ostream>

class UltraLeapEasingCurveIOHandler
{
public:
    UltraLeapEasingCurveIOHandler(
        std::istream& inStream,
        std::ostream& outStream);

    void run();

private:
    std::istream* inStream_ = nullptr;
    std::ostream* outStream_ = nullptr;
};

#endif //ULTRALEAPEASINGCURVEIOHANDLER_H
