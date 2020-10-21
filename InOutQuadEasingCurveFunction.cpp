#include "InOutQuadEasingCurveFunction.h"

float InOutQuadEasingCurveFunction::operator()(float t) const
{
    return t < 0.5f 
        ? 2.0f * t * t 
        : 2.0f * t * (1.0f - t) + 0.5f;
}

std::unique_ptr<EasingCurveFunction> InOutQuadEasingCurveFunction::clone() const
{
    return std::make_unique<InOutQuadEasingCurveFunction>(*this);
}