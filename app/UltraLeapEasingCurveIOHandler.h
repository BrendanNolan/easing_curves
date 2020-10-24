#ifndef ULTRALEAPEASINGCURVEIOHANDLER_H
#define ULTRALEAPEASINGCURVEIOHANDLER_H

#include <istream>
#include <memory>
#include <ostream>

#include "EasingCurve.h"

class EasingCurveStringFactory;

class UltraLeapEasingCurveIOHandler
{
public:
    UltraLeapEasingCurveIOHandler(
        std::istream& inStream,
        std::ostream& outStream,
        std::shared_ptr<EasingCurveStringFactory> factory);

    void run();

private:
    std::string readNextValidLine();

private:
    std::istream* inStream_ = nullptr;
    std::ostream* outStream_ = nullptr;
    std::shared_ptr<EasingCurveStringFactory> factory_;
    EasingCurve curve_;

    bool curveApplyPending_ = false;
};

#endif //ULTRALEAPEASINGCURVEIOHANDLER_H
