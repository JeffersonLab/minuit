// @(#)root/minuit2:$Name:  $:$Id: LaOuterProduct.h,v 1.1.1.1 2008/02/09 21:56:12 edwards Exp $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MA_LaOuterProd_H_
#define MA_LaOuterProd_H_

/** LAPACK Algebra
    specialize the Outer_product function for LAVector;
 */

#include "Minuit2/VectorOuterProduct.h"
#include "Minuit2/ABSum.h"
#include "Minuit2/LAVector.h"
#include "Minuit2/LASymMatrix.h"

namespace ROOT {

   namespace Minuit2 {


inline ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, double>, double>, double> Outer_product(const ABObj<vec, LAVector, double>& obj) {
//   std::cout<<"ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, double>, double>, double> Outer_product(const ABObj<vec, LAVector, double>& obj)"<<std::endl;
  return ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, double>, double>, double>(VectorOuterProduct<ABObj<vec, LAVector, double>, double>(obj));
}

// f*outer
template<class T>
inline ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator*(T f, const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj) {
//   std::cout<<"ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator*(T f, const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj)"<<std::endl;
  return ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>(obj.Obj(), obj.f()*f);
}

// outer/f
template<class T>
inline ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator/(const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj, T f) {
//   std::cout<<"ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator/(const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj, T f)"<<std::endl;
  return ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>(obj.Obj(), obj.f()/f);
}
 
// -outer
template<class T>
inline ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator-(const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj) {
//   std::cout<<"ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator/(const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj, T f)"<<std::endl;
  return ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>(obj.Obj(), T(-1.)*obj.f());
}

void Outer_prod(LASymMatrix&, const LAVector&, double f = 1.);

  }  // namespace Minuit2

}  // namespace ROOT

#endif //MA_LaOuterProd_H_
