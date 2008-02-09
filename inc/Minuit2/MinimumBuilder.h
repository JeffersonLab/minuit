// @(#)root/minuit2:$Name:  $:$Id: MinimumBuilder.h,v 1.1.1.1 2008/02/09 21:56:12 edwards Exp $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef ROOT_Minuit2_MinimumBuilder
#define ROOT_Minuit2_MinimumBuilder

namespace ROOT {

   namespace Minuit2 {


class FunctionMinimum;
class MnFcn;
class GradientCalculator;
class MinimumSeed;
class MnStrategy;

class MinimumBuilder {

public:
  
  virtual ~MinimumBuilder() {}

  virtual FunctionMinimum Minimum(const MnFcn&, const GradientCalculator&, const MinimumSeed&, const MnStrategy&, unsigned int, double) const = 0;

};

  }  // namespace Minuit2

}  // namespace ROOT

#endif  // ROOT_Minuit2_MinimumBuilder
