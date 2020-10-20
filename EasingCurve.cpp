#include "EasingCurve.h"

#include <utility>

#include "EasingCurveFunction.h"

using namespace std;

EasingCurve::EasingCurve(unique_ptr<EasingCurveFunction> function)
    : function_{ move(function) }
{
}

EasingCurve::~EasingCurve()
{
}

float EasingCurve::apply(float progress) const
{
    const auto& f = *function_;
    return f(progress);
}

void EasingCurve::setFunction(unique_ptr<EasingCurveFunction> function)
{
    function_ = move(function);
}

bool EasingCurve::isValid() const
{
    return static_cast<bool>(function_);
}
