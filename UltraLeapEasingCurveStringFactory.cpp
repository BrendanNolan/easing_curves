#include "UltraLeapEasingCurveStringFactory.h"

#include <algorithm>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "LinearEasingCurveFunction.h"
#include "InOutQuadEasingCurveFunction.h"
#include "InQuadEasingCurveFunction.h"
#include "OutQuadEasingCurveFunction.h"

using namespace std;

namespace
{
void removeSpaces(string& s);
bool startsWith(const std::string& target, const std::string& query);
float getFloatFollowing(
    const std::string& target, 
    const std::string& preceedingFloat,
    bool& ok);
int getIntFollowing(
    const std::string& target,
    const std::string& preceedingInt,
    bool& ok);
}

EasingCurve UltraLeapEasingCurveStringFactory::create(
    const std::string& stringToParse)
{
    failed_ = false;

    auto cpy = stringToParse;
    removeSpaces(cpy);

    stringstream s;
    s << cpy;

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
        return EasingCurve{
            make_unique<LinearEasingCurveFunction>(
                xt0,
                xtmax,
                duration)};
    }
    else if (firstComponent == "InQuad")
    {
        return EasingCurve{
            make_unique<InQuadEasingCurveFunction>(
                xt0,
                xtmax,
                duration)};
    }
    else if (firstComponent == "OutQuad")
    {
        return EasingCurve{
            make_unique<OutQuadEasingCurveFunction>(
                xt0,
                xtmax,
                duration)};
    }
    else if (firstComponent == "InOutQuad")
    {
        return EasingCurve{
            make_unique<InOutQuadEasingCurveFunction>(
                xt0,
                xtmax,
                duration)};
    }
    else
    {
        return {};
    }
}

int UltraLeapEasingCurveStringFactory::parseXt0(const std::string& s)
{
    auto ok = false;
    const auto i = getIntFollowing(s, "x_t0=", ok);
    if (!ok)
    {
        failed_ = true;
        return 0;
    }
    return i;
}

int UltraLeapEasingCurveStringFactory::parseXtmax(const std::string & s)
{
    auto ok = false;
    const auto i = getIntFollowing(s, "x_tmax=", ok);
    if (!ok)
    {
        failed_ = true;
        return 0;
    }
    return i;
}

float UltraLeapEasingCurveStringFactory::parseDuration(const std::string & s)
{
    auto ok = false;
    const auto f = getFloatFollowing(s, "duration=", ok);
    if (!ok)
    {
        failed_ = true;
        return 0;
    }
    return f;
}

namespace
{
void removeSpaces(string& s)
{
    s.erase(
        remove_if(
            s.begin(),
            s.end(),
            [](char c) { return isspace(c); }),
        s.end());
}

bool startsWith(const std::string& target, const std::string& query)
{
    return target.substr(0, query.size()) == query;
}

float getFloatFollowing(
    const std::string& target,
    const std::string& preceedingFloat,
    bool& ok)
{
    if (!startsWith(target, preceedingFloat))
    {
        ok = false;
        return 0.0f;
    }

    try
    {
        const auto f = stof(target.substr(preceedingFloat.size()));
        ok = true;
        return f;
    }
    catch (const invalid_argument& )
    {
        ok = false;
        return 0.0f;
    }
}

int getIntFollowing(
    const std::string& target,
    const std::string& preceedingInt,
    bool& ok)
{
    const auto f = getFloatFollowing(target, preceedingInt, ok);
    if (!ok || (ceil(f) != f))
    {
        ok = false;
        return 0;
    }
    return static_cast<int>(f);
}
}
