
#pragma once

#include <fields/compiletime/math.h>
#include <fields/physics/constants.h>
#include <fields/physics/specie.h>


/*
 * Routines pertaining to a fluid
 * associated to a specie type.
 *
 *
 */
template <
        typename Units_,
        SpecieId specieid
>
class Fluid: public Units_ {
public: // types:

    using Units = Units_;
    using scalar = typename Units::scalar;
    using Constants = Constants<scalar, Units::unitsystem>;
    using Specie = Specie<Units, specieid>;
    using Math = Math<scalar>;

public: // API:

    /*!
    \brief Calculate gas pressure from temperature
    \author Vladimir Florinski
    \date 08/08/2025
    \param[in] nden Number density in fluid units
    \param[in] T    Temperature in fluid units
    \return Sound speed in fluid units
    */
    static constexpr scalar Pressure(scalar nden, scalar T)
    {
        return nden * Units::kb * T;
    }

    /*!
    \brief Calculate the MHD energy density
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] den Density in fluid units
    \param[in] u2  Square of velocity in fluid units
    \param[in] prs Gas pressure in fluid units
    \param[in] B2  Square of the magnetic field (if defined) in fluid units
    \return Energy per unit volume in fluid units
    */
    static constexpr scalar EnergyDensity(scalar den, scalar u2, scalar prs, scalar B2 = 0.0) {
        return 0.5 * den * u2 + prs / (Specie::polytropic_index - 1.0) + B2 * Math::oneo8pi;
    }

    /*!
    \brief Calculate gas pressure from MHD energy density
    \author Vladimir Florinski
    \date 07/31/2019
    \param[in] den  Mass density
    \param[in] u2   Square of velocity
    \param[in] eden Energy density
    \param[in] B2   Square of the magnetic field (if defined)
    \return gas pressure
    */
    static constexpr scalar Pressure(scalar den, scalar u2, scalar eden, scalar B2 = 0.0)
    {
        return (eden - 0.5 * den * u2 - B2 * Math::oneo8pi) * (Specie::polytropic_index - 1.0);
    }

    /*!
    \brief Compute sound speed
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] den Density in fluid units
    \param[in] prs Pressure in fluid units
    \return Sound speed in fluid units
    */
    static constexpr scalar SoundSpeed(scalar den, scalar prs)
    {
        return Math::csqrt(Specie::polytropic_index * prs / den);
    }

    /*!
    \brief Compute square of the sound speed
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] den Density in fluid units
    \param[in] prs
    \param[in] prs
    \return Sound speed squared in fluid units
    */
    static constexpr scalar Sound2(scalar den, scalar prs)
    {
        return Specie::polytropic_index * prs / den;
    }

    /*!
    \brief Compute Alfven speed
    \author Vladimir Florinski
    \date 07/31/2019
    \param[in] den Density in fluid units
    \param[in] B2  Square of the magnetic field in fluid units
    \return Alfven speed in fluid units
    */
    static constexpr scalar AlfvenSpeed(scalar den, scalar B2)
    {
        return Math::csqrt(B2 / den * Math::oneo4pi);
    }

    /*!
    \brief Compute square of the Alfven speed
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 09/13/2025
    \param[in] den Density in fluid units
    \param[in] B2  Square of the magnetic field in fluid units
    \return Alfven speed squared in fluid units
    */
    static constexpr scalar Alfven2(scalar den, scalar B2)
    {
        return B2 / den * Math::oneo4pi;
    }

    /*!
    \brief Compute fast magnetosonic speed
    \author Vladimir Florinski
    \date 11/10/2025
    \param[in] Cs2   Square of the sound speed in fluid units
    \param[in] Va2   Square of the Alfven speed in fluid units
    \param[in] cosa2 Square of the cosine of the propagation angle
    \return Fast magnetosonic speed in fluid units
    */
    static constexpr scalar FastMagnetosonicSpeed(scalar Cs2, scalar Va2, scalar cosa2) {
        return Math::csqrt(Cs2 + Va2 + Math::csqrt(Math::Sqr(Cs2 + Va2) - 4.0 * Cs2 * Va2 * cosa2)) / Math::sqrt2;
    }

    /*!
    \brief Compute slow magnetosonic speed
    \author Vladimir Florinski
    \date 11/10/2025
    \param[in] Cs2   Square of the sound speed in fluid units
    \param[in] Va2   Square of the Alfven speed in fluid units
    \param[in] cosa2 Square of the cosine of the propagation angle
    \return Slow magnetosonic speed in fluid units
    */
    static constexpr scalar SlowMagnetosonicSpeed(scalar Cs2, scalar Va2, scalar cosa2) {
        return Math::csqrt(Cs2 + Va2 - Math::csqrt(Math::Sqr(Cs2 + Va2) - 4.0 * Cs2 * Va2 * cosa2)) / Math::sqrt2;
    }

    /*!
    \brief Compute squares of both fast and slow magnetosonic speeds
    \author Vladimir Florinski
    \date 11/10/2025
    \param[in]  Cs2   Square of the sound speed in fluid units
    \param[in]  Va2   Square of the Alfven speed in fluid units
    \param[in]  cosa2 Square of the cosine of the propagation angle
    \param[out] Vf2   Square of the fast magnetosonic speed in fluid units
    \param[out] Vs2   Square of the slow magnetosonic speed in fluid units
    */
    static constexpr void Magnetosonic2(scalar Cs2, scalar Va2, scalar cosa2, double& Vf2, double& Vs2) {
        scalar Vd2 = Math::csqrt(Math::Sqr(Cs2 + Va2) - 4.0 * Cs2 * Va2 * cosa2);
        Vf2 = 0.5 * (Cs2 + Va2 + Vd2);
        Vs2 = Vf2 - Vd2;
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

};


