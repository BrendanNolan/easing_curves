#include "OutQuadEasingCurveFunction.h"

#include <cassert>

float OutQuadEasingCurveFunction::operator()(float t) const
{
    assert(t >= 0.0f && t <= 1.0f);
    return 1.0f - (1.0f - t) * (1.0f - t);
}

std::unique_ptr<EasingCurveFunction> OutQuadEasingCurveFunction::clone() const
{
    return std::make_unique<OutQuadEasingCurveFunction>(*this);
}
