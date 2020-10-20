#ifndef OUTQUADEASINGCURVEFUNCTION_H
#define OUTQUADEASINGCURVEFUNCTION_H

#include "EasingCurveFunction.h"

class OutQuadEasingCurveFunction : public EasingCurveFunction
{
public:
    float operator()(float progress) const override;
};

#endif // OUTQUADEASINGCURVEFUNCTION_H
