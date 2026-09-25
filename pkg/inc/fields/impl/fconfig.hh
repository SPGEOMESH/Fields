/*!
\file fconfig.hh
\brief Configuration for Fields and Coordinates classes

*/

#pragma once

#include <fields/compiletime/lists.h>
#include <fields/physics/specie.h>

namespace Spectrum {

// It may seem odd that the Fields type should
// have an associated specie (ie., a particle species), but
// this is convenient for unit conversion operations.
template <
      typename Units_,
      SpecieId specieid_ = SpecieId::proton_core,
      CoordinateSystem Pos_sys_ = CoordinateSystem::Cartesian,
      CoordinateSystem Mom_sys_ = CoordinateSystem::Cartesian
>
struct FConfig {

    // unpack the Units
    using Units = Units_;
    using Constants = Constants<typename Units::scalar, Units::unitsystem>;
    using typename Units::scalar;

    static constexpr auto specieid = specieid_; //
   static constexpr auto Pos_sys = Pos_sys_;
   static constexpr auto Mom_sys = Mom_sys_;
   static constexpr auto Vel_sys = Mom_sys_;
   // A CoordinateSystem is 'radial' iff the 0th component is the radial component.
   static constexpr bool Pos_radial = (Pos_sys == CoordinateSystem::Polar || Pos_sys == CoordinateSystem::SphericalRTP);
   static constexpr bool Mom_radial = (Mom_sys == CoordinateSystem::Polar || Mom_sys == CoordinateSystem::SphericalRTP || Mom_sys == CoordinateSystem::PitchAngle);
   static  constexpr bool Vel_radial = Mom_radial;
   static constexpr bool Mag_radial = false;
   static constexpr bool Flum_radial = false;
   static constexpr bool Fluv_radial = false;
};

}

