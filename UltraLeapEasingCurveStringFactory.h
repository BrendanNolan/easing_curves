#ifndef ULTRALEAPEASINGCURVESTRINGFACTORY_H
#define ULTRALEAPEASINGCURVESTRINGFACTORY_H

#include <string>

#include "EasingCurve.h"
#include "EasingCurveStringFactory.h"


class UltraLeapEasingCurveStringFactory : public EasingCurveStringFactory
{
public:
    EasingCurve create(const std::string& stringToParse) const override;
};

#endif // ULTRALEAPEASINGCURVESTRINGFACTORY_H
