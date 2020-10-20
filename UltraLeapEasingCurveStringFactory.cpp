#include "UltraLeapEasingCurveStringFactory.h"

#include <memory>

#include "LinearEasingCurveFunction.h"

EasingCurve UltraLeapEasingCurveStringFactory::create(
    const std::string & stringToParse) const
{
    return EasingCurve(std::make_unique<LinearEasingCurveFunction>());
}
