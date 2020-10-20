#include "EasingCurve.h"

#include <utility>

using namespace std;

EasingCurve::EasingCurve(unique_ptr<EasingCurveFunction> function)
    : function_{ move(function) }
{
}

EasingCurve::EasingCurve(const EasingCurve& other)
{
    if (other.function_)
        function_ = other.function_->clone();
}

EasingCurve& EasingCurve::operator=(const EasingCurve & other)
{
    if (other.function_)
        function_ = other.function_->clone();
    return *this;
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
