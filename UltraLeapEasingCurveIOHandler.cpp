#include "UltraLeapEasingCurveIOHandler.h"

UltraLeapEasingCurveIOHandler::UltraLeapEasingCurveIOHandler(
    std::istream& inStream,
    std::ostream& outStream)
    : inStream_{ &inStream }
    , outStream_{ &outStream }
{
}
