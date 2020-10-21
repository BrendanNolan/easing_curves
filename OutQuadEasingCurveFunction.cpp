#include "OutQuadEasingCurveFunction.h"

float OutQuadEasingCurveFunction::operator()(float progress) const
{
    return 0.0f;
}

std::unique_ptr<EasingCurveFunction> OutQuadEasingCurveFunction::clone() const
{
    return std::make_unique<OutQuadEasingCurveFunction>(*this);
}
