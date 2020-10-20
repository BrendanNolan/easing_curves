#ifndef INQUADEASINGCURVEFUNCTION_H
#define INQUADEASINGCURVEFUNCTION_H

#include "EasingCurveFunction.h"

class InQuadEasingCurveFunction : public EasingCurveFunction
{
public:
    float operator()(float progress) const override;
};

#endif // INQUADEASINGCURVEFUNCTION_H
