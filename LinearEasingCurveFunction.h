#ifndef LINEAREASINGCURVEFUNCTION_H
#define LINEAREASINGCURVEFUNCTION_H

#include <memory>

#include "EasingCurveFunction.h"

class LinearEasingCurveFunction : public EasingCurveFunction
{
public:
    LinearEasingCurveFunction(
        int xt0, 
        int xtmax, 
        float duration);

    float operator()(float t) const override;
    
    std::unique_ptr<EasingCurveFunction> clone() const override;

private:
    int xt0_ = 0;
    int xtmax_ = 0; 
    float duration_= 0.0f;
};

#endif // LINEAREASINGCURVEFUNCTION_H
