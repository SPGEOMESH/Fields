
#pragma once


#include <fields/compiletime/lists.h>
#include <fields/compiletime/math.h>
#include <fields/physics/constants.h>
#include <fields/physics/specie.h>

/*
 * Static physical routines
 * applicable to a single particle species.
 * Incorporates a choice of `Units` type,
 * see `physics/units.h`.
 *
 *
 */
template <
        typename Units_,
        SpecieId specieid
>
class Particle: public Units_ {
public: // types:

    using Units = Units_;
    using scalar = Units::scalar;
    using Constants = Constants<scalar, Units::unitsystem>;
    using Specie = Specie<Units, specieid>;
    using Math = Math<scalar>;


public: // API:

    /*!
    \brief Relativistic factor
    \author Vladimir Florinski
    \date 07/15/2020
    \param[in] vmag Velocity magnitude in particle units
    \return Lorentz factor
    */
    static constexpr scalar RelFactor(scalar vmag) {
        return 1.0 / Math::csqrt(1.0 - Math::Sqr(vmag / Units::c));
    }

    /*!
    \brief Relativistic factor based on momentum
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] mmag Momentum magnitude in particle units
    \return Lorentz factor
    */
    static constexpr scalar RelFactor1(scalar mmag) {
        return Math::csqrt(1.0 + Math::Sqr(mmag / Specie::mass / Units::c));
    }

    /*!
    \brief Calculate particle momentum from its kinetic energy
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] enr Kinetic energy in particle units
    \return Relativistic momentum in particle units
    */
    static constexpr scalar Mom(scalar enr) {
        return Math::csqrt(enr * (enr + 2.0 * Specie::mass * Math::Sqr(Units::c))) / Units::c;
    }

    /*!
    \brief Calculate particle total energy from momentum magnitude
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] mom Momentum magnitude in particle units
    \return Total relativistic energy in particle units
    */
    static constexpr scalar EnrTot(scalar mmag) {
        return Math::csqrt(Math::Sqr(mmag) + Math::Sqr(Specie::mass * Units::c)) * Units::c;
    }

    /*!
    \brief Calculate particle kinetic energy from momentum magnitude
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] mom Momentum magnitude in particle units
    \return Relativistic kinetic energy in particle units
    */
    static constexpr scalar EnrKin(scalar mmag)
    {
        return EnrTot(mmag) - Specie::mass * Math::Sqr(Units::c);
    }

    /*!
    \brief Calculate particle velocity magnitude from momentum magnitude
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] mom Momentum magnitude in particle units
    \return Velocity in particle units
    */
    static constexpr scalar Vel(scalar mmag) {
        return mmag * Math::Sqr(Units::c) / EnrTot(mmag);
    }

    // todo
//    /*!
//    \brief Calculate particle velocity from momentum
//    \author Vladimir Florinski
//    \author Lucius Schoenbaum
//    \date 11/10/2025
//    \param[in] mom Momentum in particle units
//    \return Velocity in particle units
//    */
//    template <CoordinateSystem vel_sys>
//    constexpr GeoVector Vel(const GeoVector& mom) {
//        scalar mom_mag = Metric<vel_sys>::Length(mom);
//        GeoVector retval = mom;
//        Metric<vel_sys>::Rescale(retval, Vel<specie>(mom_mag) / mom_mag);
//        return retval;
//    }

    // todo
//    /*!
//    \brief Calculate particle momentum from velocity
//    \author Vladimir Florinski
//    \author Lucius Schoenbaum
//    \date 11/10/2025
//    \param[in] vel Velocity in particle units
//    \return Relativistic momentum in particle units
//    */
//    template <CoordinateSystem vel_sys>
//    constexpr GeoVector Mom(const GeoVector& vel) {
//        GeoVector retval = vel;
//        Metric<vel_sys>::Rescale(retval, Specie::mass * RelFactor(Metric<vel_sys>::Length(retval)));
//        return retval;
//    }

    /*!
    \brief Calculate particle rigidity
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] mmag Momentum magnitude in particle units
    \return Rigidity (\f$pc/q\f$) in particle units
    */
    static constexpr scalar Rigidity(scalar mmag) {
        return mmag * Units::c / Math::cfabs(Specie::charge);
    }

    /*!
    \brief Effective temperature (Maxwell) based on characteristic velocity
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 11/11/2025
    \param[in] v_th Thermal speed
    \return Effective temperature
    */
    static constexpr scalar EffectiveTemperature(scalar v_th) {
        return Specie::mass * Math::Sqr(v_th) / (2.0 * Units::kb);
    }

    //----------------------------------------------------------------------------------------------------------------------------------------------------
    // Particle-fluid routines
    //----------------------------------------------------------------------------------------------------------------------------------------------------


    // todo

//    /*!
//    \brief Electric field from ideal Ohm's law
//    \author Vladimir Florinski
//    \date 11/17/2025
//    \param[in] vel  Velocity vector in particle units
//    \param[in] Bvec Magnetic field vector in particle units
//    \return Electric field, \f$\mathbf{E}=-(\mathbf{v}\times\mathbf{B})/c\f$
//    */
//    constexpr GeoVector InducedEfield(const GeoVector& vel, const GeoVector& Bvec) {
//        return  -(vel ^ Bvec) / Units::c;
//    }
//
//    /*!
//    \brief Magnetic force on a particle
//    \author Vladimir Florinski
//    \date 11/11/2025
//    \param[in] vel  Velocity in particle units
//    \param[in] Evec Electric field in particle units
//    \param[in] Bvec Magnetic field in particle units
//    \return Magnetic Lorentz force in particle units
//    */
//    static constexpr GeoVector LorentzForce(const GeoVector& vel, const GeoVector& Evec, const GeoVector& Bvec) {
//        return Specie::charge * (Evec + (vel ^ Bvec) / Units::c);
//    }

    /*!
    \brief Thermal speed (Maxwell) based on temperature
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 11/1/2025
    \param[in] T Temperature in particle units
    \return Thermal speed
    */
    static constexpr scalar ThermalSpeed(scalar T) {
        return Math::csqrt(2.0 * Units::kb * T / Specie::mass);
    }




    /*!
    \brief Cyclotron frequency
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 11/11/2025
    \param[in] vmag Velocity magnitude in particle units
    \param[in] Bmag Magnetic field magnitude in particle units
    \return Cyclotron frequency in particle units
    */
    static constexpr scalar CyclotronFrequency(scalar vmag, scalar Bmag) {
        return Specie::charge * Bmag / (RelFactor(vmag) * Specie::mass * Units::c);
    }

    /*!
    \brief Larmor radius
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 11/11/2025
    \param[in] mmag Momentum magnitude in particle units
    \param[in] Bmag Magnetic field magnitude in particle units
    \return Larmor radius
    */
    static constexpr scalar LarmorRadius(scalar mmag, scalar Bmag) {
        return mmag * Units::c / (fabs(Specie::charge) * Bmag);
    }

    /*!
    \brief Magnetic moment
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 11/11/2025
    \param[in] mperp Momentum (perp. component) in particle units
    \param[in] Bmag  Magnetic field magnitude in particle units
    \return Magnetic moment
    */
    static constexpr scalar MagneticMoment(scalar mperp, scalar Bmag) {
        return Math::Sqr(mperp) / (2.0 * Specie::mass * Bmag);
    }

    /*!
    \brief Perpendicular momentum from magnetic moment
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] mag_mom Magnetic moment in particle units
    \param[in] Bmag    Magnetic field magnitude in particle units
    \return Momentum (perp. component) in particle units
    */
    static constexpr scalar PerpMomentum(scalar mag_mom, scalar Bmag) {
        return Math::csqrt(2.0 * Specie::mass * mag_mom * Bmag);
    }

    /*!
    \brief Relativistic factor based on parallel momentum and magnetic moment
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] mpara   Parallel component of momentum in particle units
    \param[in] mag_mom Magnetic moment in particle units
    \param[in] Bmag    Magnetic field magnitude in particle units
    \return Lorentz factor
    */
    static constexpr scalar RelFactor2(scalar mpara, scalar mag_mom, scalar Bmag) {
        return Math::csqrt(1.0 + (2.0 * Specie::mass * mag_mom * Bmag + Math::Sqr(mpara)) / Math::Sqr(Specie::mass * Units::c));
    }

};






