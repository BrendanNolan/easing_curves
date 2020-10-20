#ifndef EASINGCURVEFACTORY_H
#define EASINGCURVEFACTORY_H

#include "EasingCurve.h"

class EasingCurveFactory
{
public:
    virtual EasingCurve create() const = 0;
};

#endif // EASINGCURVEFACTORY_H
