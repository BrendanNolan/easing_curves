#include "InQuadEasingCurveFunction.h"

float InQuadEasingCurveFunction::operator()(float progress) const
{
    return 0.0f;
}

std::unique_ptr<EasingCurveFunction> InQuadEasingCurveFunction::clone() const
{
    return std::make_unique<InQuadEasingCurveFunction>(*this);
}
