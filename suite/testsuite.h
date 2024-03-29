#ifndef _KORALI_TESTSUITE_H_
#define _KORALI_TESTSUITE_H_

#include <map>
#include <vector>
#include <string>
#include <functional>

#include "korali.hpp"
#include "enginefactory.h"

namespace Suite
{

typedef void (&TestFunRef) (korali::Sample&);

class TestSuite
{

public:

  TestSuite(size_t rep, double prec);
  ~TestSuite();

  void run();
  void addFactory(std::string name, EngineFactory* facPtr);
  void addTestFunction(std::string name, TestFunRef fref, size_t dim, double lowerBound, double upperBound, double fitness, size_t numFunEval);
  void addTargetFitness(std::string name, double fitness );
  void addMaxFunctionEvaluations(std::string, size_t numFunEval);
  void makeStatistics();

private:

  std::vector<std::pair<std::string,EngineFactory*>> _factories;

  size_t _repetitions;
  double _precision;

  std::vector<std::pair<std::string, TestFunRef>> _functions;
  std::map<std::string, size_t> _dimMap;
  std::map<std::string, std::pair<double, double>> _domainMap;
  std::map<std::string, double> _fitnessMap;
  std::map<std::string, size_t> _maxModelEvals;
  std::map<std::string, std::map<std::string, std::vector<size_t>>> _evalsCount;
  std::map<std::string, std::map<std::string, size_t>> _successCount;

};

} // namespace Suite

#endif // _KORALI_TESTSUITE_H_
