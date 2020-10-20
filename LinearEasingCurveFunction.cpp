#include "LinearEasingCurveFunction.h"

LinearEasingCurveFunction::LinearEasingCurveFunction(
    int xt0, 
    int xtmax, 
    float duration)
    : xt0_{ xt0 }
    , xtmax_{ xtmax }
    , duration_{ duration }
{
}

float LinearEasingCurveFunction::operator()(float t) const
{
    return xt0_ + t * (xtmax_ - xt0_) / duration_;
}

std::unique_ptr<EasingCurveFunction> LinearEasingCurveFunction::clone() const
{
    return std::make_unique<LinearEasingCurveFunction>(*this);
}
