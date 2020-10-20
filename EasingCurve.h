#ifndef EASING_CURVE_H
#define EASING_CURVE_H

#include <memory>

#include "EasingCurveFunction.h"

class EasingCurve
{
public:
    EasingCurve() = default;
    explicit EasingCurve(std::unique_ptr<EasingCurveFunction> function);
    EasingCurve(const EasingCurve& other);
    EasingCurve& operator=(const EasingCurve& other);

    float apply(float progress) const; // Will throw if isValid() == false
    
    void setFunction(std::unique_ptr<EasingCurveFunction> function);

    bool isValid() const;

private:
    std::unique_ptr<EasingCurveFunction> function_;
};

#endif // EASING_CURVE_H
