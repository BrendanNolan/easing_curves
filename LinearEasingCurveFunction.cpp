#include "LinearEasingCurveFunction.h"

#include <cassert>

float LinearEasingCurveFunction::operator()(float t) const
{
    assert(t >= 0.0f && t <= 1.0f);
    return t;
}

std::unique_ptr<EasingCurveFunction> LinearEasingCurveFunction::clone() const
{
    return std::make_unique<LinearEasingCurveFunction>(*this);
}
