#ifndef LINEAREASINGCURVEFUNCTION_H
#define LINEAREASINGCURVEFUNCTION_H

#include <memory>

#include "EasingCurveFunction.h"

class LinearEasingCurveFunction : public EasingCurveFunction
{
public:
    float operator()(float t) const override;
    
    std::unique_ptr<EasingCurveFunction> clone() const override;
};

#endif // LINEAREASINGCURVEFUNCTION_H
