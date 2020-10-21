#include "OutQuadEasingCurveFunction.h"

float OutQuadEasingCurveFunction::operator()(float t) const
{
    return 1.0f - (1.0f - t) * (1.0f - t);
}

std::unique_ptr<EasingCurveFunction> OutQuadEasingCurveFunction::clone() const
{
    return std::make_unique<OutQuadEasingCurveFunction>(*this);
}
