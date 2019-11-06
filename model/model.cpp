#include "model.hpp"
#include "mvf.h"

void kAckley(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    s["Evaluation"] = mvfAckley ( (int) params.size(), params.data());
}
