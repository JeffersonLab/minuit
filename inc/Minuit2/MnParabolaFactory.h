// @(#)root/minuit2:$Name:  $:$Id: MnParabolaFactory.h,v 1.1 2008/02/09 21:56:12 edwards Exp $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef ROOT_Minuit2_MnParabolaFactory
#define ROOT_Minuit2_MnParabolaFactory

namespace ROOT {

   namespace Minuit2 {


class MnParabola;
class MnParabolaPoint;

class MnParabolaFactory {

public:

  MnParabolaFactory() {}

  ~MnParabolaFactory() {}

  MnParabola operator()(const MnParabolaPoint&, const MnParabolaPoint&, 
			const MnParabolaPoint&) const;

  MnParabola operator()(const MnParabolaPoint&, double, 
			const MnParabolaPoint&) const;

private: 
  
};

  }  // namespace Minuit2

}  // namespace ROOT

#endif  // ROOT_Minuit2_MnParabolaFactory
