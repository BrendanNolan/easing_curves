#include "LinearEasingCurveFunction.h"

float LinearEasingCurveFunction::operator()(float progress) const
{
    return 0.0f;
}

std::unique_ptr<EasingCurveFunction> LinearEasingCurveFunction::clone() const
{
    return std::make_unique<LinearEasingCurveFunction>(*this);
}
