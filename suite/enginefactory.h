#ifndef _ENGINE_FACTORY_H_
#define _ENGINE_FACTORY_H_

#include "korali.hpp"

namespace Suite
{


class EngineFactory
{

public:
  EngineFactory() {};
  ~EngineFactory() {};

  virtual korali::Engine createEngine(size_t dim, double lowerbound, double upperbound, size_t maxEval, double targetFitness ) = 0;

};

class CMAESFactory : public EngineFactory
{
public:
  CMAESFactory(std::string muType) : EngineFactory(), _muType(muType) {};
  ~CMAESFactory() {};
  korali::Engine createEngine(size_t dim, double lowerbound, double upperbound, size_t maxEval, double targetFitness );

private:
  std::string _muType;
};


class LMCMAFactory : public EngineFactory
{
public:
  LMCMAFactory(std::string muType, size_t memory = 0, size_t interval = 0) : EngineFactory(), _muType(muType), _memory(memory), _interval(interval) {};
  ~LMCMAFactory() {};
  korali::Engine createEngine(size_t dim, double lowerbound, double upperbound, size_t maxEval, double targetFitness );

private:
  std::string _muType;
  size_t _memory;
  size_t _interval;
};


class DEFactory : public EngineFactory
{
public:
  DEFactory(std::string parent, std::string mutationrule, std::string acceptrule) : EngineFactory (),
    _parent(parent),
    _mutationRule(mutationrule),
    _acceptRule(acceptrule) {}

  ~DEFactory() {};
  korali::Engine createEngine(size_t dim, double lowerbound, double upperbound, size_t maxEval, double targetFitness );

private:
  std::string _parent;
  std::string _mutationRule;
  std::string _acceptRule;
};


} // namespace Suite

#endif // _ENGINE_FACTORY_H_
