#ifndef ATTRACTORS_CURVE_GENERATOR_HEADER
#define ATTRACTORS_CURVE_GENERATOR_HEADER

#include <functional>

#include "math/vector.h"
#include "attractor_functions.h"
#include "kingfournier_attractor.h"


/**
 * Class for sampling the attractor function and generating a 1D curve embedded
 * in 3D space. The resulting curve can be scaled and centered into the unit
 * cube, and adaptively simplified to remove unnecessarily dense samples.
 */
class CurveGenerator {
 public:
  typedef math::Vector<double, 3> Point;
  typedef std::vector<Point> Curve;

  struct Options {
    /* Generator options. */
    AttractorFunctions::Type generator;
    double delta = 0.01;
    std::size_t iterations = 20000;

    /* Simplification options (defaults for scaled and centered curve). */
    double angle_threshold = MATH_DEG2RAD(2.0);
    double min_distance = 1e-8;
    double max_distance = 0.05;
  };

 public:
  explicit CurveGenerator(const Options& options);
  void generate();
  void generate_king_fournier(double starting, double ending, float step);
  void clear();
  void scale_and_center();
  void simplify();
  void save_ply(const std::string& filename);
  void clear_curve();

  const Curve& get_curve() const;
  void get_float_curve(std::vector<math::Vec3f>* curve) const;

 private:
  Options options_;
  Curve curve_;
};

#endif /* ATTRACTORS_CURVE_GENERATOR_HEADER */
