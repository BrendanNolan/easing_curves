#ifndef ULTRALEAPEASINGCURVESTRINGFACTORY_H
#define ULTRALEAPEASINGCURVESTRINGFACTORY_H

#include <string>

#include "EasingCurve.h"
#include "EasingCurveStringFactory.h"


class UltraLeapEasingCurveStringFactory : public EasingCurveStringFactory
{
public:
    EasingCurve create(const std::string& stringToParse) override;

private:
    int parseXt0(const std::string& s);
    int parseXtmax(const std::string& s);
    float parseDuration(const std::string& s);

private:
    bool failed_ = false;
};

#endif // ULTRALEAPEASINGCURVESTRINGFACTORY_H
