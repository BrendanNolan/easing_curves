#ifndef INOUTQUADEASINGCURVEFUNCTION_H
#define INOUTQUADEASINGCURVEFUNCTION_H

#include "EasingCurveFunction.h"

class InOutQuadEasingCurveFunction : public EasingCurveFunction
{
public:
    float operator()(float progress) const override;
};

#endif // INOUTQUADEASINGCURVEFUNCTION_H
