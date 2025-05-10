// \file B0/include/ActionInitialization.hh
// \brief Definition of the B0::ActionInitialization class

#ifndef B0ActionInitialization_h
#define B0ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

namespace B0
{

class ActionInitialization : public G4VUserActionInitialization
{
  public:
    ActionInitialization() = default;
    ~ActionInitialization() override = default;

    void BuildForMaster() const override;
    void Build() const override;
};

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
