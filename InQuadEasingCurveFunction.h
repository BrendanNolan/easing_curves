#ifndef INQUADEASINGCURVEFUNCTION_H
#define INQUADEASINGCURVEFUNCTION_H

#include "EasingCurveFunction.h"

class InQuadEasingCurveFunction : public EasingCurveFunction
{
public:
    float operator()(float progress) const override;
    std::unique_ptr<EasingCurveFunction> clone() const override;
};

#endif // INQUADEASINGCURVEFUNCTION_H
