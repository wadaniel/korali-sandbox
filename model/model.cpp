#include "model.hpp"
#include "mvf.h"

void kAckley(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    s["Evaluation"] = mvfAckley ( (int) params.size(), params.data());
}

void kRosenbrock(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    s["Evaluation"] = mvfRosenbrock ( (int) params.size(), params.data());
}

void kSphere(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    s["Evaluation"] = mvfSphere ( (int) params.size(), params.data());
}
