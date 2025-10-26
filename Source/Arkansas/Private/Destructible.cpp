#include "Destructible.h"
#include "Components\CapsuleComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "ObsidianIDComponent.h"
#include "HealthComponent.h"
#include "OwNavModifierComponent.h"
#include "TargetableComponent.h"

ADestructible::ADestructible(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bShouldSaveGameState = true;
    this->InitialState = EDestructibleState::Pristine;
    this->bShowHealth = false;
    this->bDisableCollisionOnDestroyed = true;
    this->bDisableCoverOnDestroyed = false;
    this->bChangeCoverTypeOnStateChange = false;
    this->ImpactDataSet = NULL;
    this->DestroyedDataSet = NULL;
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    this->HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
    this->DetonationPoint = CreateDefaultSubobject<USceneComponent>(TEXT("DetonationPoint"));
    this->TargetableComponent = CreateDefaultSubobject<UTargetableComponent>(TEXT("TargetableComponent"));
    this->CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("TriggerVolume"));
    this->NavModifierComponent = CreateDefaultSubobject<UOwNavModifierComponent>(TEXT("NavModifier"));
    this->TrapAudioClass = NULL;
    this->TrapAudioComponent = NULL;
    this->DestructibleAudioClass = NULL;
    this->DestructibleAudioComponent = NULL;
    this->AISoundRadius = 1000.00f;
    this->AISoundVolume = 80.00f;
    this->DisarmMaterialSensors = NULL;
    this->DisarmMaterialRing = NULL;
    this->PlacedMaterialSensors = NULL;
    this->PlacedMaterialRing = NULL;
    this->bShowDamageNumbers = false;
    this->bPooled = false;
    this->LootSeed = -1;
    this->bLooted = false;
    this->SkillDifficultyTierOverride = ESkillDifficultyTier::One;
    this->ArmedMaterialSensors = NULL;
    this->ArmedMaterialRing = NULL;
    this->OwningPool = NULL;
    this->CapsuleComponent->SetupAttachment(RootComponent);
    this->DetonationPoint->SetupAttachment(RootComponent);
    this->StaticMeshComponent->SetupAttachment(RootComponent);
}

void ADestructible::SetLooted() {
}

void ADestructible::SetDestructibleState(EDestructibleState NewState) {
}

void ADestructible::ReceiveTriggerUntripped_Implementation() {
}

void ADestructible::ReceiveTriggerTripped_Implementation() {
}

void ADestructible::ReceiveTriggerDisarmed_Implementation() {
}

void ADestructible::ReceiveTriggerArmed_Implementation() {
}

void ADestructible::ReceivePreDeploy_Implementation() {
}

void ADestructible::ReceiveDeployOrder_Implementation() {
}



void ADestructible::OnHealthChanged(UHealthComponent* InHealthComponent, float PrevNormalizedHealth, float CurrNormalizedHealth, AActor* InInstigator) {
}


bool ADestructible::IsLooted() {
    return false;
}

bool ADestructible::GetInActorPool() {
    return false;
}

float ADestructible::GetHealthForState(EDestructibleState DSTState) const {
    return 0.0f;
}

EDestructibleState ADestructible::GetCurrentState() const {
    return EDestructibleState::Pristine;
}

bool ADestructible::GetCanDetonate() const {
    return false;
}

void ADestructible::GenerateLootSeedIfUnset() {
}

void ADestructible::FreeToPoolBP() {
}


