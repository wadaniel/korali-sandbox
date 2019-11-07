#include "model.hpp"
#include "mvf.h"

void kAckley(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    s["Evaluation"] = mvfAckley ( (int) params.size(), params.data());
}

void kSphere(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    s["Evaluation"] = mvfSphere ( (int) params.size(), params.data());
}

void kBeale(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    s["Evaluation"] = mvfBeale ( (int) params.size(), params.data());
}

void kBohachevsky1(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    s["Evaluation"] = mvfBohachevsky1 ((int) params.size(), params.data());
}

void kBooth(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    s["Evaluation"] = mvfBooth ((int) params.size(), params.data());
}

void kCamel(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    s["Evaluation"] = mvfCamel3 ((int) params.size(), params.data());
}


void kLevy(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    s["Evaluation"] = mvfLevy ((int) params.size(), params.data());
}
