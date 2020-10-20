#ifndef LINEAREASINGCURVEFUNCTION_H
#define LINEAREASINGCURVEFUNCTION_H

#include "EasingCurveFunction.h"

class LinearEasingCurveFunction : public EasingCurveFunction
{
public:
    float operator()(float progress) const override;
};

#endif // LINEAREASINGCURVEFUNCTION_H
