//PID Control Algorithm
//Author: Ben Bellerose
//Description: Will give an output value for a PID control
#include <stdio.h>
int main()
{
    //Set inital variables
    float Cv,Pv,Sp,E,E2,Kp,Ki,Kd,I,D,U;
    Cv = 0.00;
    Pv = 0.00;
    E = 0.00;
    I = 0.00;
    D = 0.00;
    Kp = 1.00;
    Ki = 0.02;
    Kd = 0.01;
    Sp = 350.00;
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
