#ifndef ATTRACTORS_ATTRACTOR_FUNCTIONS_HEADER
#define ATTRACTORS_ATTRACTOR_FUNCTIONS_HEADER

#include "math/vector.h"
#include <iostream>

// Most functions can be found here with additional information.
// http://www.3d-meier.de/tut19/Seite3.html
class AttractorFunctions {
 public:
  typedef std::function<math::Vec3d(const math::Vec3d&, double)> Type;

 public:
  //dummy function
  static math::Vec3d king_fournier(const math::Vec3d& v, double dt);

  // Aizawa attractor function
  // Start value: 0.1, 0.0, 0.0
  // Good values: 0.01 / 20000  and 0.009 / 20000
  static math::Vec3d aizawa(const math::Vec3d& v, double dt);

  // Bouali attractor function
  // Start value: 1.0, 0.1, 0.1
  // Good values: 0.006 / 40000
  static math::Vec3d bouali(const math::Vec3d& v, double dt);

  // Burke-Shaw attractor function
  // Start value: 1.0, 0.0, 0.0
  // Good values: 0.005 / 20000
  static math::Vec3d burke_shaw(const math::Vec3d& v, double dt);

  // Chen-Celikovsky attractor function
  // Start value: 1.0, 1.0, 1.0
  // Good values: 0.001 / 20000
  static math::Vec3d chen_celikovsky(const math::Vec3d& v, double dt);

  // Chen-Lee attractor function
  // Start value: 1.0, 0.0, 4.5
  // Good values: 0.004 / 20000
  static math::Vec3d chen_lee(const math::Vec3d& v, double dt);

  // Dequan Li attractor function
  // Start value: 0.349, 0, -0.16
  // Good values: 0.001 / 75000
  static math::Vec3d dequan_li(const math::Vec3d& v, double dt);

  // Returns the attractor function corresponding to function name.
  static Type for_string(const std::string& name);
};

#endif /* ATTRACTORS_ATTRACTOR_FUNCTIONS_HEADER */
