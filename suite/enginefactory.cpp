#include "enginefactory.h"

namespace Suite
{

korali::Engine CMAESFactory::createEngine(size_t dim, double lowerbound, double upperbound, size_t maxEval, double targetFitness )
{


    auto k = korali::Engine();

    // Configuring Problem.
    k["Problem"]["Type"] = "Evaluation/Direct/Basic";
    k["Problem"]["Objective"] = "Maximize";

    // Defining the problem's variables.
    k["Variables"][0]["Name"] = "X";
    k["Variables"][0]["Lower Bound"] = -10.0;
    k["Variables"][0]["Upper Bound"] = +10.0;

    // Configuring CMA-ES parameters
    k["Solver"]["Type"] = "Optimizer/CMAES";
    k["Solver"]["Population Size"] = 32;
    k["Solver"]["Termination Criteria"]["Min Value Difference Threshold"] = 1e-7;
    k["Solver"]["Termination Criteria"]["Max Generations"] = 100;


  /*
  auto k = korali::Engine();

  k["Problem"]["Type"] = "Evaluation/Direct/Basic";
  k["Problem"]["Objective"] = "Minimize";
  printf("..\n");
  k["Solver"]["Type"] = "Optimizer/CMAES";
  //k["Solver"]["Result Output"]["Frequency"] = 0;
  k["Solver"]["Population Size"] = 32; //size_t(4+3*log(dim));
  printf("..\n");
  //k["Solver"]["Mu Type"]  = _muType;

  for (int i = 0; i < dim; i++)
  {
    //k["Variables"][i]["Name"] = "X" + std::to_string(i);
    k["Variables"][i]["Lower Bound"] = lowerbound;
    k["Variables"][i]["Upper Bound"] = upperbound;
  }
  printf("..\n");
  */
  //k["Conduit"]["Termination Criteria"]["Max Model Evaluations"] = maxEval;
  //k["Solver"]["Termination Criteria"]["Value"] = targetFitness;
  return k;
}

korali::Engine DEFactory::createEngine(size_t dim, double lowerbound, double upperbound, size_t maxEval, double targetFitness )
{
  auto k = korali::Engine();
  
  k["Problem"]["Type"] = "Evaluation/Direct/Basic";
  k["Problem"]["Objective"] = "Minimize";
  
  k["Solver"]["Type"] = "Optimizer/DEA";
  //k["Solver"]["Result Output"]["Frequency"] = 0;
  k["Solver"]["Population Size"] = 10*dim;
  //k["Solver"]["Parent Selection Rule"] = _parent;
  //k["Solver"]["Mutation Rule"] = _mutationRule;
  //k["Solver"]["Accept Rule"] = _acceptRule;

  for (int i = 0; i < dim; i++)
  {
    k["Variables"][i]["Name"] = "X" + std::to_string(i);
    k["Variables"][i]["Lower Bound"] = lowerbound;
    k["Variables"][i]["Upper Bound"] = upperbound;
  }
  
  //k["Conduit"]["Termination Criteria"]["Max Model Evaluations"] = maxEval;
  //k["Solver"]["Termination Criteria"]["Value"] = targetFitness;
  return k;
}

} // namepsace Suite
