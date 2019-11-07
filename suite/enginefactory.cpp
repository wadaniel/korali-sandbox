#include "enginefactory.h"

namespace Suite
{

korali::Engine CMAESFactory::createEngine(size_t dim, double lowerbound, double upperbound, size_t maxEval, double targetFitness )
{
  auto k = korali::Engine();

  k["Problem"]["Type"]           = "Evaluation/Direct/Basic";
  k["Problem"]["Objective"]      = "Minimize";
  k["Solver"]["Type"]            = "Optimizer/CMAES";
  k["Solver"]["Population Size"] = size_t(4+3*log(dim));
  k["Solver"]["Mu Type"]         = _muType;

  for (int i = 0; i < dim; i++)
  {
    k["Variables"][i]["Name"] = "X" + std::to_string(i);
    k["Variables"][i]["Lower Bound"] = lowerbound;
    k["Variables"][i]["Upper Bound"] = upperbound;
  }
  
  k["Solver"]["Termination Criteria"]["Min Value"] = targetFitness;
  k["Solver"]["Termination Criteria"]["Max Generations"] = 99999999;
  k["Conduit"]["Termination Criteria"]["Max Model Evaluations"] = maxEval;
  k["Results Output"]["Active"] = 0;
  k["Console Output"]["Frequency"] = 0;
  k["Console Output"]["Verbosity"] = "Minimal";
  
  return k;
}


korali::Engine LMCMAFactory::createEngine(size_t dim, double lowerbound, double upperbound, size_t maxEval, double targetFitness )
{
  auto k = korali::Engine();

  k["Problem"]["Type"]           = "Evaluation/Direct/Basic";
  k["Problem"]["Objective"]      = "Minimize";
  k["Solver"]["Type"]            = "Optimizer/LMCMAES";
  k["Solver"]["Population Size"] = size_t(4+3*log(dim));
  k["Solver"]["Mu Type"]         = _muType;
  
  if(_memory > 0)   k["Solver"]["Subset Size"]         = _memory;
  if(_interval > 0) k["Solver"]["Set Update Interval"] = _interval;

  for (int i = 0; i < dim; i++)
  {
    k["Variables"][i]["Name"] = "X" + std::to_string(i);
    k["Variables"][i]["Lower Bound"] = lowerbound;
    k["Variables"][i]["Upper Bound"] = upperbound;
  }
  
  k["Solver"]["Termination Criteria"]["Min Value"] = targetFitness;
  k["Solver"]["Termination Criteria"]["Max Generations"] = 99999999;
  k["Conduit"]["Termination Criteria"]["Max Model Evaluations"] = maxEval;
  k["Results Output"]["Active"] = 0;
  k["Console Output"]["Frequency"] = 1;
  k["Console Output"]["Verbosity"] = "Normal";
  
  return k;
}


korali::Engine DEFactory::createEngine(size_t dim, double lowerbound, double upperbound, size_t maxEval, double targetFitness )
{
  auto k = korali::Engine();
  
  k["Problem"]["Type"] = "Evaluation/Direct/Basic";
  k["Problem"]["Objective"] = "Minimize";
  
  k["Solver"]["Type"] = "Optimizer/DEA";
  k["Solver"]["Population Size"] = 10*dim;
  k["Solver"]["Parent Selection Rule"] = _parent;
  k["Solver"]["Mutation Rule"] = _mutationRule;
  k["Solver"]["Accept Rule"] = _acceptRule;

  for (int i = 0; i < dim; i++)
  {
    k["Variables"][i]["Name"] = "X" + std::to_string(i);
    k["Variables"][i]["Lower Bound"] = lowerbound;
    k["Variables"][i]["Upper Bound"] = upperbound;
  }
  
  k["Solver"]["Termination Criteria"]["Min Value"] = targetFitness;
  k["Solver"]["Termination Criteria"]["Max Generations"] = 99999999;
  k["Conduit"]["Termination Criteria"]["Max Model Evaluations"] = maxEval;
  k["Results Output"]["Active"] = false;
  k["Console Output"]["Frequency"] = 10;
  k["Console Output"]["Verbosity"] = "Minimal";
  
  return k;
}

} // namepsace Suite
