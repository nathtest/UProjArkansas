#include "TrapTrigger.h"
#include "Components\CapsuleComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"
#include "InteractLookAtTriggerComponent.h"
#include "InteractableComponent.h"
#include "OwNavModifierComponent.h"

ATrapTrigger::ATrapTrigger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bShouldSaveGameState = true;
    this->bAllowChildActorsToSaveGameState = true;
    this->InitialState = ETrapTriggerState::Armed;
    this->PreDeploymentSeconds = 0.50f;
    this->DeploymentDelaySeconds = 1.00f;
    this->DeploymentsPerSecond = 0.00f;
    this->RearmDelaySeconds = 0.00f;
    this->TeamClass = NULL;
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->ActivationShapeComponent = NULL;
    this->ActivatorTrackingShapeComponent = NULL;
    this->InteractLookAtTriggerComponent = CreateDefaultSubobject<UInteractLookAtTriggerComponent>(TEXT("InteractLookAtTrigger"));
    this->CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("LookAtCapsule"));
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("Interactable"));
    this->DisarmSkill = ESkill::Melee;
    this->DisarmDifficulty = EOCLDifficulty::Medium;
    this->bForceDisarmTier = false;
    this->ForcedDisarmTier = ESkillDifficultyTier::One;
    this->bIgnoreLightStep = false;
    this->OwningFaction = NULL;
    this->NavModifierComponent = CreateDefaultSubobject<UOwNavModifierComponent>(TEXT("NavModifier"));
    this->CapsuleComponent->SetupAttachment(RootComponent);
    this->InteractableComponent->SetupAttachment(RootComponent);
}

void ATrapTrigger::StartInteract(const FInteractionDescription& InteractionDescription) {
}

void ATrapTrigger::OnObservationRevealed() {
}

void ATrapTrigger::OnActivatorTrackingShapeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ATrapTrigger::OnActivatorTrackingShapeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ATrapTrigger::OnActivationShapeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ATrapTrigger::OnActivationShapeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool ATrapTrigger::IsRearming() const {
    return false;
}

bool ATrapTrigger::IsDeploymentPending() const {
    return false;
}

ETrapTriggerState ATrapTrigger::GetInitialState() const {
    return ETrapTriggerState::Armed;
}

ETrapTriggerState ATrapTrigger::GetCurrentState() const {
    return ETrapTriggerState::Armed;
}

AIndianaCharacter* ATrapTrigger::GetActivatingCharacter() {
    return NULL;
}

void ATrapTrigger::DisarmTrapTrigger(bool bAlertEffectSources) {
}

void ATrapTrigger::ChangeState(ETrapTriggerState State) {
}

void ATrapTrigger::ArmTrapTrigger() {
}


