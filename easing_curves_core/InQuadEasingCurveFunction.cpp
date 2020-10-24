#include "InQuadEasingCurveFunction.h"

#include <cassert>

float InQuadEasingCurveFunction::operator()(float t) const
{
    assert(t >= 0.0f && t <= 1.0f);
    return t * t;
}

std::unique_ptr<EasingCurveFunction> InQuadEasingCurveFunction::clone() const
{
    return std::make_unique<InQuadEasingCurveFunction>(*this);
}
