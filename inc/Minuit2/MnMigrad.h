// @(#)root/minuit2:$Name:  $:$Id: MnMigrad.h,v 1.1 2008/02/09 21:56:12 edwards Exp $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef ROOT_Minuit2_MnMigrad
#define ROOT_Minuit2_MnMigrad

#include "Minuit2/MnApplication.h"
#include "Minuit2/VariableMetricMinimizer.h"

namespace ROOT {

   namespace Minuit2 {


class FCNBase;

/** API class for minimization using Variable Metric technology ("MIGRAD");
    allows for user interaction: set/change parameters, do minimization,
    change parameters, re-do minimization etc.; 
    also used by MnMinos and MnContours;
 */

class MnMigrad : public MnApplication {

public:

  /// construct from FCNBase + std::vector for parameters and errors
  MnMigrad(const FCNBase& fcn, const std::vector<double>& par, const std::vector<double>& err, unsigned int stra = 1) : MnApplication(fcn, MnUserParameterState(par,err), MnStrategy(stra)), fMinimizer(VariableMetricMinimizer()) {}

  /// construct from FCNBase + std::vector for parameters and covariance
  MnMigrad(const FCNBase& fcn, const std::vector<double>& par, const std::vector<double>& cov, unsigned int nrow, unsigned int stra = 1) : MnApplication(fcn, MnUserParameterState(par, cov, nrow), MnStrategy(stra)), fMinimizer(VariableMetricMinimizer()) {}

  /// construct from FCNBase + std::vector for parameters and MnUserCovariance
  MnMigrad(const FCNBase& fcn, const std::vector<double>& par, const MnUserCovariance& cov, unsigned int stra = 1) : MnApplication(fcn, MnUserParameterState(par, cov), MnStrategy(stra)), fMinimizer(VariableMetricMinimizer()) {}

  /// construct from FCNBase + MnUserParameters
  MnMigrad(const FCNBase& fcn, const MnUserParameters& par, unsigned int stra = 1) : MnApplication(fcn, MnUserParameterState(par), MnStrategy(stra)), fMinimizer(VariableMetricMinimizer()) {}

  /// construct from FCNBase + MnUserParameters + MnUserCovariance
  MnMigrad(const FCNBase& fcn, const MnUserParameters& par, const MnUserCovariance& cov, unsigned int stra = 1) : MnApplication(fcn, MnUserParameterState(par, cov), MnStrategy(stra)), fMinimizer(VariableMetricMinimizer()) {}

  /// construct from FCNBase + MnUserParameterState + MnStrategy
  MnMigrad(const FCNBase& fcn, const MnUserParameterState& par, const MnStrategy& str) : MnApplication(fcn, MnUserParameterState(par), str), fMinimizer(VariableMetricMinimizer()) {}

  MnMigrad(const MnMigrad& migr) : MnApplication(migr.Fcnbase(), migr.State(), migr.Strategy(), migr.NumOfCalls()), fMinimizer(migr.fMinimizer) {}  

  ~MnMigrad() {}

  const ModularFunctionMinimizer& Minimizer() const {return fMinimizer;}

private:

  VariableMetricMinimizer fMinimizer;

private:

  //forbidden assignment of migrad (const FCNBase& = )
  MnMigrad& operator=(const MnMigrad&) {return *this;}
};

  }  // namespace Minuit2

}  // namespace ROOT

#endif  // ROOT_Minuit2_MnMigrad
