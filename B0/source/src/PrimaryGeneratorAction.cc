// \file B0/src/PrimaryGeneratorAction.cc
// \brief Implementation of the B0::PrimaryGeneratorAction class

#include "PrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

namespace B0
{

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  PrimaryGeneratorAction::PrimaryGeneratorAction()
  {
    G4int n_particle = 1;
    fParticleGun  = new G4ParticleGun(n_particle);
  }

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  PrimaryGeneratorAction::~PrimaryGeneratorAction()
  {
    delete fParticleGun;
  }

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
  {
    //isotropic emission at 0,0,0
    double theta = 2*M_PI*((double)std::rand()/RAND_MAX); //(0,2pi)
    double phi = 2*(((double)std::rand()/RAND_MAX) - .5); //(-1,1)
    phi = acos(phi); //lol this is math notation 

    G4double imo = cos(theta)*sin(phi);
    G4double jmo = sin(theta)*sin(phi);
    G4double kmo = cos(phi);
	
    fParticleGun->SetParticlePosition(G4ThreeVector());
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(imo, jmo, kmo));
    fParticleGun->GeneratePrimaryVertex(anEvent);
  }

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}


