#include <stdio.h>

#include "korali.hpp"
#include "model/model.hpp"
#include "suite/testsuite.h"

using namespace Suite;

int main(int, char**)
{

  auto t = TestSuite(10, 1e-3); 
  
  //t.addFactory("CMAES Linear", new CMAESFactory("Linear"));
  t.addFactory("LMCMA Normal", new LMCMAFactory("Linear","Normal"));
  t.addFactory("LMCMA Uniform", new LMCMAFactory("Linear","Uniform"));
  //t.addFactory("DE Default", new DEFactory("Best", "Default", "Greedy"));

  
  t.addTestFunction("Sphere2", kSphere,   2, -10.0, 10.0, 0.0, 1e5);
  t.addTestFunction("Sphere16", kSphere, 16, -10.0, 10.0, 0.0, 1e5);
  t.addTestFunction("Sphere32", kSphere, 32, -10.0, 10.0, 0.0, 1e5);
  t.addTestFunction("Ackley2",  kAckley,  2, -30.0, 30.0, 0.0, 1e5);
  t.addTestFunction("Ackley16", kAckley, 16, -30.0, 30.0, 0.0, 1e5);
  t.addTestFunction("Ackley32", kAckley, 32, -30.0, 30.0, 0.0, 1e5);
  //t.addTestFunction("Rosenbrock2", kRosenbrock, 2, -30.0, 30.0, 0.0, 10000);
  //t.addTestFunction("Rosenbrock16", &mvfRosenbrock, 16, -30.0, 30.0, 0.0, 100000);
  t.addTestFunction("Beale", kBeale, 2, -4.5, 4.5, 0.0, 100000);
  t.addTestFunction("Bohachevsky", kBohachevsky1, 2, -50.0, 50.0, 0.0, 100000);
  //t.addTestFunction("Booth", &mvfBooth, 2, -10.0, 10.0, 0.0, 100000);
  //t.addTestFunction("Camel3", &mvfCamel3, 2, -50.0, 50.0, 0.0, 100000);
  //t.addTestFunction("Levy", &mvfLevy, 4, -50.0, 50.0, -21.502356, 100000);

  t.run();
  t.makeStatistics();

  return 0;
}

