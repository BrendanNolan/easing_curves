#include "InQuadEasingCurveFunction.h"

float InQuadEasingCurveFunction::operator()(float t) const
{
    return t * t;
}

std::unique_ptr<EasingCurveFunction> InQuadEasingCurveFunction::clone() const
{
    return std::make_unique<InQuadEasingCurveFunction>(*this);
}
