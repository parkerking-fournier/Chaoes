#ifndef KINGFOURNIER_ATTRACTOR_HEADER
#define KINGFOURNIER_ATTRACTOR_HEADER

#include "math/vector.h"

class KingFournierAttractor{
 public:
  typedef std::function<std::vector<double>(const std::vector<double>&, double)> Type;

 public:
  //dummy function
  static std::vector<double> king_fournier(const std::vector<double>& v, double dt);
  static double f(double u, double v, double a, double b);
};

#endif /* ATTRACTORS_ATTRACTOR_FUNCTIONS_HEADER */