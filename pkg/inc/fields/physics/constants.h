

#pragma once

#include <fields/physics/unitsystem.h>

//! Conversion of seconds into hours,
// into days, into years.
#define minuteshoursdays \
static constexpr scalar hours(scalar sec) { \
   return sec/3600.0; \
} \
static constexpr scalar days(scalar sec) { \
   return sec/86400.0; \
} \
static constexpr scalar years(scalar sec) { \
   return sec/31536000.0; \
} \


template <
   typename scalar,
   UnitSystem unitsystem
>
struct Constants;


template <typename scalar>
struct Constants<scalar, UnitSystem::CGSM> {
   static constexpr scalar SPEED_OF_LIGHT = (2.99792458e10); /* cm / s */
   static constexpr scalar GRAVITATIONAL_CONSTANT = (6.673e-8); /* cm^3 / g s^2 */
   static constexpr scalar PLANCKS_CONSTANT_H = (6.62606896e-27); /* g cm^2 / s */
   static constexpr scalar PLANCKS_CONSTANT_HBAR = (1.05457162825e-27); /* g cm^2 / s */
   static constexpr scalar ASTRONOMICAL_UNIT = (1.49597870691e13); /* cm */
   static constexpr scalar LIGHT_YEAR = (9.46053620707e17); /* cm */
   static constexpr scalar PARSEC = (3.08567758135e18); /* cm */
   static constexpr scalar GRAV_ACCEL = (9.80665e2); /* cm / s^2 */
   static constexpr scalar ELECTRON_VOLT = (1.602176487e-12); /* g cm^2 / s^2 */
   static constexpr scalar KILO_ELECTRON_VOLT = 1e3*ELECTRON_VOLT;
   static constexpr scalar MEGA_ELECTRON_VOLT = 1e6*ELECTRON_VOLT;
   static constexpr scalar GIGA_ELECTRON_VOLT = 1e9*ELECTRON_VOLT;
   static constexpr scalar MASS_ELECTRON = (9.10938188e-28); /* g */
   static constexpr scalar MASS_MUON = (1.88353109e-25); /* g */
   static constexpr scalar MASS_PROTON = (1.67262158e-24); /* g */
   static constexpr scalar MASS_NEUTRON = (1.67492716e-24); /* g */
   static constexpr scalar RYDBERG = (2.17987196968e-11); /* g cm^2 / s^2 */
   static constexpr scalar BOLTZMANN = (1.3806504e-16); /* g cm^2 / K s^2 */
   static constexpr scalar MOLAR_GAS = (8.314472e7); /* g cm^2 / K mol s^2 */
   static constexpr scalar STANDARD_GAS_VOLUME = (2.2710981e4); /* cm^3 / mol */
   static constexpr scalar MINUTE = (6e1); /* s */
   static constexpr scalar HOUR = (3.6e3); /* s */
   static constexpr scalar DAY = (8.64e4); /* s */
   static constexpr scalar WEEK = (6.048e5); /* s */
   static constexpr scalar INCH = (2.54e0); /* cm */
   static constexpr scalar FOOT = (3.048e1); /* cm */
   static constexpr scalar YARD = (9.144e1); /* cm */
   static constexpr scalar MILE = (1.609344e5); /* cm */
   static constexpr scalar NAUTICAL_MILE = (1.852e5); /* cm */
   static constexpr scalar FATHOM = (1.8288e2); /* cm */
   static constexpr scalar MIL = (2.54e-3); /* cm */
   static constexpr scalar POINT = (3.52777777778e-2); /* cm */
   static constexpr scalar TEXPOINT = (3.51459803515e-2); /* cm */
   static constexpr scalar MICRON = (1e-4); /* cm */
   static constexpr scalar ANGSTROM = (1e-8); /* cm */
   static constexpr scalar HECTARE = (1e8); /* cm^2 */
   static constexpr scalar ACRE = (4.04685642241e7); /* cm^2 */
   static constexpr scalar BARN = (1e-24); /* cm^2 */
   static constexpr scalar LITER = (1e3); /* cm^3 */
   static constexpr scalar US_GALLON = (3.78541178402e3); /* cm^3 */
   static constexpr scalar QUART = (9.46352946004e2); /* cm^3 */
   static constexpr scalar PINT = (4.73176473002e2); /* cm^3 */
   static constexpr scalar CUP = (2.36588236501e2); /* cm^3 */
   static constexpr scalar FLUID_OUNCE = (2.95735295626e1); /* cm^3 */
   static constexpr scalar TABLESPOON = (1.47867647813e1); /* cm^3 */
   static constexpr scalar TEASPOON = (4.92892159375e0); /* cm^3 */
   static constexpr scalar CANADIAN_GALLON = (4.54609e3); /* cm^3 */
   static constexpr scalar UK_GALLON = (4.546092e3); /* cm^3 */
   static constexpr scalar MILES_PER_HOUR = (4.4704e1); /* cm / s */
   static constexpr scalar KILOMETERS_PER_HOUR = (2.77777777778e1); /* cm / s */
   static constexpr scalar KNOT = (5.14444444444e1); /* cm / s */
   static constexpr scalar POUND_MASS = (4.5359237e2); /* g */
   static constexpr scalar OUNCE_MASS = (2.8349523125e1); /* g */
   static constexpr scalar TON = (9.0718474e5); /* g */
   static constexpr scalar METRIC_TON = (1e6); /* g */
   static constexpr scalar UK_TON = (1.0160469088e6); /* g */
   static constexpr scalar TROY_OUNCE = (3.1103475e1); /* g */
   static constexpr scalar CARAT = (2e-1); /* g */
   static constexpr scalar UNIFIED_ATOMIC_MASS = (1.660538782e-24); /* g */
   static constexpr scalar GRAM_FORCE = (9.80665e2); /* cm g / s^2 */
   static constexpr scalar POUND_FORCE = (4.44822161526e5); /* cm g / s^2 */
   static constexpr scalar KILOPOUND_FORCE = (4.44822161526e8); /* cm g / s^2 */
   static constexpr scalar POUNDAL = (1.38255e4); /* cm g / s^2 */
   static constexpr scalar CALORIE = (4.1868e7); /* g cm^2 / s^2 */
   static constexpr scalar BTU = (1.05505585262e10); /* g cm^2 / s^2 */
   static constexpr scalar THERM = (1.05506e15); /* g cm^2 / s^2 */
   static constexpr scalar HORSEPOWER = (7.457e9); /* g cm^2 / s^3 */
   static constexpr scalar BAR = (1e6); /* g / cm s^2 */
   static constexpr scalar STD_ATMOSPHERE = (1.01325e6); /* g / cm s^2 */
   static constexpr scalar TORR = (1.33322368421e3); /* g / cm s^2 */
   static constexpr scalar METER_OF_MERCURY = (1.33322368421e6); /* g / cm s^2 */
   static constexpr scalar INCH_OF_MERCURY = (3.38638815789e4); /* g / cm s^2 */
   static constexpr scalar INCH_OF_WATER = (2.490889e3); /* g / cm s^2 */
   static constexpr scalar PSI = (6.89475729317e4); /* g / cm s^2 */
   static constexpr scalar POISE = (1e0); /* g / cm s */
   static constexpr scalar STOKES = (1e0); /* cm^2 / s */
   static constexpr scalar STILB = (1e0); /* cd / cm^2 */
   static constexpr scalar LUMEN = (1e0); /* cd sr */
   static constexpr scalar LUX = (1e-4); /* cd sr / cm^2 */
   static constexpr scalar PHOT = (1e0); /* cd sr / cm^2 */
   static constexpr scalar FOOTCANDLE = (1.076e-3); /* cd sr / cm^2 */
   static constexpr scalar LAMBERT = (1e0); /* cd sr / cm^2 */
   static constexpr scalar FOOTLAMBERT = (1.07639104e-3); /* cd sr / cm^2 */
   static constexpr scalar CURIE = (3.7e10); /* 1 / s */
   static constexpr scalar ROENTGEN = (2.58e-8); /* abamp s / g */
   static constexpr scalar RAD = (1e2); /* cm^2 / s^2 */
   static constexpr scalar SOLAR_MASS = (1.98892e33); /* g */
   static constexpr scalar BOHR_RADIUS = (5.291772083e-9); /* cm */
   static constexpr scalar NEWTON = (1e5); /* cm g / s^2 */
   static constexpr scalar DYNE = (1e0); /* cm g / s^2 */
   static constexpr scalar JOULE = (1e7); /* g cm^2 / s^2 */
   static constexpr scalar ERG = (1e0); /* g cm^2 / s^2 */
   static constexpr scalar STEFAN_BOLTZMANN_CONSTANT = (5.67040047374e-5); /* g / K^4 s^3 */
   static constexpr scalar THOMSON_CROSS_SECTION = (6.65245893699e-25); /* cm^2 */
   static constexpr scalar BOHR_MAGNETON = (9.27400899e-21); /* abamp cm^2 */
   static constexpr scalar NUCLEAR_MAGNETON = (5.05078317e-24); /* abamp cm^2 */
   static constexpr scalar ELECTRON_MAGNETIC_MOMENT = (9.28476362e-21); /* abamp cm^2 */
   static constexpr scalar PROTON_MAGNETIC_MOMENT = (1.410606633e-23); /* abamp cm^2 */
   static constexpr scalar FARADAY = (9.64853429775e3); /* abamp s / mol */
   static constexpr scalar ELECTRON_CHARGE = (1.602176487e-20); /* abamp s */

   minuteshoursdays

};



template <typename scalar>
struct Constants<scalar, UnitSystem::MKSA> {
   static constexpr scalar SPEED_OF_LIGHT = (2.99792458e8); /* m / s */
   static constexpr scalar GRAVITATIONAL_CONSTANT = (6.673e-11); /* m^3 / kg s^2 */
   static constexpr scalar PLANCKS_CONSTANT_H = (6.62606896e-34); /* kg m^2 / s */
   static constexpr scalar PLANCKS_CONSTANT_HBAR = (1.05457162825e-34); /* kg m^2 / s */
   static constexpr scalar ASTRONOMICAL_UNIT = (1.49597870691e11); /* m */
   static constexpr scalar LIGHT_YEAR = (9.46053620707e15); /* m */
   static constexpr scalar PARSEC = (3.08567758135e16); /* m */
   static constexpr scalar GRAV_ACCEL = (9.80665e0); /* m / s^2 */
   static constexpr scalar ELECTRON_VOLT = (1.602176487e-19); /* kg m^2 / s^2 */
   static constexpr scalar KILO_ELECTRON_VOLT = 1e3*ELECTRON_VOLT;
   static constexpr scalar MEGA_ELECTRON_VOLT = 1e6*ELECTRON_VOLT;
   static constexpr scalar GIGA_ELECTRON_VOLT = 1e9*ELECTRON_VOLT;
   static constexpr scalar MASS_ELECTRON = (9.10938188e-31); /* kg */
   static constexpr scalar MASS_MUON = (1.88353109e-28); /* kg */
   static constexpr scalar MASS_PROTON = (1.67262158e-27); /* kg */
   static constexpr scalar MASS_NEUTRON = (1.67492716e-27); /* kg */
   static constexpr scalar RYDBERG = (2.17987196968e-18); /* kg m^2 / s^2 */
   static constexpr scalar BOLTZMANN = (1.3806504e-23); /* kg m^2 / K s^2 */
   static constexpr scalar MOLAR_GAS = (8.314472e0); /* kg m^2 / K mol s^2 */
   static constexpr scalar STANDARD_GAS_VOLUME = (2.2710981e-2); /* m^3 / mol */
   static constexpr scalar MINUTE = (6e1); /* s */
   static constexpr scalar HOUR = (3.6e3); /* s */
   static constexpr scalar DAY = (8.64e4); /* s */
   static constexpr scalar WEEK = (6.048e5); /* s */
   static constexpr scalar INCH = (2.54e-2); /* m */
   static constexpr scalar FOOT = (3.048e-1); /* m */
   static constexpr scalar YARD = (9.144e-1); /* m */
   static constexpr scalar MILE = (1.609344e3); /* m */
   static constexpr scalar NAUTICAL_MILE = (1.852e3); /* m */
   static constexpr scalar FATHOM = (1.8288e0); /* m */
   static constexpr scalar MIL = (2.54e-5); /* m */
   static constexpr scalar POINT = (3.52777777778e-4); /* m */
   static constexpr scalar TEXPOINT = (3.51459803515e-4); /* m */
   static constexpr scalar MICRON = (1e-6); /* m */
   static constexpr scalar ANGSTROM = (1e-10); /* m */
   static constexpr scalar HECTARE = (1e4); /* m^2 */
   static constexpr scalar ACRE = (4.04685642241e3); /* m^2 */
   static constexpr scalar BARN = (1e-28); /* m^2 */
   static constexpr scalar LITER = (1e-3); /* m^3 */
   static constexpr scalar US_GALLON = (3.78541178402e-3); /* m^3 */
   static constexpr scalar QUART = (9.46352946004e-4); /* m^3 */
   static constexpr scalar PINT = (4.73176473002e-4); /* m^3 */
   static constexpr scalar CUP = (2.36588236501e-4); /* m^3 */
   static constexpr scalar FLUID_OUNCE = (2.95735295626e-5); /* m^3 */
   static constexpr scalar TABLESPOON = (1.47867647813e-5); /* m^3 */
   static constexpr scalar TEASPOON = (4.92892159375e-6); /* m^3 */
   static constexpr scalar CANADIAN_GALLON = (4.54609e-3); /* m^3 */
   static constexpr scalar UK_GALLON = (4.546092e-3); /* m^3 */
   static constexpr scalar MILES_PER_HOUR = (4.4704e-1); /* m / s */
   static constexpr scalar KILOMETERS_PER_HOUR = (2.77777777778e-1); /* m / s */
   static constexpr scalar KNOT = (5.14444444444e-1); /* m / s */
   static constexpr scalar POUND_MASS = (4.5359237e-1); /* kg */
   static constexpr scalar OUNCE_MASS = (2.8349523125e-2); /* kg */
   static constexpr scalar TON = (9.0718474e2); /* kg */
   static constexpr scalar METRIC_TON = (1e3); /* kg */
   static constexpr scalar UK_TON = (1.0160469088e3); /* kg */
   static constexpr scalar TROY_OUNCE = (3.1103475e-2); /* kg */
   static constexpr scalar CARAT = (2e-4); /* kg */
   static constexpr scalar UNIFIED_ATOMIC_MASS = (1.660538782e-27); /* kg */
   static constexpr scalar GRAM_FORCE = (9.80665e-3); /* kg m / s^2 */
   static constexpr scalar POUND_FORCE = (4.44822161526e0); /* kg m / s^2 */
   static constexpr scalar KILOPOUND_FORCE = (4.44822161526e3); /* kg m / s^2 */
   static constexpr scalar POUNDAL = (1.38255e-1); /* kg m / s^2 */
   static constexpr scalar CALORIE = (4.1868e0); /* kg m^2 / s^2 */
   static constexpr scalar BTU = (1.05505585262e3); /* kg m^2 / s^2 */
   static constexpr scalar THERM = (1.05506e8); /* kg m^2 / s^2 */
   static constexpr scalar HORSEPOWER = (7.457e2); /* kg m^2 / s^3 */
   static constexpr scalar BAR = (1e5); /* kg / m s^2 */
   static constexpr scalar STD_ATMOSPHERE = (1.01325e5); /* kg / m s^2 */
   static constexpr scalar TORR = (1.33322368421e2); /* kg / m s^2 */
   static constexpr scalar METER_OF_MERCURY = (1.33322368421e5); /* kg / m s^2 */
   static constexpr scalar INCH_OF_MERCURY = (3.38638815789e3); /* kg / m s^2 */
   static constexpr scalar INCH_OF_WATER = (2.490889e2); /* kg / m s^2 */
   static constexpr scalar PSI = (6.89475729317e3); /* kg / m s^2 */
   static constexpr scalar POISE = (1e-1); /* kg m^-1 s^-1 */
   static constexpr scalar STOKES = (1e-4); /* m^2 / s */
   static constexpr scalar STILB = (1e4); /* cd / m^2 */
   static constexpr scalar LUMEN = (1e0); /* cd sr */
   static constexpr scalar LUX = (1e0); /* cd sr / m^2 */
   static constexpr scalar PHOT = (1e4); /* cd sr / m^2 */
   static constexpr scalar FOOTCANDLE = (1.076e1); /* cd sr / m^2 */
   static constexpr scalar LAMBERT = (1e4); /* cd sr / m^2 */
   static constexpr scalar FOOTLAMBERT = (1.07639104e1); /* cd sr / m^2 */
   static constexpr scalar CURIE = (3.7e10); /* 1 / s */
   static constexpr scalar ROENTGEN = (2.58e-4); /* A s / kg */
   static constexpr scalar RAD = (1e-2); /* m^2 / s^2 */
   static constexpr scalar SOLAR_MASS = (1.98892e30); /* kg */
   static constexpr scalar BOHR_RADIUS = (5.291772083e-11); /* m */
   static constexpr scalar NEWTON = (1e0); /* kg m / s^2 */
   static constexpr scalar DYNE = (1e-5); /* kg m / s^2 */
   static constexpr scalar JOULE = (1e0); /* kg m^2 / s^2 */
   static constexpr scalar ERG = (1e-7); /* kg m^2 / s^2 */
   static constexpr scalar STEFAN_BOLTZMANN_CONSTANT = (5.67040047374e-8); /* kg / K^4 s^3 */
   static constexpr scalar THOMSON_CROSS_SECTION = (6.65245893699e-29); /* m^2 */
   static constexpr scalar BOHR_MAGNETON = (9.27400899e-24); /* A m^2 */
   static constexpr scalar NUCLEAR_MAGNETON = (5.05078317e-27); /* A m^2 */
   static constexpr scalar ELECTRON_MAGNETIC_MOMENT = (9.28476362e-24); /* A m^2 */
   static constexpr scalar PROTON_MAGNETIC_MOMENT = (1.410606633e-26); /* A m^2 */
   static constexpr scalar FARADAY = (9.64853429775e4); /* A s / mol */
   static constexpr scalar ELECTRON_CHARGE = (1.602176487e-19); /* A s */
   static constexpr scalar VACUUM_PERMITTIVITY = (8.854187817e-12); /* A^2 s^4 / kg m^3 */
   static constexpr scalar VACUUM_PERMEABILITY = (1.25663706144e-6); /* kg m / A^2 s^2 */
   static constexpr scalar DEBYE = (3.33564095198e-30); /* A s^2 / m^2 */
   static constexpr scalar GAUSS = (1e-4); /* kg / A s^2 */

   minuteshoursdays

};


template <typename scalar>
struct Constants<scalar, UnitSystem::CGS> {
   static constexpr scalar SPEED_OF_LIGHT = (2.99792458e10); /* cm / s */
   static constexpr scalar GRAVITATIONAL_CONSTANT = (6.673e-8); /* cm^3 / g s^2 */
   static constexpr scalar PLANCKS_CONSTANT_H = (6.62606896e-27); /* g cm^2 / s */
   static constexpr scalar PLANCKS_CONSTANT_HBAR = (1.05457162825e-27); /* g cm^2 / s */
   static constexpr scalar ASTRONOMICAL_UNIT = (1.49597870691e13); /* cm */
   static constexpr scalar LIGHT_YEAR = (9.46053620707e17); /* cm */
   static constexpr scalar PARSEC = (3.08567758135e18); /* cm */
   static constexpr scalar GRAV_ACCEL = (9.80665e2); /* cm / s^2 */
   static constexpr scalar ELECTRON_VOLT = (1.602176487e-12); /* g cm^2 / s^2 */
   static constexpr scalar KILO_ELECTRON_VOLT = 1e3*ELECTRON_VOLT;
   static constexpr scalar MEGA_ELECTRON_VOLT = 1e6*ELECTRON_VOLT;
   static constexpr scalar GIGA_ELECTRON_VOLT = 1e9*ELECTRON_VOLT;
   static constexpr scalar MASS_ELECTRON = (9.10938188e-28); /* g */
   static constexpr scalar MASS_MUON = (1.88353109e-25); /* g */
   static constexpr scalar MASS_PROTON = (1.67262158e-24); /* g */
   static constexpr scalar MASS_NEUTRON = (1.67492716e-24); /* g */
   static constexpr scalar RYDBERG = (2.17987196968e-11); /* g cm^2 / s^2 */
   static constexpr scalar BOLTZMANN = (1.3806504e-16); /* g cm^2 / K s^2 */
   static constexpr scalar MOLAR_GAS = (8.314472e7); /* g cm^2 / K mol s^2 */
   static constexpr scalar STANDARD_GAS_VOLUME = (2.2710981e4); /* cm^3 / mol */
   static constexpr scalar MINUTE = (6e1); /* s */
   static constexpr scalar HOUR = (3.6e3); /* s */
   static constexpr scalar DAY = (8.64e4); /* s */
   static constexpr scalar WEEK = (6.048e5); /* s */
   static constexpr scalar INCH = (2.54e0); /* cm */
   static constexpr scalar FOOT = (3.048e1); /* cm */
   static constexpr scalar YARD = (9.144e1); /* cm */
   static constexpr scalar MILE = (1.609344e5); /* cm */
   static constexpr scalar NAUTICAL_MILE = (1.852e5); /* cm */
   static constexpr scalar FATHOM = (1.8288e2); /* cm */
   static constexpr scalar MIL = (2.54e-3); /* cm */
   static constexpr scalar POINT = (3.52777777778e-2); /* cm */
   static constexpr scalar TEXPOINT = (3.51459803515e-2); /* cm */
   static constexpr scalar MICRON = (1e-4); /* cm */
   static constexpr scalar ANGSTROM = (1e-8); /* cm */
   static constexpr scalar HECTARE = (1e8); /* cm^2 */
   static constexpr scalar ACRE = (4.04685642241e7); /* cm^2 */
   static constexpr scalar BARN = (1e-24); /* cm^2 */
   static constexpr scalar LITER = (1e3); /* cm^3 */
   static constexpr scalar US_GALLON = (3.78541178402e3); /* cm^3 */
   static constexpr scalar QUART = (9.46352946004e2); /* cm^3 */
   static constexpr scalar PINT = (4.73176473002e2); /* cm^3 */
   static constexpr scalar CUP = (2.36588236501e2); /* cm^3 */
   static constexpr scalar FLUID_OUNCE = (2.95735295626e1); /* cm^3 */
   static constexpr scalar TABLESPOON = (1.47867647813e1); /* cm^3 */
   static constexpr scalar TEASPOON = (4.92892159375e0); /* cm^3 */
   static constexpr scalar CANADIAN_GALLON = (4.54609e3); /* cm^3 */
   static constexpr scalar UK_GALLON = (4.546092e3); /* cm^3 */
   static constexpr scalar MILES_PER_HOUR = (4.4704e1); /* cm / s */
   static constexpr scalar KILOMETERS_PER_HOUR = (2.77777777778e1); /* cm / s */
   static constexpr scalar KNOT = (5.14444444444e1); /* cm / s */
   static constexpr scalar POUND_MASS = (4.5359237e2); /* g */
   static constexpr scalar OUNCE_MASS = (2.8349523125e1); /* g */
   static constexpr scalar TON = (9.0718474e5); /* g */
   static constexpr scalar METRIC_TON = (1e6); /* g */
   static constexpr scalar UK_TON = (1.0160469088e6); /* g */
   static constexpr scalar TROY_OUNCE = (3.1103475e1); /* g */
   static constexpr scalar CARAT = (2e-1); /* g */
   static constexpr scalar UNIFIED_ATOMIC_MASS = (1.660538782e-24); /* g */
   static constexpr scalar GRAM_FORCE = (9.80665e2); /* cm g / s^2 */
   static constexpr scalar POUND_FORCE = (4.44822161526e5); /* cm g / s^2 */
   static constexpr scalar KILOPOUND_FORCE = (4.44822161526e8); /* cm g / s^2 */
   static constexpr scalar POUNDAL = (1.38255e4); /* cm g / s^2 */
   static constexpr scalar CALORIE = (4.1868e7); /* g cm^2 / s^2 */
   static constexpr scalar BTU = (1.05505585262e10); /* g cm^2 / s^2 */
   static constexpr scalar THERM = (1.05506e15); /* g cm^2 / s^2 */
   static constexpr scalar HORSEPOWER = (7.457e9); /* g cm^2 / s^3 */
   static constexpr scalar BAR = (1e6); /* g / cm s^2 */
   static constexpr scalar STD_ATMOSPHERE = (1.01325e6); /* g / cm s^2 */
   static constexpr scalar TORR = (1.33322368421e3); /* g / cm s^2 */
   static constexpr scalar METER_OF_MERCURY = (1.33322368421e6); /* g / cm s^2 */
   static constexpr scalar INCH_OF_MERCURY = (3.38638815789e4); /* g / cm s^2 */
   static constexpr scalar INCH_OF_WATER = (2.490889e3); /* g / cm s^2 */
   static constexpr scalar PSI = (6.89475729317e4); /* g / cm s^2 */
   static constexpr scalar POISE = (1e0); /* g / cm s */
   static constexpr scalar STOKES = (1e0); /* cm^2 / s */
   static constexpr scalar STILB = (1e0); /* cd / cm^2 */
   static constexpr scalar LUMEN = (1e0); /* cd sr */
   static constexpr scalar LUX = (1e-4); /* cd sr / cm^2 */
   static constexpr scalar PHOT = (1e0); /* cd sr / cm^2 */
   static constexpr scalar FOOTCANDLE = (1.076e-3); /* cd sr / cm^2 */
   static constexpr scalar LAMBERT = (1e0); /* cd sr / cm^2 */
   static constexpr scalar FOOTLAMBERT = (1.07639104e-3); /* cd sr / cm^2 */
   static constexpr scalar CURIE = (3.7e10); /* 1 / s */
   static constexpr scalar ROENTGEN = (2.58e-7); /* A s / g */
   static constexpr scalar RAD = (1e2); /* cm^2 / s^2 */
   static constexpr scalar SOLAR_MASS = (1.98892e33); /* g */
   static constexpr scalar BOHR_RADIUS = (5.291772083e-9); /* cm */
   static constexpr scalar NEWTON = (1e5); /* cm g / s^2 */
   static constexpr scalar DYNE = (1e0); /* cm g / s^2 */
   static constexpr scalar JOULE = (1e7); /* g cm^2 / s^2 */
   static constexpr scalar ERG = (1e0); /* g cm^2 / s^2 */
   static constexpr scalar STEFAN_BOLTZMANN_CONSTANT = (5.67040047374e-5); /* g / K^4 s^3 */
   static constexpr scalar THOMSON_CROSS_SECTION = (6.65245893699e-25); /* cm^2 */

   minuteshoursdays

};


#undef minuteshoursdays
