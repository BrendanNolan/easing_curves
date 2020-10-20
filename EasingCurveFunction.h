#ifndef EASINGCURVEFUNCTION_H
#define EASINGCURVEFUNCTION_H

class EasingCurveFunction
{
public:
    virtual float operator()(float progress) const = 0;
};

#endif // EASINGCURVEFUNCTION_H
