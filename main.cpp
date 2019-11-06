#include <stdio.h>

#include "korali.hpp"
#include "model/model.hpp"
#include "suite/testsuite.h"

using namespace Suite;

int main(int, char**)
{

  auto t = TestSuite(10, 1e-4); 
  
  t.addFactory("Linear", new CMAESFactory("Linear"));
  t.addFactory("Logarithmic", new CMAESFactory("Logarithmic"));
  t.addFactory("Equal", new CMAESFactory("Equal"));
  //t.addFactory("DE Self Adaptive", new DEFactory("Best", "Self Adaptive", "Greedy"));
  //t.addFactory("DE Default", new DEFactory("Best", "Default", "Greedy"));

  
  t.addTestFunction("Ackley2",  kAckley,  2, -30.0, 30.0, 0.0, 100000);
  t.addTestFunction("Ackley16", kAckley, 16, -30.0, 30.0, 0.0, 100000);
  //t.addTestFunction("Rosenbrock2", &mvfRosenbrock, 2, -30.0, 30.0, 0.0, 100000);
  //t.addTestFunction("Rosenbrock16", &mvfRosenbrock, 16, -30.0, 30.0, 0.0, 100000);
  //t.addTestFunction("Sphere", &mvfSphere, 2, -10.0, 10.0, 0.0, 100000);
  //t.addTestFunction("Sphere2", &mvfSphere2, 2, -10.0, 10.0, 0.0, 100000);
  //t.addTestFunction("Beale", &mvfBeale, 2, -4.5, 4.5, 0.0, 100000);
  //t.addTestFunction("Bohachevsky1", &mvfBohachevsky1, 2, -50.0, 50.0, 0.0, 100000);
  //t.addTestFunction("Booth", &mvfBooth, 2, -10.0, 10.0, 0.0, 100000);
  //t.addTestFunction("Camel3", &mvfCamel3, 2, -50.0, 50.0, 0.0, 100000);
  //t.addTestFunction("Levy", &mvfLevy, 4, -50.0, 50.0, -21.502356, 100000);

  t.run();
  t.makeStatistics();

  return 0;
}

