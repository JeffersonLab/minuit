// @(#)root/minuit2:$Name:  $:$Id: VariableMetricBuilder.h,v 1.1.1.1 2008/02/09 21:56:13 edwards Exp $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef ROOT_Minuit2_VariableMetricBuilder
#define ROOT_Minuit2_VariableMetricBuilder

#include "Minuit2/MnConfig.h"
#include "Minuit2/MinimumBuilder.h"
#include "Minuit2/VariableMetricEDMEstimator.h"
#include "Minuit2/DavidonErrorUpdator.h"

#include <vector>

namespace ROOT {

   namespace Minuit2 {

/**
   Build (find) function minimum using the Variable Metric method (MIGRAD) 
 */
class VariableMetricBuilder : public MinimumBuilder {

public:

  VariableMetricBuilder() : fEstimator(VariableMetricEDMEstimator()), 
			    fErrorUpdator(DavidonErrorUpdator()) {}

  ~VariableMetricBuilder() {}

  virtual FunctionMinimum Minimum(const MnFcn&, const GradientCalculator&, const MinimumSeed&, const MnStrategy&, unsigned int, double) const;

  FunctionMinimum Minimum(const MnFcn&, const GradientCalculator&, const MinimumSeed&, std::vector<MinimumState> &, unsigned int, double) const;

  const VariableMetricEDMEstimator& Estimator() const {return fEstimator;}
  const DavidonErrorUpdator& ErrorUpdator() const {return fErrorUpdator;}

private:

  VariableMetricEDMEstimator fEstimator;
  DavidonErrorUpdator fErrorUpdator;
};

  }  // namespace Minuit2

}  // namespace ROOT

#endif  // ROOT_Minuit2_VariableMetricBuilder
