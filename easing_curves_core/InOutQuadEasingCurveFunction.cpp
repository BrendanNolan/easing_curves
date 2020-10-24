#include "InOutQuadEasingCurveFunction.h"

#include <cassert>

float InOutQuadEasingCurveFunction::operator()(float t) const
{
    assert(t >= 0.0f && t <= 1.0f);
    return t < 0.5f 
        ? 2.0f * t * t 
        : 1.0f - (2.0f - 2.0f * t) * (2.0f - 2.0f * t) /2.0f;
}

std::unique_ptr<EasingCurveFunction> InOutQuadEasingCurveFunction::clone() const
{
    return std::make_unique<InOutQuadEasingCurveFunction>(*this);
}