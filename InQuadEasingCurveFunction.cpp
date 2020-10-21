#include "InQuadEasingCurveFunction.h"

InQuadEasingCurveFunction::InQuadEasingCurveFunction(
    int xt0,
    int xtmax,
    float duration)
    : xt0_{ xt0 }
    , xtmax_{ xtmax }
    , duration_{ duration }
{
}

float InQuadEasingCurveFunction::operator()(float progress) const
{
    return 0.0f;
}

std::unique_ptr<EasingCurveFunction> InQuadEasingCurveFunction::clone() const
{
    return std::make_unique<InQuadEasingCurveFunction>(*this);
}
