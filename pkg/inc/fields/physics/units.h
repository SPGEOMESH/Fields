
#pragma once

#include <fields/physics/constants.h>
#include <fields/compiletime/math.h>

/*
 * Units class
 *
 * A `Units` class provides a basic yet important
 * list of constant data. It is the common
 * language of higher physical reasoning
 * and therefore of computational modules.
 * Without this information they would not be
 * able to be linked together.
 *
 * A `Units` class should provide:
 *  - a scalar type,
 *  - a unitsystem field (see `unitsystem.h`)
 *  - a Constants subtype housing constants
 *     (e.g. the speed of light, Boltzmann constant),
 *  - a Math subtype for convenient access to static methods.
 * Finally, it should provide the units
 * in dimensions of consideration, like
 * length, mass, momentum, and so on.
 * These provide the normalization used
 * in any simulation or processing subsequently
 * carried out in these units.
 *
 *
 */
// todo investigate whether this
//  could be defined as a C++ concept



/*
 * Choice of heliospheric particle code units.
 * This serves as a template for a Units
 * type, or it can also be used in an off-the-shelf fashion.
 *
 *
 */
template <
   typename scalar_,
   UnitSystem unitsystem_
>
class ParticleUnits {
public: // types:

   using scalar = scalar_;
   static constexpr UnitSystem unitsystem = unitsystem_;
   using Constants = Constants<scalar, unitsystem>;
   using Math = Math<scalar>;

public:

   //! Length unit: primary (choose based on on Larmor radius, such as 1000 km)
   static constexpr scalar unit_length = 1.0E10;
   //! Velocity unit: primary (~c)
   static constexpr scalar unit_velocity = 0.1 * Constants::SPEED_OF_LIGHT;
   //! Mass unit: primary (m_p, m_e, etc.)
   static constexpr scalar unit_mass = Constants::MASS_PROTON;
   //! Charge unit: arbitrary (set for convenience to e and not usable without conversion)
   static constexpr scalar unit_charge = Constants::ELECTRON_CHARGE;
   //! Temperature: primary (use for PUIs and other low-energy populations)
   static constexpr scalar unit_temperature = Constants::KILO_ELECTRON_VOLT / Constants::BOLTZMANN;
   //! Number density: arbitrary (not usable without conversion)
   static constexpr scalar unit_number_density = 1.0;


   //! Momentum unit: derived from mass and velocity
   static constexpr scalar unit_momentum = unit_mass * unit_velocity;
   //! Energy unit: derived from mass and velocity
   static constexpr scalar unit_energy = unit_mass * unit_velocity * unit_velocity;
   //! Time unit: derived from velocity and length (should be ~ gyro-period)
   static constexpr scalar unit_time = unit_length / unit_velocity;
   //! Density: derived from mass and number density (should be 1 m_p*cm^-3)
   static constexpr scalar unit_density = unit_mass * unit_number_density;
   //! Field unit: derived from momentum, time, and charge (should be ~1 nT)
   static constexpr scalar unit_magnetic = unit_momentum / (unit_charge * unit_time);
   //! Pressure and energy density: derived from magnetic field
   static constexpr scalar unit_pressure = unit_magnetic * unit_magnetic;
   //! Force unit: derived from momentum and time
   static constexpr scalar unit_force = unit_momentum / unit_time;

   //! Speed of light
   static constexpr scalar c = Constants::SPEED_OF_LIGHT / unit_velocity;
   //! Boltzmann constant
   static constexpr scalar kb = Constants::BOLTZMANN * unit_temperature / unit_energy;

   //! Rigidity unit: derived from energy and charge
   static constexpr scalar unit_rigidity = unit_energy / unit_charge;
   //! Diffusion coefficient: derived, should be 10^20-10^23 (good numbers for GCRs)
   static constexpr scalar unit_diffusion = unit_velocity * unit_length;
   //! Magnetic moment: derived from charge and length
   static constexpr scalar unit_magnetic_moment = unit_charge * unit_length;
   //! Conversion factor for charge
   static constexpr scalar charge_conv = unit_charge * unit_magnetic * unit_time / unit_momentum;
   //! Frequency
   static constexpr scalar unit_frequency = 1.0;

};



/*
 * Choice of heliospheric fluid code units.
 * This serves as a template for a Units
 * type, or it can also be used in an off-the-shelf fashion.
 *
 */
template <
      typename scalar_,
      UnitSystem unitsystem_
>
class FluidUnits {
public: // types:

   using scalar = scalar_;
   static constexpr UnitSystem unitsystem = unitsystem_;
   using Constants = Constants<scalar, unitsystem>;
   using Math = Math<scalar>;

public:

   //! Length: primary (1 au is a good value for the heliosphere)
   static constexpr scalar unit_length = Constants::ASTRONOMICAL_UNIT;
   //! Velocity: primary (100 km/s is a good value for the heliosphere)
   static constexpr scalar unit_velocity = 1.0E7;
   //! Mass unit: primary (m_p, m_e, etc.)
   static constexpr scalar unit_mass = Constants::MASS_PROTON;
   //! Charge unit: arbitrary (set for convenience to e and not usable without conversion)
   static constexpr scalar unit_charge = Constants::ELECTRON_CHARGE;
   //! Temperature: primary (should be 1 eV/k_B~10^4 K)
   static constexpr scalar unit_temperature = Constants::ELECTRON_VOLT / Constants::BOLTZMANN;
   //! Number density: primary (should be 1 cm^-3). We can choose a number density unit independently of the length unit because certain conservation laws (namely MHD) are invariant under the transformation rho->a*rho, p->a*p, B^2->a*B^2. However, this is not the case for other physical laws such as those governing collisions, where corrections must are applied.
   static constexpr scalar unit_number_density = 1.0;


   //! Momentum unit: derived from mass and velocity
   static constexpr scalar unit_momentum = unit_mass * unit_velocity;
   //! Energy unit: derived from mass and velocity
   static constexpr scalar unit_energy = unit_mass * unit_velocity * unit_velocity;
   //! Time: derived from length and velocity (should be hours/days)
   static constexpr scalar unit_time = unit_length / unit_velocity;
   //! Density: derived from mass and number density (should be 1 m_p*cm^-3)
   static constexpr scalar unit_density = unit_mass * unit_number_density;
   //! Magnetic field: derived from density and velocity (should be uG)
   static constexpr scalar unit_magnetic = unit_velocity * Math::csqrt(unit_density);
   //! Pressure and energy density: derived from magnetic field (should be 10^-10)
   static constexpr scalar unit_pressure = Math::Sqr(unit_magnetic);
   //! Force unit: derived from momentum and time
   static constexpr scalar unit_force = unit_momentum / unit_time;

   //! Speed of light
   static constexpr scalar c = Constants::SPEED_OF_LIGHT / unit_velocity;
   //! Boltzmann constant. Note that for fluids the ideal gas EOS is p=n*k_B*T.
   static constexpr scalar kb = Constants::BOLTZMANN / unit_pressure * unit_temperature * unit_number_density;

};



