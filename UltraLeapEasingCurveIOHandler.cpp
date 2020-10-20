#include "UltraLeapEasingCurveIOHandler.h"

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
    while (in && out && !in.eof())
    {

    }
}
