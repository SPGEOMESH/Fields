
#pragma once


#include <fields/types.h>
#include <fields/compiletime/math.h>


//----------------------------------------------------------------------------------------------------------------------------------------------------
// Fields options
//----------------------------------------------------------------------------------------------------------------------------------------------------


//! Coordinate system - defines curvilinear coordinates
enum class CoordinateSystem {
   Cartesian,
   Cylindrical,
   SphericalRTP,
   SphericalRMP,
   Custom,
   Polar,
   PitchAngle, /* magnitude, 'mu', - */
   Anisotropic, /* perpendicular, - , parallel */
};


//----------------------------------------------------------------------------------------------------------------------------------------------------
// Fluid Specie / Convervation Law options
//----------------------------------------------------------------------------------------------------------------------------------------------------


enum class Model {
// GASDYN - compressible gas dynamics (5 vars)
   GasDyn,
// MHD - ideal MHD (8 vars)
   MHD,
// MHDE - two-fluid ideal MHD (9 vars)
   MHDGLM,
   MHDE,
// CGL - anisotropic ideal MHD (9 vars)
   CGL,
// CGLE - anisotropic two-fluid ideal MHD (9 vars)
   CGLE,
};

enum class TurbulenceModel {
   Zank6eq,
};

enum class Form {
   primitive,
   conserved,
   flux,
};

enum class Passivity {
   active,
   passive,
};




namespace Impl {

template<bool cond, typename IfTrue, typename IfFalse>
struct Cond_impl;

template<typename IfTrue, typename IfFalse>
struct Cond_impl<true, IfTrue, IfFalse> {
   using Cond = IfTrue;
};

template<typename IfTrue, typename IfFalse>
struct Cond_impl<false, IfTrue, IfFalse> {
   using Cond = IfFalse;
};

}

//! Conditional type
template <bool cond, typename IfTrue, typename IfFalse>
using Cond = typename Impl::Cond_impl<cond, IfTrue, IfFalse>::Cond;



