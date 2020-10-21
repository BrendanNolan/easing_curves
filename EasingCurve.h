#ifndef EASING_CURVE_H
#define EASING_CURVE_H

#include <memory>

#include "EasingCurveFunction.h"

class EasingCurve
{
public:
    EasingCurve() = default;
    EasingCurve(
        std::unique_ptr<EasingCurveFunction> function,
        int xt0,
        int xtmax,
        float duration);
    EasingCurve(const EasingCurve& other);
    EasingCurve& operator=(const EasingCurve& other);

    // Will produce nonsense if isValid() == false
    float apply(float progress) const; 
    
    void setFunction(std::unique_ptr<EasingCurveFunction> function);
    void setParams(
        int xt0,
        int xtmax,
        float duration);

    bool isValid() const;

private:
    std::unique_ptr<EasingCurveFunction> function_;

    int xt0_ = 0;
    int xtmax_ = 0;
    float duration_ = 0.0f;
};

#endif // EASING_CURVE_H
