// @(#)root/minuit2:$Name:  $:$Id: FlatRandomGen.h,v 1.2 2008/10/20 17:57:02 edwards Exp $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MN_FlatRandomGen_H_
#define MN_FlatRandomGen_H_

#include <cmath>

namespace ROOT {

   namespace Minuit2 {


class FlatRandomGen {

public:

  FlatRandomGen() : fMean(0.5), fDelta(0.5) {}

  FlatRandomGen(double mean, double delta) : fMean(mean), fDelta(delta) {}

  ~FlatRandomGen() {}

  double Mean() const {return fMean;}

  double Delta() const {return fDelta;}

  double operator()() const {
    return 2.*Delta()*(rand()/double(RAND_MAX) - 0.5) + Mean();
  }

private:

  double fMean;
  double fDelta;
};

  }  // namespace Minuit2

}  // namespace ROOT

#endif //MN_FlatRandomGen_H_
