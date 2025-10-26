#include "IndianaPlayerStart.h"
#include "Camera/CameraComponent.h"
#include "Components\CapsuleComponent.h"

AIndianaPlayerStart::AIndianaPlayerStart(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LeftCompanion = CreateDefaultSubobject<UCapsuleComponent>(TEXT("LeftCompanion"));
    this->RightCompanion = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RightCompanion"));
    this->PreviewCam = CreateDefaultSubobject<UCameraComponent>(TEXT("Preview Camera"));
    this->DestinationPointOfInterestData = NULL;
    this->FastTravelDestinationPointOfInterestData = NULL;
    this->LeftCompanion->SetupAttachment(RootComponent);
    this->PreviewCam->SetupAttachment(RootComponent);
    this->RightCompanion->SetupAttachment(RootComponent);
}

bool AIndianaPlayerStart::GetCompanionSpawnLocation(const FString& CompanionCapsuleName, FVector& Location, FRotator& Rotation, bool bFeetLocation) const {
    return false;
}


