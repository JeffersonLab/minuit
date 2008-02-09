// @(#)root/minuit2:$Name:  $:$Id: ScanMinimizer.h,v 1.1.1.1 2008/02/09 21:56:12 edwards Exp $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef ROOT_Minuit2_ScanMinimizer
#define ROOT_Minuit2_ScanMinimizer

#include "Minuit2/MnConfig.h"
#include "Minuit2/ModularFunctionMinimizer.h"
#include "Minuit2/ScanBuilder.h"
#include "Minuit2/SimplexSeedGenerator.h"

#include <vector>

namespace ROOT {

   namespace Minuit2 {


class ScanMinimizer : public ModularFunctionMinimizer {

public:

  ScanMinimizer() : fSeedGenerator(SimplexSeedGenerator()), 
		    fBuilder(ScanBuilder()) {}
  
  ~ScanMinimizer() {}
  
  const MinimumSeedGenerator& SeedGenerator() const {return fSeedGenerator;}
  const MinimumBuilder& Builder() const {return fBuilder;}
  
private:
  
  SimplexSeedGenerator fSeedGenerator;
  ScanBuilder fBuilder;
};

  }  // namespace Minuit2

}  // namespace ROOT

#endif  // ROOT_Minuit2_ScanMinimizer
