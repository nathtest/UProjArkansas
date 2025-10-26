#include "Trap.h"
#include <AkComponent.h>
#include "Components\CapsuleComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"
#include "InteractLookAtTriggerComponent.h"

ATrap::ATrap(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bShouldSaveGameState = true;
    this->InitialState = ETrapState::Armed;
    this->bCanArm = true;
    this->bCanDisarm = true;
    this->TrapDifficulty = ETrapDifficulty::Easy;
    this->PreDetonationSeconds = 0.50f;
    this->DetonationDelaySeconds = 1.00f;
    this->DetonationsPerSecond = 0.00f;
    this->RearmDelaySeconds = -1.00f;
    this->StatusEffectType = NULL;
    this->ImpactDataSet = NULL;
    this->NiagaraFxShotOrigin = NULL;
    this->NiagaraFxShotEnd = NULL;
    this->NiagaraFxBeam = NULL;
    this->AttackFxBeamEndParam = TEXT("BeamEnd");
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("Ak"));
    this->InteractLookAtTriggerComponent = CreateDefaultSubobject<UInteractLookAtTriggerComponent>(TEXT("InteractLookAtTrigger"));
    this->CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("LookAtCapsule"));
    this->ActivationShapeComponent = NULL;
    this->ActivatorTrackingShapeComponent = NULL;
    this->AkComponent->SetupAttachment(RootComponent);
    this->CapsuleComponent->SetupAttachment(RootComponent);
}

void ATrap::UpdateInteractHold(float ElapsedTime) {
}

void ATrap::StartInteract(const FInteractionDescription& InteractionDescription) {
}

void ATrap::SetInteractTarget(bool bIsTarget, UInteractableComponent* Interactable) {
}

void ATrap::OnStatUpdated(URpgStatComponent* InStatComponent, const URpgStat* Stat) {
}

void ATrap::OnObservationRevealed() {
}

void ATrap::OnActivatorTrackingShapeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ATrap::OnActivatorTrackingShapeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ATrap::OnActivationShapeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ATrap::OnActivationShapeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool ATrap::IsRearming() const {
    return false;
}

bool ATrap::IsDetonationPending() const {
    return false;
}

TArray<EInteractionType> ATrap::GetInteractions(const FInteractionDescription& Description) const {
    return TArray<EInteractionType>();
}

float ATrap::GetInteractHoldTime(const FInteractionDescription& Description) {
    return 0.0f;
}

uint8 ATrap::GetExactTrapDifficulty() const {
    return 0;
}

ETrapState ATrap::GetCurrentState() const {
    return ETrapState::Armed;
}

UShapeComponent* ATrap::GetActivatorTrackingShapeComponent() const {
    return NULL;
}

UShapeComponent* ATrap::GetActivationShapeComponent() const {
    return NULL;
}

void ATrap::DisarmTrap(AIndianaCharacter* Initiator, bool bFireTrapDisarmedEvent) {
}

void ATrap::DeactivateTrap(AIndianaCharacter* Initiator, bool bFireTrapDeactivatedEvent) {
}

void ATrap::CompleteInteract(const FInteractionDescription& InteractionDescription) {
}

bool ATrap::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}

void ATrap::CancelInteract(const FInteractionDescription& InteractionDescription) {
}

void ATrap::ArmTrap(AIndianaCharacter* Initiator, bool bFireTrapArmedEvent) {
}


