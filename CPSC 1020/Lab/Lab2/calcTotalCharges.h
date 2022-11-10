#ifndef CALC_TOTAL_CHARGES
#define CALC_TOTAL_CHARGES

// prototype for calcTotalCharges (in-patient)
double calcTotalCharges(double numDays, double roomRate, double hospServices, double medCharges);
// prototype for calcTotalCharges (out-patient)
double calcTotalCharges(double hospServices, double medCharges);

#endif