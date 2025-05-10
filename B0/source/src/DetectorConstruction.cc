// \file B0/src/DetectorConstruction.cc
// \brief Implementation of the B0::DetectorConstruction class

#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

namespace B0
{

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  G4VPhysicalVolume* DetectorConstruction::Construct()
  {
    // Get nist material manager
    G4NistManager* nist = G4NistManager::Instance();

    // Option to switch on/off checking of volumes overlaps
    G4bool checkOverlaps = true;

    // World
    G4double worldSizeX = 1. * m;
    G4double worldSizeY = 1. * m;
    G4double worldSizeZ = 1. * m;
    G4Material* worldMaterial = nist->FindOrBuildMaterial("G4_AIR");

    auto worldSol
      = new G4Box("worldSol", worldSizeX/2., worldSizeY/2., worldSizeZ/2.);

    auto worldLog = new G4LogicalVolume(worldSol, worldMaterial, "worldLog");

    auto worldPhys = new G4PVPlacement(nullptr,            // no rotation
				       G4ThreeVector(),    // at (0,0,0)
				       worldLog,           // its logical volume
				       "worldPhys",        // its name
				       nullptr,            // its mother  volume
				       false,              // no boolean operation
				       0,                  // copy number
				       checkOverlaps);     // overlaps checking

    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

    // Box
    G4double boxSizeX = 10. * cm;
    G4double boxSizeY = 10. * cm;
    G4double boxSizeZ = 10. * cm;
    G4Material* boxMaterial = nist->FindOrBuildMaterial("G4_WATER");

    auto boxSol = new G4Box("boxSol", boxSizeX/2., boxSizeY/2., boxSizeZ/2.);

    auto boxLog = new G4LogicalVolume(boxSol, boxMaterial, "boxLog");

    auto boxPhys = new G4PVPlacement(nullptr,            // no rotation
				     G4ThreeVector(),    // at (0,0,0)
				     boxLog,             // its logical volume
				     "boxPhys",          // its name
				     worldLog,           // its mother  volume
				     false,              // no boolean operation
				     0,                  // copy number
				     checkOverlaps);     // overlaps checking

    // Set boxLog as scoring volume
    fScoringVolume = boxLog;

    //always return the physical World
    return worldPhys;
  }

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
