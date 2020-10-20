#include "UltraLeapEasingCurveStringFactory.h"

#include <memory>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "LinearEasingCurveFunction.h"
#include "InOutQuadEasingCurveFunction.h"
#include "InQuadEasingCurveFunction.h"
#include "OutQuadEasingCurveFunction.h"

using namespace std;

EasingCurve UltraLeapEasingCurveStringFactory::create(
    const std::string& stringToParse)
{
    failed_ = false;

    stringstream s;
    s << stringToParse;

    vector<string> components{4};
    for (auto i = 0u; i < 4; ++i)
    {
        if (s.eof())
            return {};
        getline(s, components[i]);
    }
    if (!s.eof())
        return {};

    const auto xt0 = parseXt0(components[1]);
    const auto xtmax = parseXtmax(components[2]);
    const auto duration = parseDuration(components[3]);
    if (failed_)
        return {};

    const auto& firstComponent = components[0];
    if (firstComponent == "Linear")
    {
        return EasingCurve(
            make_unique<LinearEasingCurveFunction>(
                xt0, 
                xtmax,
                duration));
    }
    else if (firstComponent == "InQuad")
    {
        return EasingCurve(
            make_unique<InQuadEasingCurveFunction>(
                xt0,
                xtmax,
                duration));
    }
    else if (firstComponent == "OutQuad")
    {
        return EasingCurve(
            make_unique<OutQuadEasingCurveFunction>(
                xt0,
                xtmax,
                duration));
    }
    else if (firstComponent == "InOutQuad")
    {
        return EasingCurve(
            make_unique<InOutQuadEasingCurveFunction>(
                xt0,
                xtmax,
                duration));
    }
    else
        return {};
}

int UltraLeapEasingCurveStringFactory::parseXt0(const std::string & s)
{
    const auto beginning = s.substr(0, 5);
    if (beginning != "x_t0=")
    {
        failed_ = true;
        return 0;
    }
    const auto value = s.substr(5);
    try
    {
        return stoi(value);
    }
    catch (const invalid_argument&)
    {
        failed_ = true;
        return 0;
    }
}

int UltraLeapEasingCurveStringFactory::parseXtmax(const std::string & s)
{
    const auto beginning = s.substr(0, 7);
    if (beginning != "x_tmax=")
    {
        failed_ = true;
        return 0;
    }
    const auto value = s.substr(7);
    try
    {
        return stoi(value);
    }
    catch (const invalid_argument&)
    {
        failed_ = true;
        return 0;
    }
}

float UltraLeapEasingCurveStringFactory::parseDuration(const std::string & s)
{
    const auto beginning = s.substr(0, 9);
    if (beginning != "duration=")
    {
        failed_ = true;
        return 0;
    }
    const auto value = s.substr(9);
    try
    {
        return stof(value);
    }
    catch (const invalid_argument&)
    {
        failed_ = true;
        return 0;
    }
}
