#include "kingfournier_attractor.h"

#include <iostream>
#include <vector>

std::vector<double>
KingFournierAttractor::king_fournier(const std::vector<double>& v, double dt) {
	
	// Network connection parameters
	double a_1 = 0.125; 	//Z -> Y
	double b_1 = 0.25;
	double a_2 = 0.25;		//Y -> X
	double b_2 = 0.5;
	double a_3 = 1.0;		//X -> Ci 	(i = 1,2)
	double b_3 = 2.0;
	double a_4 = 7.5;		//C1 -> P1 	&	C2 -> P3
	double b_4 = 5.0;
	
	// Intrinsic Growth Rate of 'Primary Producers'
	double r = 2.5000001;

	// parameters chosen to make attractor to make chaotic attractor
	double d_z = 0.01;
	double d_y = 0.01;
	double d_x = 0.01;
	double d_c = 0.11;

	// Time Step Variables
	double z = v[0];
	double y = v[1];
	double x = v[2];
	double c = v[3];
	double p = v[4];
	double z_dot = z*( f(y,y,a_1,b_1) - d_z );
	double y_dot = y*( f(x,x,a_2,b_2) - f(z,y,a_1,b_1) - d_y );
	double x_dot = x*( f(c,c,a_3,b_3) - f(y,x,a_2,b_2) - d_x );
	double c_dot = c*( f(p,p,a_4,b_4) - f(x,c,a_3,b_3) - d_c );
	double p_dot = p* (  r*(1 - p)    - f(c,p,a_4,b_4) );

	//TODO implement threshold

	// Calcuating next time step
	double z_new = z + z_dot*dt;
	double y_new = y + y_dot*dt;
	double x_new = x + x_dot*dt;
	double c_new = c + c_dot*dt;
	double p_new = p + p_dot*dt;

	// Return vector
	std::vector<double> v1 = {z_new, y_new, x_new, c_new, p_new};
	
  	return v1;
  }

double
KingFournierAttractor::f(double u, double v, double a, double b) {

  double minimum = 0.00001;
  // do nothing
  double f_u = ((a*u)/(1+b*v));
  if(f_u == 0){
  	f_u = minimum;
  }
  return f_u;
}
