//PID Control Algorithm
//Author: Ben Bellerose
//Description: Will give an output value for a PID control
#include <stdio.h>
int main()
{
    //Set inital variables
    float Cv,Pv,Sp,E,E2,Kp,Ki,Kd,I,D,U;
    Cv = 0.00; //Control Variable
    Pv = 0.00; //Proccess Variable
    E = 0.00; //Error
    I = 0.00; //Integral
    D = 0.00; //Derivative
    Kp = 1.00; //Proportional Constant
    Ki = 0.02; //Integral Constant
    Kd = 0.01; //Derivative Constant
    Sp = 350.00; //Setpoint
    //Calculate PI Loop
    while (Pv != Sp)
    {
      //Calculate error
      E2 = E;
      E = Sp - Pv;
      //Calculate the integral
      I = I + E;
      //Calculate the derivitave
      D = E - E2;
      //Calculate the control variable
      Cv = (Kp * E) + (Ki*I) + (Kd*D);
      //Determine output
      U = (Cv/Sp)*100;
      if (U > 100)
      {
        U = 100; //Make U 100 if output is larger
      }
      //printf("%f \n", Cv);
      //printf("%f \n", U);
      Pv = Pv + 25;
    }
    return U;
}
