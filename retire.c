/**
 * Aayush kulkarni
 * akulkarni3@huskers.unl.edu
 * Date: 2022/09/19
 *
 * A 401(k) plan is a type of tax-qualified account for people to save for retirement.
 *
 * // https://github.com/Aayush-cyborg/hack4 [View my repo]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


 int main(int argc, char **argv) {
  //declaration
  double balance;
  double monthlyContribution;
  double returnRate=0;
  double inflationRate;
  double total_int;
  double inflaReturnRate;
  int yearsUntilRetired;
  int months;
  int i;
  //ask for input from user
  scanf ("%lf %lf %lf %lf %d", &balance, &monthlyContribution, &returnRate, &inflationRate, &yearsUntilRetired);
  //checking for valid input from user
    if ((returnRate > 1) || (returnRate < 0) || (inflationRate > 1) || (inflationRate < 0)) {
    printf ("Invalid input ");
  }
  //calculating month
    months = yearsUntilRetired * 12;
  //calculating inflation adjusant
    inflaReturnRate = ((returnRate + 1) / (inflationRate + 1)) - 1;
  //print tables
    printf ("Month  Interest  Balance\n");
    for (i = 1; i <= months; i++)
  {
      returnRate = (inflaReturnRate * balance) / 12;
      balance = balance + returnRate + monthlyContribution;
      printf (" %d $   %0.2f $    %0.2f \n", i, returnRate, balance);
      total_int = total_int + returnRate;
  }
    printf("Total Interest Earned : $ %0.2f\n",total_int);
    printf("Total Nest Egg: $ %0.2f",balance);

return 0;
}