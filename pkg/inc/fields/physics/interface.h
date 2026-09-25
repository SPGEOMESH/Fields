
#pragma once

#include <fields/compiletime/math.h>
#include <fields/physics/constants.h>
#include <fields/physics/specie.h>


/*
 * It is assumed that both particle
 * and fluid units use the same unit system.
 *
 *
 */
template <
      typename ParticleUnits_,
      typename FluidUnits_,
      SpecieId specieid
>
class Interface {
public: // types:

   using ParticleUnits = ParticleUnits_;
   using FluidUnits = FluidUnits_;
   using scalar = typename ParticleUnits::scalar;
   using Constants = Constants<scalar, ParticleUnits::unitsystem>;
   using ParticleSpecie = Specie<ParticleUnits, specieid>;
   using Math = Math<scalar>;

   static_assert(ParticleUnits::unitsystem == FluidUnits::unitsystem, "A particle-fluid interface must have a consistent unit system.");

   //! Ratio of charge/mass has a conversion factor required to calculate particle's cyclotron frequency and radius.
   static constexpr scalar charge_mass_conversion = ((ParticleUnits::unit_charge * FluidUnits::unit_magnetic /ParticleUnits::unit_mass / FluidUnits::unit_velocity) / ParticleUnits::unit_frequency);


public: // API:

   /*!
   \brief Plasma frequency
   \author Vladimir Florinski
   \author Lucius Schoenbaum
   \date 09/13/2025
   \param[in] den Density
   \return Plasma frequency
   */
   constexpr scalar Frequency(scalar den) {
      return sqrt(Math::fourpi * den) * charge_mass_conversion * Math::cfabs(ParticleSpecie::charge) / ParticleSpecie::mass;
   }


   /*!
   \brief Collision frequency
   \author Vladimir Florinski
   \author Lucius Schoenbaum
   \date 09/13/2025
   \param[in] den Density
   \param[in] T   Temperature
   \param[in] Lam Coulomb logarithm
   \return Collision frequency
   \note Our system of units (MHD centric) requires a coefficient to relate the number density unit to the inverse cube of distance unit.
   */
   constexpr scalar CollisionFrequency(scalar den, scalar T, scalar Lam) {
      return 2.0 / 3.0 * Math::sqrt2 * Math::oneopi * Lam * ParticleSpecie::mass / Math::Cube(ThermalSpeed(T) * FluidUnits::unit_length) / FluidUnits::unit_density
             * ParticleUnits::unit_mass * Math::Sqr(Frequency(den) * charge_mass_conversion * ParticleSpecie::charge / ParticleSpecie::mass);
   }


};



