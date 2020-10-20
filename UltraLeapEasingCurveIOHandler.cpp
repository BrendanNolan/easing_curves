#include "UltraLeapEasingCurveIOHandler.h"

#include <stdexcept>
#include <string>
#include <utility>

#include "EasingCurveStringFactory.h"

using namespace std;

UltraLeapEasingCurveIOHandler::UltraLeapEasingCurveIOHandler(
    std::istream& inStream,
    std::ostream& outStream,
    std::shared_ptr<EasingCurveStringFactory> factory)
    : inStream_{ &inStream }
    , outStream_{ &outStream }
    , factory_{ move(factory) }
{
}

void UltraLeapEasingCurveIOHandler::run()
{
    if (!inStream_ || !outStream_ || !factory_)
        return;

    auto& in = *inStream_;
    auto& out = *outStream_;
    while (!in.eof())
    {
        const auto line = readNextValidLine();
        if (!curve_.isValid())
            return;
        if (curveApplyPending_)
            out << curve_.apply(stof(line));
        else
            out << line;
    }
}

string UltraLeapEasingCurveIOHandler::readNextValidLine()
{
    string line;
    while (!(inStream_->eof()))
    {
        if (!*inStream_)
        {
            inStream_->clear();
            continue;
        }
        
        getline(*inStream_, line);
        
        try
        {
            stof(line);
            curveApplyPending_ = true;
            return line;
        }
        catch (const invalid_argument&)
        {
            auto curve = factory_->create(line);
            if (!curve.isValid())
                continue;
            curve_ = curve;
            curveApplyPending_ = false;
            return line;
        }
    }
    return {};
}
