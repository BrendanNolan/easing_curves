#include "InOutQuadEasingCurveFunction.h"

InOutQuadEasingCurveFunction::InOutQuadEasingCurveFunction(
    int xt0,
    int xtmax,
    float duration)
    : xt0_{xt0}
    , xtmax_{ xtmax }
    , duration_{ duration }
{
}

float InOutQuadEasingCurveFunction::operator()(float progress) const
{
    return 0.0f;
}

std::unique_ptr<EasingCurveFunction> InOutQuadEasingCurveFunction::clone() const
{
    return std::make_unique<InOutQuadEasingCurveFunction>(*this);
}