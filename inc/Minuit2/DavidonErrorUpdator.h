// @(#)root/minuit2:$Name:  $:$Id: DavidonErrorUpdator.h,v 1.1.1.1 2008/02/09 21:56:11 edwards Exp $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef ROOT_Minuit2_DavidonErrorUpdator
#define ROOT_Minuit2_DavidonErrorUpdator

#ifndef ROOT_Minuit2_MinimumErrorUpdator
#include "Minuit2/MinimumErrorUpdator.h"
#endif

namespace ROOT {

   namespace Minuit2 {


/**
   Update of the covariance matrix for the Variable Metric minimizer (MIGRAD)
 */
class DavidonErrorUpdator : public MinimumErrorUpdator {

public:

  DavidonErrorUpdator() {}
  
  virtual ~DavidonErrorUpdator() {}

  virtual MinimumError Update(const MinimumState&, const MinimumParameters&,
			      const FunctionGradient&) const;

private:

};

  }  // namespace Minuit2

}  // namespace ROOT

#endif  // ROOT_Minuit2_DavidonErrorUpdator
