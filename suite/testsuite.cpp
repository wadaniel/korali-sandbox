#include "testsuite.h"

#include <stdio.h>
#include <algorithm>

namespace Suite
{

TestSuite::TestSuite(size_t rep, double prec) : _repetitions(rep), _precision(prec) { };

TestSuite::~TestSuite() {};

void TestSuite::run()
{

  for(auto func : _functions)
  {

    std::string funcname = func.first;

    std::map<std::string, std::vector<size_t>> evals;
   
    for(auto factory : _factories)
    {
    std::vector<size_t> evec;
 
    std::string fname = factory.first;
    
    for(size_t rep = 0; rep < _repetitions; ++rep)
    {

        auto k = factory.second->createEngine(_dimMap[funcname], _domainMap[funcname].first, _domainMap[funcname].second, _maxModelEvals[funcname], _fitnessMap[funcname] + _precision);

        k["Problem"]["Objective Function"] = &func.second;

        printf("\n\nRun Test: %s\nRepetition %zu\nName: %s\n\n", funcname.c_str(), rep, fname.c_str());

        k.runSingle();
        size_t eval = k["Solver"]["Internal"]["Model Evaluation Count"];
        evec.push_back(eval);
    }

    
    evals.insert(std::pair<std::string, std::vector<size_t>>(fname, evec));
   }
    _evalsCount.insert(std::pair<std::string, std::map<std::string, std::vector<size_t>>>(funcname, evals));
  }
}


void TestSuite::addFactory(std::string name, EngineFactory* factoryPtr)
{
  _factories.push_back(std::pair<std::string, EngineFactory*>(name, factoryPtr));
}


void TestSuite::addTestFunction(std::string name, TestFunRef fref, size_t dim, double lowerBound, double upperBound, double fitness, size_t numFunEval )
{
  _functions.push_back( std::pair<std::string, TestFunRef> (name, fref) );

  _dimMap.insert( std::pair<std::string, size_t>(name, dim) );

  std::pair<double, double> domain(lowerBound, upperBound);
  _domainMap.insert( std::pair<std::string, std::pair<double, double> > (name, domain ) );

  _fitnessMap.insert( std::pair<std::string, double>(name, fitness) );

  _maxModelEvals.insert( std::pair<std::string, size_t>(name, numFunEval) );
}

void TestSuite::addTargetFitness(std::string name, double fitness)
{
  _fitnessMap.insert( std::pair<std::string, double>(name, fitness) );
}


void TestSuite::addMaxFunctionEvaluations(std::string name, size_t numFunEval)
{
  _maxModelEvals.insert( std::pair<std::string, size_t>(name, numFunEval) );
}

void TestSuite::makeStatistics() 
{
  for(auto func : _functions)
  {
    std::map<std::string, std::vector<size_t>> funcres = _evalsCount[func.first];
    for(auto fac : _factories)
    {
        std::vector<size_t> facres = funcres[fac.first];
        
        size_t len = facres.size();

        sort(std::begin(facres), std::end(facres)); 
        size_t min = *std::begin(facres);
        size_t max = *(std::end(facres)-1);
        size_t med;

        if(len % 2 == false) med = facres[len/2];
        else                 med = (facres[(len-1)/2] + facres[len/2])/2.0;  

        double sum  = 0;
        double sum2 = 0;
        for(size_t i = 0; i < len; ++i)
        {
            sum  += facres[i];
            sum2 += (facres[i]*facres[i]);
        }

        double avg = sum/len;
        double std = std::sqrt(sum2/len - sum*sum/(len*len));
        
        printf("| FUNCTION  %-25s  | SOLVER  %-25s | MIN  %5zu | MAX %5zu | MED %5zu | AVG %6.1f | STD %6.1f \n", func.first.c_str(), fac.first.c_str(), min, max, med, avg, std);
    }
  }

}

} // namespace Suite
