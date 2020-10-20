#ifndef EASING_CURVE_H
#define EASING_CURVE_H

#include <memory>

class EasingCurveFunction;

class EasingCurve
{
    explicit EasingCurve(std::unique_ptr<EasingCurveFunction> function);
    ~EasingCurve();

    float apply(float progress) const; // Will throw if isValid() == false
    
    void setFunction(std::unique_ptr<EasingCurveFunction> function);

    bool isValid() const;

private:
    std::unique_ptr<EasingCurveFunction> function_;
};

#endif // EASING_CURVE_H
