#include "model.hpp"
#include "mvf.h"

void kAckley(korali::Sample& s)
{
    std::vector<double> params = s["Parameters"];
    double eval = mvfAckley ( (int) params.size(), params.data());
    printf("eval: %lf\n", eval);
    s["Evaluation"] = mvfAckley ( (int) params.size(), params.data());
}
