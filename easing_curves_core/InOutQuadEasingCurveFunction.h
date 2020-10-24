#ifndef INOUTQUADEASINGCURVEFUNCTION_H
#define INOUTQUADEASINGCURVEFUNCTION_H

#include "EasingCurveFunction.h"

class InOutQuadEasingCurveFunction : public EasingCurveFunction
{
public:
    float operator()(float t) const override;
    std::unique_ptr<EasingCurveFunction> clone() const override;
};

#endif // INOUTQUADEASINGCURVEFUNCTION_H
