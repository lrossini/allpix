/**
 *  Author:
 *    Mathieu.Benoit@cern.ch
 *
 *  allpix Authors:
 *   John Idarraga <idarraga@cern.ch>
 *   Mathieu Benoit <benoit@lal.in2p3.fr>
 */

#ifndef AllPixTimepixDigit_h
#define AllPixTimepixDigit_h 1

#include "AllPixDigitInterface.hh"
#include "G4TDigiCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

/**
 *  Digit AllPixTimepix class.
 */
class AllPixTimepixDigit : public AllPixDigitInterface {

public:
  AllPixTimepixDigit();
  ~AllPixTimepixDigit();

  AllPixTimepixDigit(const AllPixTimepixDigit&);
  const AllPixTimepixDigit& operator=(const AllPixTimepixDigit&);
  int operator==(const AllPixTimepixDigit&) const;
  
  inline void* operator new(size_t);
  inline void  operator delete(void*);
  
  void Draw();
  void Print();

private:
  
  G4int pixelIDX;    
  G4int pixelIDY;    
  G4int pixelCounts;
  G4double pixelEnergyDep; // MC // Corrected MC charge (detector effects included, at Digi step)
  G4ThreeVector primaryVertex;
  G4double pixelEnergyMC; //MC only //nalipour
  
  G4double posX_WithRespectToPixel; //nalipour
  G4double posY_WithRespectToPixel; //nalipour
  G4double posZ_WithRespectToPixel; //nalipour

public:
  
  inline void SetPixelIDX(G4int pidX)   {pixelIDX = pidX;};
  inline void SetPixelIDY(G4int pidY)   {pixelIDY = pidY;};
  inline void SetPixelCounts(G4int pc)  {pixelCounts = pc;};
  inline void SetPixelEnergyDep(G4double ed)  {pixelEnergyDep = ed;}; // MC // Corrected MC charge (detector effects included, at Digi step)
  inline void SetPrimaryVertex(G4ThreeVector pv)  {primaryVertex = pv;}; // MC vertex //
  inline void IncreasePixelCounts()     {pixelCounts++;};
  inline void SetPixelEnergyMC(G4double energyMC) {pixelEnergyMC = energyMC;};

  inline G4int GetPixelIDX()   {return pixelIDX;};
  inline G4int GetPixelIDY()   {return pixelIDY;};
  inline G4int GetPixelCounts()  {return pixelCounts;};
  inline G4double GetPixelEnergyDep()  {return pixelEnergyDep;}; // MC //
  inline G4ThreeVector GetPrimaryVertex()  {return primaryVertex;}; // MC //
  inline G4double GetPixelEnergyMC() {return pixelEnergyMC;};

  inline void Set_posX_WithRespectoToPixel(G4double pos) {posX_WithRespectToPixel=pos;}; //nalipour
  inline void Set_posY_WithRespectoToPixel(G4double pos) {posY_WithRespectToPixel=pos;}; //nalipour
  inline void Set_posZ_WithRespectoToPixel(G4double pos) {posZ_WithRespectToPixel=pos;}; //nalipour
  inline G4double Get_posX_WithRespectoToPixel() {return posX_WithRespectToPixel;}; //nalipour
  inline G4double Get_posY_WithRespectoToPixel() {return posY_WithRespectToPixel;}; //nalipour
  inline G4double Get_posZ_WithRespectoToPixel() {return posZ_WithRespectToPixel;}; //nalipour

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

typedef G4TDigiCollection<AllPixTimepixDigit> AllPixTimepixDigitsCollection;

extern G4Allocator<AllPixTimepixDigit> AllPixTimepixDigitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void* AllPixTimepixDigit::operator new(size_t)
{
  void* aDigi;
  aDigi = (void*) AllPixTimepixDigitAllocator.MallocSingle();
  return aDigi;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void AllPixTimepixDigit::operator delete(void* aDigi)
{
  AllPixTimepixDigitAllocator.FreeSingle((AllPixTimepixDigit*) aDigi);
}

#endif

