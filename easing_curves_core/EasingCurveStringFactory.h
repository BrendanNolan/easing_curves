#ifndef EASINGCURVESTRINGFACTORY_H
#define EASINGCURVESTRINGFACTORY_H

#include <string>

#include "EasingCurve.h"

class EasingCurveStringFactory
{
public:
    virtual ~EasingCurveStringFactory() = default;
    virtual EasingCurve create(const std::string& stringToParse) = 0;
};


#endif // EASINGCURVESTRINGFACTORY_H
