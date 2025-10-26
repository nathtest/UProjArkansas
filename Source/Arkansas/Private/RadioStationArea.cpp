#include "RadioStationArea.h"
#include "ObsidianIDComponent.h"
#include "RadioStationAreaComponent.h"

ARadioStationArea::ARadioStationArea(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<URadioStationAreaComponent>(TEXT("RootComponent"));
    this->bShouldSaveGameState = true;
    this->bIsActive = true;
    this->bForcePlayerRadioOn_WhenClear = false;
    this->RadioStationData = NULL;
    this->BufferActivationRadius = 6000.00f;
    this->ActivationRadius = 5000.00f;
    this->bBoxActivation = true;
    this->bOrientBoxes = false;
    this->bModifyVisualization = false;
    this->BoxVisualizationLineThickness = 12.00f;
    this->CylinderVisualizationLineThickness = 20.00f;
    this->BufferDeactivationTime = 1.00f;
    this->DeactivationTime = 1.00f;
    this->ObsidianID = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianID"));
}


