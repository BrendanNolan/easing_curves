#ifndef ULTRALEAPEASINGCURVESTRINGFACTORY_H
#define ULTRALEAPEASINGCURVESTRINGFACTORY_H

#include <string>

#include "EasingCurve.h"
#include "EasingCurveStringFactory.h"


class UltraLeapEasingCurveStringFactory : public EasingCurveStringFactory
{
public:
    explicit UltraLeapEasingCurveStringFactory(
        const std::string& stringToParse);

    EasingCurve create() const override;
};

#endif // ULTRALEAPEASINGCURVESTRINGFACTORY_H
