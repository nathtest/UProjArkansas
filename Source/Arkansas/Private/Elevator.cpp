#include "Elevator.h"
#include <AkComponent.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SplineComponent -FallbackName=SplineComponent
#include "Components\SplineComponent.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICinematics -ObjectName=MovingStageBoxComponent -FallbackName=MovingStageBoxComponent
#include "MovingStageBoxComponent.h"

#include "ObsidianIDComponent.h"
#include "BeaconComponent.h"
#include "InteractableComponent.h"

AElevator::AElevator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bGenerateOverlapEventsDuringLevelStreaming = true;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bShouldSaveGameState = true;
    this->InitialSplineTime = 0.00f;
    this->DistanceMovedPerSecond = 100.00f;
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->CarriageComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Carriage"));
    this->FrameMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Frame"));
    this->SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("Ak"));
    this->WPBeaconComponent = CreateDefaultSubobject<UBeaconComponent>(TEXT("WPBeaconComponent"));
    this->MovingStageBoxComponent = CreateDefaultSubobject<UMovingStageBoxComponent>(TEXT("BoxComponent"));
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));
    this->Floors.AddDefaulted(2);
    this->WallMesh = NULL;
    this->DoorMesh = NULL;
    this->LeftDoorPanelMesh = NULL;
    this->RightDoorPanelMesh = NULL;
    this->InteractableAudioComponent = NULL;
    this->bStartDisabled = false;
    this->bHasDoorPanels = true;
    this->bHideTransition = false;
    this->bUseEscapeBlockers = true;
    this->bActivateBlockersOnFloorSelect = false;
    this->bSuppressWaitLocationMapCheckWarnings = false;
    this->FrontDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontDoor"));
    this->RightDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightDoor"));
    this->BackDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackDoor"));
    this->LeftDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftDoor"));
    this->FrontRightDoorPanel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontRightDoorPanel"));
    this->FrontLeftDoorPanel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontLeftDoorPanel"));
    this->RightRightDoorPanel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightRightDoorPanel"));
    this->RightLeftDoorPanel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightLeftDoorPanel"));
    this->BackRightDoorPanel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackRightDoorPanel"));
    this->BackLeftDoorPanel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackLeftDoorPanel"));
    this->LeftRightDoorPanel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftRightDoorPanel"));
    this->LeftLeftDoorPanel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftLeftDoorPanel"));
    this->EscapeBlockers.AddDefaulted(4);
    this->WaitLocationLeft = CreateDefaultSubobject<USceneComponent>(TEXT("Wait Location (Left)"));
    this->WaitLocationMiddle = CreateDefaultSubobject<USceneComponent>(TEXT("Wait Location (Middle)"));
    this->WaitLocationRight = CreateDefaultSubobject<USceneComponent>(TEXT("Wait Location (Right)"));
    this->AkComponent->SetupAttachment(RootComponent);
    this->BackDoor->SetupAttachment(FrameMeshComponent);
    this->BackLeftDoorPanel->SetupAttachment(FrameMeshComponent);
    this->BackRightDoorPanel->SetupAttachment(FrameMeshComponent);
    this->CarriageComponent->SetupAttachment(RootComponent);
    this->FrameMeshComponent->SetupAttachment(CarriageComponent);
    this->FrontDoor->SetupAttachment(FrameMeshComponent);
    this->FrontLeftDoorPanel->SetupAttachment(FrameMeshComponent);
    this->FrontRightDoorPanel->SetupAttachment(FrameMeshComponent);
    this->InteractableComponent->SetupAttachment(RootComponent);
    this->LeftDoor->SetupAttachment(FrameMeshComponent);
    this->LeftLeftDoorPanel->SetupAttachment(FrameMeshComponent);
    this->LeftRightDoorPanel->SetupAttachment(FrameMeshComponent);
    this->MovingStageBoxComponent->SetupAttachment(RootComponent);
    this->RightDoor->SetupAttachment(FrameMeshComponent);
    this->RightLeftDoorPanel->SetupAttachment(FrameMeshComponent);
    this->RightRightDoorPanel->SetupAttachment(FrameMeshComponent);
    this->SplineComponent->SetupAttachment(RootComponent);
    this->WPBeaconComponent->SetupAttachment(CarriageComponent);
    this->WaitLocationLeft->SetupAttachment(CarriageComponent);
    this->WaitLocationMiddle->SetupAttachment(CarriageComponent);
    this->WaitLocationRight->SetupAttachment(CarriageComponent);
}

void AElevator::UpdateCurrentFloor() {
}

void AElevator::TeleportToFloor(int32 FloorIndex, bool bUpdateCarriage) {
}

void AElevator::StartMove() {
}

void AElevator::SetDoorPanelsOpenWidth(ECarriageWallDir Dir, float Width) {
}

void AElevator::SetDistanceMovedPerSecond(float NewDistanceMovedPerSecond) {
}

void AElevator::SetDisabled(bool bNewDisabled) {
}

void AElevator::SetCurrentFloor(int32 FloorIndex, bool bIgnoreRequirements) {
}

bool AElevator::PassesRPGRequirements(uint8 InteractionIndex) {
    return false;
}

void AElevator::OnUpdateEmissiveMaterials() {
}

bool AElevator::IsStationary() const {
    return false;
}

bool AElevator::IsMoving() const {
    return false;
}

UPointOfInterestData* AElevator::GetTravelDestinationData() const {
    return NULL;
}

int32 AElevator::GetTargetFloor() const {
    return 0;
}

FRPGInteractableRequirements AElevator::GetRPGRequirements(EInteractionType InteractionType) {
    return FRPGInteractableRequirements{};
}

int32 AElevator::GetNumberOfFloors() const {
    return 0;
}

TArray<EInteractionType> AElevator::GetInteractions(const FInteractionDescription& Description) const {
    return TArray<EInteractionType>();
}

float AElevator::GetInteractHoldTime(const FInteractionDescription& InteractionDescription) {
    return 0.0f;
}

ECarriageWallDir AElevator::GetGroundFloorDir() const {
    return ECarriageWallDir::Front;
}

int32 AElevator::GetGroundFloor() const {
    return 0;
}

FElevatorFloorData AElevator::GetFloorData(int32 FloorIndex) const {
    return FElevatorFloorData{};
}

bool AElevator::GetDisabled() const {
    return false;
}

ECarriageWallDir AElevator::GetCurrentFloorDir() const {
    return ECarriageWallDir::Front;
}

int32 AElevator::GetCurrentFloor() const {
    return 0;
}

FRotator AElevator::GetCarriageWiggleRotation_Implementation(float TimelineTime) const {
    return FRotator{};
}

TArray<FElevatorFloorData> AElevator::GetAllFloorData() const {
    return TArray<FElevatorFloorData>();
}

void AElevator::CompleteInteract(const FInteractionDescription& InteractionDescription) {
}

bool AElevator::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}

bool AElevator::CanAccessFloor(int32 FloorIndex) const {
    return false;
}


