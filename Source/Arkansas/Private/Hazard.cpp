#include "Hazard.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "ObsidianIDComponent.h"
#include "EventEffectState.h"
#include "OwNavModifierComponent.h"

AHazard::AHazard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bShouldSaveGameState = true;
    this->bAllowChildActorsToSaveGameState = true;
    this->bEnabled = true;
    this->bShouldBeAvoided = false;
    this->HazardEffect = NULL;
    this->StartEventEffects = NULL;
    this->StopEventEffects = NULL;
    this->EventEffectState = CreateDefaultSubobject<UEventEffectState>(TEXT("EventEffectState"));
    this->HazardTeam = NULL;
    this->bActivateHazardOnFriendly = false;
    this->bIgnoreCompanions = false;
    this->bPreventedByShieldGadget = false;
    this->EnableRampUpTime = 1.00f;
    this->DisableRampDownTime = 1.00f;
    this->RampRTPC = NULL;
    this->EffectExpirationDuration = 0.50f;
    this->EffectExpirationDurationModifyingStat = NULL;
    this->AutoDisableTime = 0.00f;
    this->AutoDisableKillTime = 1.00f;
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->CollisionStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollisionStaticMesh"));
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->bCheckLoS = false;
    this->ZyraniumType = EZyraniumType::None;
    this->NavModifierComponent = CreateDefaultSubobject<UOwNavModifierComponent>(TEXT("NavModifier"));
    this->bDeferredSpawn = false;
    this->bPooled = false;
    this->OwningPool = NULL;
    this->CollisionStaticMeshComponent->SetupAttachment(RootComponent);
}

void AHazard::StartInteract(const FInteractionDescription& InteractionDescription) {
}

void AHazard::SetInstigator(AActor* InInstigator) {
}

void AHazard::SetHazardEnabled(bool bInEnabled) {
}





void AHazard::OnAutoDisableKillTimeElapsed() {
}

void AHazard::OnActorExited(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AHazard::OnActorEntered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool AHazard::IsPointInsideHazard(const FVector& Point, const float Extent) const {
    return false;
}

bool AHazard::IsHazardEnabled() const {
    return false;
}

bool AHazard::HasPower() const {
    return false;
}

bool AHazard::GetShouldBeAvoided() const {
    return false;
}

bool AHazard::GetInActorPool() {
    return false;
}

void AHazard::FreeToPoolBP() {
}

bool AHazard::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}

void AHazard::AttemptEnableHazard(bool bEnable) {
}


