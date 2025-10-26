#include "CoverNodeGenerationVolume.h"
#include "ObsidianIDComponent.h"
#include "NavDataGenerationVolumeComponent.h"

ACoverNodeGenerationVolume::ACoverNodeGenerationVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->NavDataGenerationVolumeComponent = CreateDefaultSubobject<UNavDataGenerationVolumeComponent>(TEXT("NavDataGenerationVolume"));
    this->bBuildCoverNodes = false;
    this->bDeleteCoverNodes = false;
    this->bGenerateHalfHeight = true;
    this->bGenerateFullHeight = true;
    this->bGenerateSegments = true;
    this->bMergeSegments = true;
    this->bWeldNodes = true;
    this->bFiringVolumeValidation = true;
    this->bComplexBallisticValidation = true;
    this->ComplexBallisticDepth = 120.00f;
    this->bStepOutVolumeValidation = true;
    this->bStepOutNavMeshValidation = true;
    this->bFindCorner = true;
    this->bFiringVolumeScan = true;
    this->FullHeightMinHeight = 150.00f;
    this->HalfHeightMaxHeight = 120.00f;
    this->HalfHeightMinHeight = 80.00f;
    this->SampleSize = 10.00f;
    this->MaxRayWallCheckDistance = 120.00f;
    this->MaxRayCornerCheckDistance = 120.00f;
    this->BackUpWallAngleDistance = 30.00f;
    this->MaxWallCheckDistance = 180.00f;
    this->MinFullHeightWallDistance = 30.00f;
    this->IdealFullHeightWallDistance = 50.00f;
    this->MinHalfHeightWallDistance = 40.00f;
    this->MaxAcceptableGapLength = 20.00f;
    this->FiringAcceptanceAngle = 5.00f;
    this->CoverAcceptanceHalfAngle = 25.00f;
    this->ZOffset = 80.00f;
    this->SlotSize = 120.00f;
    this->CoverTolerance = 120.00f;
    this->bMergeRejectedNodes = true;
    this->bDisplayDebugEdges = false;
    this->bDisplayRadialWallScan = false;
    this->bDisplayWallAngle = false;
    this->bDisplayFiringArc = false;
    this->bDisplayCornerDistance = false;
    this->bDisplayHeightTest = false;
    this->bDisplayWallThicknessTest = false;
    this->bDisplayBallisticValidation = false;
    this->bDisplayCornerPosition = false;
    this->bDisplayStepOutVolume = false;
    this->bDisplayVolumeScan = false;
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->bShowRejectedNodes = false;
    this->bFilterRejectedNodes = true;
    this->NavDataGenerationVolumeComponent->SetupAttachment(RootComponent);
}


