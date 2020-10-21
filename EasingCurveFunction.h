#ifndef EASINGCURVEFUNCTION_H
#define EASINGCURVEFUNCTION_H

#include <memory>

class EasingCurveFunction
{
public:
    virtual ~EasingCurveFunction() = default;
    virtual float operator()(float t) const = 0;
    virtual std::unique_ptr<EasingCurveFunction> clone() const = 0;
};

#endif // EASINGCURVEFUNCTION_H
