// @(#)root/minuit2:$Name:  $:$Id: Quad4FMain.cxx,v 1.1 2008/02/09 21:56:15 edwards Exp $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "Quad4F.h"
#include "Minuit2/FunctionMinimum.h"
#include "Minuit2/MnMigrad.h"
#include "Minuit2/MnUserParameters.h"
#include "Minuit2/MnPrint.h"
// #include "TimingUtilities/PentiumTimer.h"

// StackAllocator gStackAllocator;

using namespace ROOT::Minuit2;

int main() {

  Quad4F fcn;

//   PentiumTimer stopwatch;
//   stopwatch.start();

//   long long int start = stopwatch.lap().ticks();
//   long long int stop = stopwatch.lap().ticks();
//   std::cout<<"stop-start: "<<stop - start<<std::endl;
//   start = stopwatch.lap().ticks();
  {
  //test constructor
  MnUserParameters upar;
  upar.Add("x", 1., 0.1);
  upar.Add("y", 1., 0.1);
  upar.Add("z", 1., 0.1);
  upar.Add("w", 1., 0.1);

  MnMigrad migrad(fcn, upar);
  FunctionMinimum min = migrad();
  std::cout<<"minimum: "<<min<<std::endl;
  }
//   stop = stopwatch.lap().ticks();
//   std::cout<<"stop-start: "<<stop - start<<std::endl;
/*

  {
  //test constructor
  std::vector<double> par(4); 
  std::vector<double> err(4);
  for(int i = 0; i < 4; i++) {
    par[i] = 1.;
    err[i] = 0.1;
  }
  MnMigrad migrad(fcn, par, err);
  FunctionMinimum min = migrad();
  std::cout<<"minimum: "<<min<<std::endl;
  }

  {
  //test edm Value
  std::vector<double> par(4); 
  std::vector<double> err(4);
  for(int i = 0; i < 4; i++) {
    par[i] = 1.;
    err[i] = 0.1;
  }
  MnMigrad migrad(fcn, par, err);
  double edm = 1.e-1;
  FunctionMinimum min = migrad(20, edm);
  std::cout<<"minimum: "<<min<<std::endl;
  }

  {
  //test # of iterations
  std::vector<double> par(4); 
  std::vector<double> err(4);
  for(int i = 0; i < 4; i++) {
    par[i] = 1.;
    err[i] = 0.1;
  }
  MnMigrad migrad(fcn, par, err);
  int niter = 2;
  FunctionMinimum min = migrad(niter, 1.e-5);
  std::cout<<"minimum: "<<min<<std::endl;
  }
*/

  return 0;
}
