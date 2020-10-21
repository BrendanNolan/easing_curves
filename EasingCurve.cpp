#include "EasingCurve.h"

#include <utility>

using namespace std;

EasingCurve::EasingCurve(
    unique_ptr<EasingCurveFunction> function,
    int xt0,
    int xtmax,
    float duration)
    : function_{ move(function) }
    , xt0_{xt0}
    , xtmax_{xtmax}
    , duration_{duration}
{
}

EasingCurve::EasingCurve(const EasingCurve& other)
    : xt0_{other.xt0_}
    , xtmax_{other.xtmax_}
    , duration_{other.duration_}
{
    if (other.function_)
        function_ = other.function_->clone();
}

EasingCurve& EasingCurve::operator=(const EasingCurve & other)
{
    if (other.function_)
        function_ = other.function_->clone();
    xt0_ = other.xt0_;
    xtmax_ = other.xtmax_;
    duration_ = other.duration_;
    
    return *this;
}

float EasingCurve::apply(float progress) const
{
    if (!function_)
        return 0.0f;

    const auto& f = *function_;
    return xt0_ +  f(progress / duration_) * (xtmax_ - xt0_);
}

void EasingCurve::setFunction(unique_ptr<EasingCurveFunction> function)
{
    function_ = move(function);
}

void EasingCurve::setParams(int xt0, int xtmax, float duration)
{
    xt0_ = xt0;
    xtmax_ = xtmax;
    duration_ = duration;
}

bool EasingCurve::isValid() const
{
    return static_cast<bool>(function_);
}
