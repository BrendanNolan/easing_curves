#include "LinearEasingCurveFunction.h"

float LinearEasingCurveFunction::operator()(float t) const
{
    return t * t;
}

std::unique_ptr<EasingCurveFunction> LinearEasingCurveFunction::clone() const
{
    return std::make_unique<LinearEasingCurveFunction>(*this);
}
