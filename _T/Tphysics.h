
#pragma once

#include <Tbasis.h>

// todo fix header gore
#include <fields/physics/constants.h>
#include <fields/physics/units.h>
#include <fields/compiletime/lists.h>
#include <fields/compiletime/math.h>

#include <fields/physics/physics.h>


class Tphysics {


public:

    using scalar = double;

    using Math = Math<scalar>;

    using ParticleUnits = ParticleUnits<scalar, UnitSystem::CGSM>;
    using FluidUnits = FluidUnits<scalar, UnitSystem::CGSM>;


    using Particle = Particle<ParticleUnits, default_specie>;
    using Fluid = Fluid<FluidUnits, default_specie>;

    using Proton = Specie<ParticleUnits, SpecieId::proton_core>;

   //! Print all units and test each conversion routine
   static void TestPhysics() {
       cout << endl;

       using Constants = Constants<double, UnitSystem::CGSM>;

       cout << "-------------------------------Physical constants-------------------------------\n";
       cout << "CGS speed of light: " << Constants::SPEED_OF_LIGHT << "⨯cm⨯s⁻¹\n";
       cout << "CGS mass of electron: " << Constants::MASS_ELECTRON << "⨯g\n";
       cout << "CGS mass of proton: " << Constants::MASS_PROTON << "⨯g\n";
       cout << "CGS electron charge: " << Constants::ELECTRON_CHARGE << "⨯Fr\n";
       cout << "CGS Boltzmann constant: " << Constants::BOLTZMANN << "⨯erg⨯K⁻¹\n";
       cout << "CGS astronomical unit: " << Constants::ASTRONOMICAL_UNIT << "⨯cm\n";
       cout << "CGS electron volt: " << Constants::ELECTRON_VOLT << "⨯erg\n";
       cout << endl;

       cout << "---------------------------------Particle-units---------------------------------\n";
       cout << "Unit of length: " << Particle::unit_length << "⨯cm\n";
       cout << "Unit of velocity: " << Particle::unit_velocity << "⨯cm⨯s⁻¹\n";
       cout << "Unit of mass: " << Particle::unit_mass << "⨯g\n";
       cout << "Unit of charge: " << Particle::unit_charge << "⨯Fr\n";
       cout << "Unit of temperature: " << Particle::unit_temperature << "⨯K\n";
       cout << "Unit of momentum: " << Particle::unit_momentum << "⨯g⨯cm⨯s⁻¹\n";
       cout << "Unit of energy: " << Particle::unit_energy << "⨯erg or " << Particle::unit_energy / Constants::MEGA_ELECTRON_VOLT << "⨯MeV\n";
       cout << "Unit of rigidity: " << Particle::unit_rigidity << " erg*Fr^-1\n";
       cout << "Unit of time: " << Particle::unit_time << "⨯s\n";
       cout << "Unit of force: " << Particle::unit_force << "⨯g⨯cm⨯s⁻²\n";
       cout << "Unit of magnetic field: " << Particle::unit_magnetic << "⨯G\n";
       cout << "Unit of diffusion: " << Particle::unit_diffusion << "⨯cm²⨯s⁻¹\n";
       cout << "Unit of magnetic moment: " << Particle::unit_magnetic_moment << "⨯Fr⨯cm\n";
//   cout << "EM to particle conversion unit: " << Particle::charge_conv << "\n";
       cout << endl;

       cout << "----------------------------------Fluid-units-----------------------------------\n";

       cout << "Unit of length: " << Fluid::unit_length << "⨯cm or " << Fluid::unit_length / Constants::ASTRONOMICAL_UNIT << "⨯au\n";
       cout << "Unit of velocity: " << Fluid::unit_velocity << "⨯cm⨯s⁻¹\n";
       cout << "Unit of mass: " << Fluid::unit_mass << "⨯g\n";
       cout << "Unit of time: " << Fluid::unit_time << "⨯s\n";
       cout << "Unit of number density: " << Fluid::unit_number_density << "⨯cm^⁻³\n";
       cout << "Unit of temperature: " << Fluid::unit_temperature << "⨯K\n";
       cout << "Unit of density: " << Fluid::unit_density << "⨯g⨯cm^⁻³\n";
       cout << "Unit of pressure: " << Fluid::unit_pressure << "⨯dyn⨯cm⁻²\n";
       cout << "Unit of magnetic field: " << Fluid::unit_magnetic << "⨯G\n";
       cout << endl;

       cout << "-----------------------------Testing fluid routines-----------------------------\n";

       std::string message;
       double res1, res2;

       double m_cgs = Proton::mass * Particle::unit_mass;
       double n_cgs = 0.14;
       double rho_cgs = n_cgs * Constants::MASS_PROTON;
       double T_cgs = 7.0E4;
       double P_cgs = n_cgs * Constants::BOLTZMANN * T_cgs;
       double u_cgs = 1.0E7;
       GeoVector B_cgs = {double754(1.5E-6), double754(-2.5E-6), double754(-4.2E-6)};
       double Bmag_cgs = B_cgs.Norm();
       double e_cgs = 10.5 * P_cgs;
       double Cs_cgs = 8.0E6;
       double Va_cgs = 4.6E6;
       double alpha = DegToRad(40.0);
       double vth_cgs = 1.3E7;

       message = "Pressure at " + std::format("n={:.3e}⨯cm⁻³, ",  n_cgs)
                 + std::format("T={:.3e}⨯K", T_cgs);
       res1 = Fluid::Pressure(n_cgs / Fluid::unit_number_density, T_cgs / Fluid::unit_temperature);
       res2 = P_cgs / Fluid::unit_pressure;
       PrintPassFail(message, res1, res2);

       message = "Energy density at " + std::format("ρ={:.3e}⨯g⨯cm⁻³, ", rho_cgs)
                 + std::format("u={:.3e}⨯cm⨯s⁻¹, ", u_cgs)
                 + std::format("P={:.3e}⨯dyn⨯cm⁻², ", P_cgs)
                 + std::format("B={:.3e}⨯G", Bmag_cgs);

       res1 = Fluid::EnergyDensity(rho_cgs / Fluid::unit_density,  Math::Sqr(u_cgs / Fluid::unit_velocity),
                                           P_cgs / Fluid::unit_pressure, Math::Sqr(Bmag_cgs / Fluid::unit_magnetic));
       res2 = (0.5 * rho_cgs * Math::Sqr(u_cgs) + P_cgs / (Proton::polytropic_index - 1.0) + Math::Sqr(Bmag_cgs) / M_8PI) / Fluid::unit_pressure;
       PrintPassFail(message, res1, res2);

       message = "Pressure at " + std::format("ρ={:.3e}⨯g⨯cm⁻³, ", rho_cgs)
                 + std::format("u={:.3e}⨯cm⨯s⁻¹, ", u_cgs)
                 + std::format("ε={:.3e}⨯dyn⨯cm⁻², ", e_cgs)
                 + std::format("B={:.3e}⨯G", Bmag_cgs);
       res1 = Fluid::Pressure(rho_cgs / Fluid::unit_density,  Math::Sqr(u_cgs / Fluid::unit_velocity),
                                      e_cgs / Fluid::unit_pressure, Math::Sqr(Bmag_cgs / Fluid::unit_magnetic));
       res2 = (e_cgs - 0.5 * rho_cgs * Math::Sqr(u_cgs) - Math::Sqr(Bmag_cgs) * Math::oneo8pi) * (Proton::polytropic_index - 1.0) / Fluid::unit_pressure;
       PrintPassFail(message, res1, res2);


       message = "Sound speed at " + std::format("ρ={:.3e}⨯g⨯cm⁻³, ", rho_cgs)
                 + std::format("P={:.3e}⨯dyn⨯cm⁻², ", P_cgs);
       res1 = Fluid::SoundSpeed(rho_cgs / Fluid::unit_density, P_cgs / Fluid::unit_pressure);
       res2 = sqrt(Proton::polytropic_index * P_cgs / rho_cgs) / Fluid::unit_velocity;
       PrintPassFail(message, res1, res2);

       message = "Alfven speed at " + std::format("ρ={:.3e}⨯g⨯cm⁻³, ", rho_cgs)
                 + std::format("B={:.3e}⨯G", Bmag_cgs);
       res1 = Fluid::AlfvenSpeed(rho_cgs / Fluid::unit_density, Math::Sqr(Bmag_cgs) / Fluid::unit_pressure);
       res2 = Bmag_cgs / sqrt(Math::fourpi * rho_cgs) / Fluid::unit_velocity;
       PrintPassFail(message, res1, res2);

       message = "Fast magnetosonic speed at " + std::format("Cs={:.3e}⨯cm⨯s⁻¹, ", Cs_cgs)
                 + std::format("Va={:.3e}⨯cm⨯s⁻¹, ", Va_cgs)
                 + std::format("alpha={:.3e}", alpha);
       res1 = Fluid::FastMagnetosonicSpeed(Math::Sqr(Cs_cgs / Fluid::unit_velocity), Math::Sqr(Va_cgs / Fluid::unit_velocity), Math::Sqr(cos(alpha)));
       res2 = sqrt(Math::Sqr(Cs_cgs) + Math::Sqr(Va_cgs) + sqrt(Math::Sqr(Math::Sqr(Cs_cgs) + Math::Sqr(Va_cgs)) - Math::Sqr(2.0 * Cs_cgs * Va_cgs * cos(alpha))))
              / M_SQRT2 / Fluid::unit_velocity;
       PrintPassFail(message, res1, res2);

       message = "Slow magnetosonic speed at " + std::format("Cs={:.3e}⨯cm⨯s⁻¹, ", Cs_cgs)
                 + std::format("Va={:.3e}⨯cm⨯s⁻¹, ", Va_cgs)
                 + std::format("alpha={:.3e}", alpha);
       res1 = Fluid::SlowMagnetosonicSpeed(Math::Sqr(Cs_cgs / Fluid::unit_velocity), Math::Sqr(Va_cgs / Fluid::unit_velocity), Math::Sqr(cos(alpha)));
       res2 = sqrt(Math::Sqr(Cs_cgs) + Math::Sqr(Va_cgs) - sqrt(Math::Sqr(Math::Sqr(Cs_cgs) + Math::Sqr(Va_cgs)) - Math::Sqr(2.0 * Cs_cgs * Va_cgs * cos(alpha))))
              / M_SQRT2 / Fluid::unit_velocity;
       PrintPassFail(message, res1, res2);

       message = "Temperature at " + std::format("v_th={:.3e}⨯cm⨯s⁻¹", vth_cgs);
       res1 = Fluid::EffectiveTemperature(vth_cgs / Fluid::unit_velocity);
       res2 = m_cgs * Math::Sqr(vth_cgs) / (2.0 * Constants::BOLTZMANN) / Fluid::unit_temperature;
       PrintPassFail(message, res1, res2);

       cout << endl;

       cout << "----------------------Testing particle/particle routines------------------------\n";

       const CoordinateSystem vel_sys = CoordinateSystem::Cartesian;
       double q_cgs = Proton::charge * Particle::unit_charge;
       GeoVector v_cgs = GeoVector(0.23, 0.05, 0.56) * Constants::SPEED_OF_LIGHT;
       double vmag_cgs = v_cgs.Norm();
       GeoVector p_cgs = GeoVector(0.27, 0.41, -0.13) * m_cgs * Constants::SPEED_OF_LIGHT;
       double pmag_cgs = p_cgs.Norm();
       double K_cgs = 0.23 * m_cgs * Math::Sqr(Constants::SPEED_OF_LIGHT);
       GeoVector E_cgs = 1.0E-5 * B_cgs;
       double Emag_cgs = E_cgs.Norm();
       double mag_mom_cgs = q_cgs * 2.7E11;
       double ppara_cgs = (p_cgs * B_cgs) / B_cgs.Norm();

       // todo when using Particle, the units
       //  should not have to be mixed in at this level.
       //  The Particle class knows your code units
       //  and should return values in those units.

       message = "Relativistic factor at " + std::format("v={:.3e}⨯cm⨯s⁻¹", vmag_cgs);
       res1 = Particle::RelFactor(vmag_cgs / Particle::unit_velocity);
       double rel = 1.0 / sqrt(1.0 - Math::Sqr(vmag_cgs / Constants::SPEED_OF_LIGHT));
       res2 = rel;
       PrintPassFail(message, res1, res2);

       message = "Relativistic factor at " + std::format("p={:.3e}⨯g⨯cm⨯s⁻¹", pmag_cgs);
       res1 = Particle::RelFactor1(pmag_cgs / Particle::unit_momentum);
       res2 = sqrt(1.0 + Math::Sqr(pmag_cgs / (m_cgs * Constants::SPEED_OF_LIGHT)));
       PrintPassFail(message, res1, res2);

       message = "Momentum at " + std::format("K={:.3e}⨯erg", K_cgs);
       res1 = Particle::Mom(K_cgs / Particle::unit_energy);
       res2 = sqrt(K_cgs * (K_cgs / Math::Sqr(Constants::SPEED_OF_LIGHT) + 2.0 * m_cgs)) / Particle::unit_momentum;
       PrintPassFail(message, res1, res2);

       message = "Total energy at " + std::format("p={:.3e}⨯g⨯cm⨯s⁻¹", pmag_cgs);
       res1 = Particle::EnrTot(pmag_cgs / Particle::unit_momentum);
       double Et_cgs = sqrt(Math::Sqr(pmag_cgs) + Math::Sqr(m_cgs * Constants::SPEED_OF_LIGHT)) * Constants::SPEED_OF_LIGHT;
       res2 = Et_cgs / Particle::unit_energy;
       PrintPassFail(message, res1, res2);

       message = "Kinetic energy at " + std::format("p={:.3e}⨯g⨯cm⨯s⁻¹", pmag_cgs);
       res1 = Particle::EnrKin(pmag_cgs / Particle::unit_momentum);
       res2 = (Et_cgs - m_cgs * Math::Sqr(Constants::SPEED_OF_LIGHT)) / Particle::unit_energy;
       PrintPassFail(message, res1, res2);

       message = "Velocity at " + std::format("p={:.3e}⨯g⨯cm⨯s⁻¹", pmag_cgs);
       res1 = Particle::Vel(pmag_cgs / Particle::unit_momentum);
       res2 = pmag_cgs * Math::Sqr(Constants::SPEED_OF_LIGHT) / Et_cgs / Particle::unit_velocity;
       PrintPassFail(message, res1, res2);

       message = "Velocity at " + std::format("p={:.3e}⨯g⨯cm⨯s⁻¹", pmag_cgs);
       res1 = Particle::Vel<specie, vel_sys>(p_cgs / Particle::unit_momentum).Norm();
       res2 = p_cgs.Norm() * Math::Sqr(Constants::SPEED_OF_LIGHT) / Et_cgs / Particle::unit_velocity;
       PrintPassFail(message, res1, res2);

       message = "Momentum at " + std::format("v={:.3e}⨯cm⨯s⁻¹", vmag_cgs);
       res1 = Particle::Mom<specie, vel_sys>(v_cgs / Particle::unit_velocity).Norm();
       res2 = m_cgs * v_cgs.Norm() / sqrt(1.0 - Math::Sqr(v_cgs.Norm() / Constants::SPEED_OF_LIGHT)) / Particle::unit_momentum;
       PrintPassFail(message, res1, res2);

       message = "Rigidity at " + std::format("p={:.3e}⨯g⨯cm⨯s⁻¹", pmag_cgs);
       res1 = Particle::Rigidity(pmag_cgs / Particle::unit_momentum);
       res2 = pmag_cgs * Constants::SPEED_OF_LIGHT / q_cgs / Particle::unit_rigidity;
       PrintPassFail(message, res1, res2);

       message = "Temperature at " + std::format("v_th={:.3e}⨯cm⨯s⁻¹", vth_cgs);
       res1 = Particle::EffectiveTemperature(vth_cgs / Particle::unit_velocity);
       res2 = m_cgs * Math::Sqr(vth_cgs) / (2.0 * Constants::BOLTZMANN) / Particle::unit_temperature;
       PrintPassFail(message, res1, res2);

       cout << endl;

       cout << "------------------------Testing particle/fluid routines-------------------------\n";

       message = "Induced Electric field at " + std::format("v={:.3e}⨯cm⨯s⁻¹, ", vmag_cgs)
                 + std::format("B={:.3e}⨯G", Bmag_cgs);
       res1 = Particle::InducedEfield(v_cgs / Particle::unit_velocity, B_cgs / Particle::unit_magnetic).Norm();
       res2 = (v_cgs ^ B_cgs).Norm() / Constants::SPEED_OF_LIGHT / Particle::unit_magnetic;
       PrintPassFail(message, res1, res2);

       message = "Lorentz force at " + std::format("v={:.3e}⨯cm⨯s⁻¹, ", vmag_cgs)
                 + std::format("E={:.3e}⨯G, ", Emag_cgs)
                 + std::format("B={:.3e}⨯G", Bmag_cgs);
       res1 = Particle::LorentzForce(v_cgs / Particle::unit_velocity, E_cgs / Particle::unit_magnetic, B_cgs / Particle::unit_magnetic).Norm();
       res2 = q_cgs * (E_cgs + (v_cgs ^ B_cgs) / Constants::SPEED_OF_LIGHT).Norm() / Particle::unit_force;
       PrintPassFail(message, res1, res2);

       message = "Thermal speed at " + std::format("T={:.3e}⨯K", T_cgs);
       res1 = Particle::ThermalSpeed(T_cgs / Particle::unit_temperature);
       res2 = sqrt(2.0 * Constants::BOLTZMANN * T_cgs / m_cgs) / Particle::unit_velocity;
       PrintPassFail(message, res1, res2);

       message = "Cyclotron frequency at " + std::format("v={:.3e}⨯cm⨯s⁻¹, ", vmag_cgs)
                 + std::format("B={:.3e}⨯G", Bmag_cgs);
       res1 = Particle::CyclotronFrequency(vmag_cgs / Particle::unit_velocity, Bmag_cgs / Particle::unit_magnetic);
       res2 = q_cgs * Bmag_cgs / (rel * m_cgs * Constants::SPEED_OF_LIGHT) * Particle::unit_time;
       PrintPassFail(message, res1, res2);

       message = "Larmor radius at " + std::format("p={:.3e}⨯g⨯cm⨯s⁻¹, ", pmag_cgs)
                 + std::format("B={:.3e}⨯G", Bmag_cgs);
       res1 = Particle::LarmorRadius(pmag_cgs / Particle::unit_momentum, Bmag_cgs / Particle::unit_magnetic);
       res2 = pmag_cgs * Constants::SPEED_OF_LIGHT / q_cgs / Bmag_cgs / Particle::unit_length;
       PrintPassFail(message, res1, res2);

       message = "Magnetic moment at " + std::format("p={:.3e}⨯g⨯cm⨯s⁻¹, ", pmag_cgs)
                 + std::format("B={:.3e}⨯G", Bmag_cgs);
       res1 = Particle::MagneticMoment(pmag_cgs / Particle::unit_momentum, Bmag_cgs / Particle::unit_magnetic);
       res2 = Math::Sqr(pmag_cgs) / (2.0 * m_cgs * Bmag_cgs) / Particle::unit_magnetic_moment;
       PrintPassFail(message, res1, res2);

       message = "Perpendicular momentum at " + std::format("M={:.3e}⨯Fr⨯cm, ", mag_mom_cgs)
                 + std::format("B={:.3e}⨯G", Bmag_cgs);
       res1 = Particle::PerpMomentum(mag_mom_cgs / Particle::unit_magnetic_moment, Bmag_cgs / Particle::unit_magnetic);
       res2 = sqrt(2.0 * m_cgs * mag_mom_cgs * Bmag_cgs) / Particle::unit_momentum;
       PrintPassFail(message, res1, res2);

       message = "Relativistic factor at " + std::format("p∥={:.3e}⨯g⨯cm⨯s⁻¹, ", ppara_cgs)
                 + std::format("M={:.3e}⨯Fr⨯cm, ", mag_mom_cgs)
                 + std::format("B={:.3e}⨯G", Bmag_cgs);

       res1 = Particle::RelFactor2(ppara_cgs / Particle::unit_momentum, mag_mom_cgs / Particle::unit_magnetic_moment,
                                           Bmag_cgs / Particle::unit_magnetic);
       res2 = sqrt(1.0 + (2.0 * m_cgs * mag_mom_cgs * Bmag_cgs + Math::Sqr(ppara_cgs)) / Math::Sqr(m_cgs * Constants::SPEED_OF_LIGHT));
       PrintPassFail(message, res1, res2);

       cout << endl;
   
   }



};


