
#pragma once

#include <array>
#include <string_view>

#include <fields/physics/constants.h>

/*
 * Specie class
 *
 * Specie is codebase notation for a particle species.
 * Think of: ParticleSpecies is too long, so just Specie.
 * Basic Specie types: proton, electron, alpha particle.
 * Specie identifiers provide constant data lookup, at compile time.
 *
 * If you are simulating using test particles,
 * you would probably create a Specie in order
 * to construct a Particle class, see `particle.h`.
 *
 * If you are simulating using a fluid model,
 * you would probably create a Specie in order
 * to construct a Fluid class, see `fluid.h`.
 *
 */



enum class SpecieId {
    //! Electrons - core
    electron_core,
    //! Electrons - energetic
    electron_halo,
    //! Electrons - energetic/anisotropic (e.g., strahl)
    electron_beam,
    //! Muons - core
    muon_core,
    //! Protons - core
    proton_core,
    //! Protons - energetic (e.g., suprathermal)
    proton_halo,
    //! Protons - energetic/anisotropic
    proton_beam,
    //! Protons - pickup (as proton_halo, but different origin)
    proton_pickup,
    //! Alpha particles - core
    alpha_core,
    //! Alpha particles - energetic
    alpha_halo,
    //! Singly ionized helium
    heliumII_core,
    //! Singly ionized helium - pickup
    heliumII_pickup,
    //! Proton-electron plasma - core
    hydrogenII_core,
    //! Hydrogen atoms - core
    hydrogenI_core,
    //! Hydrogen atoms - energetic (e.g., from heliosheath)
    hydrogenI_halo,
    //! Hydrogen atoms - energetic (e.g., from solar wind)
    hydrogenI_beam,
    //! Helium atoms - core
    heliumI_core
};



template <
        typename Units_,
        SpecieId specieid
>
class Specie {

    // unpack the Units
    using Units = Units_;
    using scalar = Units::scalar;
    using Constants = Constants<scalar, Units::unitsystem>;

    static constexpr size_t num_species = 17;

    // Names of fluid species
    static constexpr std::array<std::string_view, num_species> SpeciesNames
            = {"Electron (core)", "Electron (halo)", "Electron (beam)",
               "Muon (core)",
               "Proton (core)", "Proton (halo)", "Proton (beam)", "Proton (pickup)",
               "Alpha (core)", "Alpha (halo)",
               "Helium II (core)", "Helium II (pickup)",
               "Hydrogen II (core)",
               "Hydrogen I (core)", "Hydrogen I (halo)", "Hydrogen I (beam)",
               "Helium I (core)"};


    // Masses of particles comprising the fluids
    static constexpr scalar SpeciesMasses[num_species] = {
        Constants::MASS_ELECTRON / Units::unit_mass,
        Constants::MASS_ELECTRON / Units::unit_mass,
        Constants::MASS_ELECTRON / Units::unit_mass,
        Constants::MASS_MUON  / Units::unit_mass,
        Constants::MASS_PROTON / Units::unit_mass,
        Constants::MASS_PROTON / Units::unit_mass,
        Constants::MASS_PROTON / Units::unit_mass,
        Constants::MASS_PROTON / Units::unit_mass,
        2.0 * (Constants::MASS_PROTON + Constants::MASS_NEUTRON) / Units::unit_mass,
        2.0 * (Constants::MASS_PROTON + Constants::MASS_NEUTRON) / Units::unit_mass,
        (2.0 * (Constants::MASS_PROTON + Constants::MASS_NEUTRON) + Constants::MASS_ELECTRON) / Units::unit_mass,
        (2.0 * (Constants::MASS_PROTON + Constants::MASS_NEUTRON) + Constants::MASS_ELECTRON) / Units::unit_mass,
        (Constants::MASS_PROTON + Constants::MASS_ELECTRON) / Units::unit_mass,
        (Constants::MASS_PROTON + Constants::MASS_ELECTRON) / Units::unit_mass,
        (Constants::MASS_PROTON + Constants::MASS_ELECTRON) / Units::unit_mass,
        (Constants::MASS_PROTON + Constants::MASS_ELECTRON) / Units::unit_mass,
        2.0 * (Constants::MASS_PROTON + Constants::MASS_NEUTRON  + Constants::MASS_ELECTRON) / Units::unit_mass
    };

    // Charges of particles comprising the fluids
    static constexpr scalar SpeciesCharges[num_species] = {
        -Constants::ELECTRON_CHARGE / Units::unit_charge,
        -Constants::ELECTRON_CHARGE / Units::unit_charge,
        -Constants::ELECTRON_CHARGE / Units::unit_charge,
        -Constants::ELECTRON_CHARGE / Units::unit_charge,
        Constants::ELECTRON_CHARGE / Units::unit_charge,
        Constants::ELECTRON_CHARGE / Units::unit_charge,
        Constants::ELECTRON_CHARGE / Units::unit_charge,
        Constants::ELECTRON_CHARGE / Units::unit_charge,
        2.0 * Constants::ELECTRON_CHARGE / Units::unit_charge,
        2.0 * Constants::ELECTRON_CHARGE / Units::unit_charge,
        Constants::ELECTRON_CHARGE / Units::unit_charge,
        Constants::ELECTRON_CHARGE / Units::unit_charge,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0
    };

    // Polytropic indices (degrees of freedom)
    static constexpr scalar SpeciesPolytropicIndices[num_species] = {
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0,
        5.0 / 3.0
    };


public: // API:


    // Index of the specie from "SpecieId"
   static constexpr SpecieId id = specieid;
   // printable name
   static constexpr std::string_view name = SpeciesNames[static_cast<size_t>(specieid)];
    // Mass of the particle
   static constexpr scalar mass = SpeciesMasses[static_cast<size_t>(specieid)];
    // Signed charge of the particle
   static constexpr scalar charge = SpeciesCharges[static_cast<size_t>(specieid)];
    // Degrees of freedom
   static constexpr scalar polytropic_index = SpeciesPolytropicIndices[static_cast<size_t>(specieid)];

};


//! Default specie
constexpr SpecieId default_specie = SpecieId::proton_core;


