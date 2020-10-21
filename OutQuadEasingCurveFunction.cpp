#include "OutQuadEasingCurveFunction.h"

OutQuadEasingCurveFunction::OutQuadEasingCurveFunction(
    int xt0,
    int xtmax,
    float duration)
    : xt0_{ xt0 }
    , xtmax_{ xtmax }
    , duration_{ duration }
{
}

float OutQuadEasingCurveFunction::operator()(float progress) const
{
    return 0.0f;
}

std::unique_ptr<EasingCurveFunction> OutQuadEasingCurveFunction::clone() const
{
    return std::make_unique<OutQuadEasingCurveFunction>(*this);
}
