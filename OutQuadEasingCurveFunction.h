#ifndef OUTQUADEASINGCURVEFUNCTION_H
#define OUTQUADEASINGCURVEFUNCTION_H

#include "EasingCurveFunction.h"

class OutQuadEasingCurveFunction : public EasingCurveFunction
{
public:
    float operator()(float t) const override;
    std::unique_ptr<EasingCurveFunction> clone() const override;
};

#endif // OUTQUADEASINGCURVEFUNCTION_H
