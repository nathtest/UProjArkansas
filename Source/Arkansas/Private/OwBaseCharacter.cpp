#include "OwBaseCharacter.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "Components\SceneComponent.h"

#include "Templates/SubclassOf.h"

AOwBaseCharacter::AOwBaseCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TalkingIdleOverrides = NULL;
    this->GroundOffsetComponent = CreateDefaultSubobject<USceneComponent>(TEXT("GroundOffset"));
    this->IndianaCharacterMovementComponent = NULL;
    this->AIMovementComponent = NULL;
    this->LocomotionLogicComponent = NULL;
    this->bRenderDepthOnlyDuringScanner = false;
    this->InvisibleRTPC = NULL;
    this->BossRTPC = NULL;
    this->bIgnoreCorpseForDetection = false;
    this->bOptimizeMovementTicks = false;
    this->GroundOffsetComponent->SetupAttachment(RootComponent);
}

void AOwBaseCharacter::SpawnScriptedProp(UAnimSequenceBase* Animation, UNewPropData* PropToSpawn, UAnimationAsset* PropAnimToPlay, bool bUseParentPosition) {
}

void AOwBaseCharacter::SetProxySubState(FGameplayTag PriorityTag, FGameplayTag DesiredSubState, FGameplayTag CurrentProxySubStateToCheck) {
}

void AOwBaseCharacter::OnMovementUpdated(float DeltaSeconds, FVector OldLocation, FVector OldVelocity) {
}

void AOwBaseCharacter::OnGadgetDeactivateVisuals(FGameplayTag GameplayTag) {
}

void AOwBaseCharacter::OnGadgetDeactivated(FGameplayTag GameplayTag) {
}

void AOwBaseCharacter::OnGadgetActivated(FGameplayTag GameplayTag) {
}

TSubclassOf<UFactionData> AOwBaseCharacter::K2_GetFactionData() const {
    return NULL;
}

bool AOwBaseCharacter::IsInCombat() const {
    return false;
}

void AOwBaseCharacter::HideProps() {
}

UEquipmentComponent* AOwBaseCharacter::GetEquipmentComponent() const {
    return NULL;
}

UWeapon* AOwBaseCharacter::GetCurrentWeapon() const {
    return NULL;
}

UAIMovementComponent* AOwBaseCharacter::GetAIMovementComponent() const {
    return NULL;
}


