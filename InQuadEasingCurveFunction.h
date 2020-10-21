#ifndef INQUADEASINGCURVEFUNCTION_H
#define INQUADEASINGCURVEFUNCTION_H

#include "EasingCurveFunction.h"

class InQuadEasingCurveFunction : public EasingCurveFunction
{
public:
    InQuadEasingCurveFunction(
        int xt0,
        int xtmax,
        float duration);

    float operator()(float progress) const override;
    std::unique_ptr<EasingCurveFunction> clone() const override;

private:
    int xt0_ = 0;
    int xtmax_ = 0;
    float duration_ = 0.0f;
};

#endif // INQUADEASINGCURVEFUNCTION_H
