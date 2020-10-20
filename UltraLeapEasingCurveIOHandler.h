#ifndef ULTRALEAPEASINGCURVEIOHANDLER_H
#define ULTRALEAPEASINGCURVEIOHANDLER_H

#include <istream>
#include <memory>
#include <ostream>

#include "EasingCurveTextProvider.h"

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
    EasingCurve readNextCurve();
    void writeCurve(const EasingCurve& curve);

private:
    std::istream* inStream_ = nullptr;
    std::ostream* outStream_ = nullptr;
    std::shared_ptr<EasingCurveStringFactory> factory_;
    EasingCurveTextProvider textProvider_;
};

#endif //ULTRALEAPEASINGCURVEIOHANDLER_H
