#ifndef EASINGCURVESTRINGFACTORY_H
#define EASINGCURVESTRINGFACTORY_H

#include <string>

#include "EasingCurve.h"

class EasingCurveStringFactory
{
public:
    virtual EasingCurve create(const std::string& stringToParse) const = 0;
};


#endif // EASINGCURVESTRINGFACTORY_H