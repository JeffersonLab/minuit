// @(#)root/minuit2:$Name:  $:$Id: MinuitParameter.h,v 1.1 2008/02/09 21:56:12 edwards Exp $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef ROOT_Minuit2_MinuitParameter
#define ROOT_Minuit2_MinuitParameter

#include <algorithm>
#include <memory>

namespace ROOT {

   namespace Minuit2 {


/** class for the individual Minuit Parameter with Name and number; 
    contains the input numbers for the minimization or the output result
    from minimization;
    possible interactions: Fix/release, set/remove limits, set Value/error; 
 */

class MinuitParameter {

public:
  
  //constructor for constant Parameter
  MinuitParameter(unsigned int num, const char* Name, double val) : 
    fNum(num), fValue(val), fError(0.), fConst(true), fFix(false), 
    fLoLimit(0.), fUpLimit(0.), fLoLimValid(false), fUpLimValid(false){
    SetName(Name);
  }
  
  //constructor for standard Parameter
  MinuitParameter(unsigned int num, const char* Name, double val, double err) :
    fNum(num), fValue(val), fError(err), fConst(false), fFix(false), 
    fLoLimit(0.), fUpLimit(0.), fLoLimValid(false), fUpLimValid(false){
    SetName(Name);
  }
  
  //constructor for limited Parameter
  MinuitParameter(unsigned int num, const char* Name, double val, double err, 
		  double min, double max) : 
    fNum(num),fValue(val), fError(err), fConst(false), fFix(false), 
    fLoLimit(min), fUpLimit(max), fLoLimValid(true), fUpLimValid(true){
    assert(min != max);
    if(min > max) {
      fLoLimit = max;
      fUpLimit = min;
    }
    SetName(Name);    
  }

  ~MinuitParameter() {}

  MinuitParameter(const MinuitParameter& par) : 
    fNum(par.fNum), fValue(par.fValue), fError(par.fError),
    fConst(par.fConst), fFix(par.fFix), fLoLimit(par.fLoLimit), 
    fUpLimit(par.fUpLimit), fLoLimValid(par.fLoLimValid), 
    fUpLimValid(par.fUpLimValid) {
    memcpy(fName, par.Name(), 11*sizeof(char));
  }
  
  MinuitParameter& operator=(const MinuitParameter& par) {
    fNum = par.fNum;
    memcpy(fName, par.fName, 11*sizeof(char));
    fValue = par.fValue;
    fError = par.fError;
    fConst = par.fConst;
    fFix = par.fFix;
    fLoLimit = par.fLoLimit; 
    fUpLimit = par.fUpLimit;
    fLoLimValid = par.fLoLimValid; 
    fUpLimValid = par.fUpLimValid;
    return *this;
  }

  //access methods
  unsigned int Number() const {return fNum;}
  const char* Name() const {return fName;}
  double Value() const {return fValue;}
  double Error() const {return fError;}

  //interaction
  void SetValue(double val) {fValue = val;}
  void SetError(double err) {fError = err;}
  void SetLimits(double low, double up) {
    assert(low != up);
    fLoLimit = low; 
    fUpLimit = up;
    fLoLimValid = true; 
    fUpLimValid = true;
    if(low > up) {
      fLoLimit = up; 
      fUpLimit = low;
    }
  }

  void SetUpperLimit(double up) {
    fLoLimit = 0.; 
    fUpLimit = up;
    fLoLimValid = false; 
    fUpLimValid = true;
  }

  void SetLowerLimit(double low) {
    fLoLimit = low; 
    fUpLimit = 0.;
    fLoLimValid = true; 
    fUpLimValid = false;
  }

  void RemoveLimits() {
    fLoLimit = 0.; 
    fUpLimit = 0.;
    fLoLimValid = false; 
    fUpLimValid = false;
  }

  void Fix() {fFix = true;}
  void Release() {fFix = false;}
  
  //state of Parameter (fixed/const/limited)
  bool IsConst() const {return fConst;}
  bool IsFixed() const {return fFix;}

  bool HasLimits() const {return fLoLimValid || fUpLimValid; }
  bool HasLowerLimit() const {return fLoLimValid; }
  bool HasUpperLimit() const {return fUpLimValid; }
  double LowerLimit() const {return fLoLimit;}
  double UpperLimit() const {return fUpLimit;}

private:

  unsigned int fNum;
  char fName[11];
  double fValue;
  double fError;
  bool fConst;
  bool fFix;
  double fLoLimit; 
  double fUpLimit;
  bool fLoLimValid; 
  bool fUpLimValid;

private:

  void SetName(const char* Name) {
    int l = std::min(int(strlen(Name)), 11);
    memset(fName, 0, 11*sizeof(char));
    memcpy(fName, Name, l*sizeof(char));
    fName[10] = '\0';
  }
};

  }  // namespace Minuit2

}  // namespace ROOT

#endif  // ROOT_Minuit2_MinuitParameter
