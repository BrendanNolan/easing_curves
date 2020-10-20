#include "InOutQuadEasingCurveFunction.h"

float InOutQuadEasingCurveFunction::operator()(float progress) const
{
    return 0.0f;
}

std::unique_ptr<EasingCurveFunction> InOutQuadEasingCurveFunction::clone() const
{
    return std::make_unique<InOutQuadEasingCurveFunction>(*this);
}