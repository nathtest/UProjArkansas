#include "InteractableTriggerVolume.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "AnimationProxyComponent.h"
#include "ObsidianIDComponent.h"
#include "InteractableComponent.h"

AInteractableTriggerVolume::AInteractableTriggerVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bGenerateOverlapEventsDuringLevelStreaming = true;
    this->InteractHoldTime = 0.00f;
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));
    this->AnimationProxyComponent = CreateDefaultSubobject<UAnimationProxyComponent>(TEXT("AnimationProxyComponent"));
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->TargetPointComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TargetPointComponent"));
    this->bRequireFacingAngle = false;
    this->FacingAngle = 90.00f;
    this->AnimationProxyComponent->SetupAttachment(RootComponent);
    this->InteractableComponent->SetupAttachment(RootComponent);
    this->TargetPointComponent->SetupAttachment(RootComponent);
}

void AInteractableTriggerVolume::StartInteract(const FInteractionDescription& InteractionDescription) {
}

void AInteractableTriggerVolume::SetInteractTarget(bool bIsTarget, UInteractableComponent* Interactable) {
}

void AInteractableTriggerVolume::OnPageExitDelegateFired(URPGExaminableData* RPGExaminableData, int32 PageIndex, bool bWasUIClosed) {
}

void AInteractableTriggerVolume::OnPageEnterDelegateFired(URPGExaminableData* RPGExaminableData, int32 PageIndex) {
}

void AInteractableTriggerVolume::OnPageChoiceSelectDelegateFired(URPGExaminableData* RPGExaminableData, int32 PageIndex, int32 PageChoiceIndex) {
}

void AInteractableTriggerVolume::OnInteractStateInteractDelegateFired(int32 StateIndex) {
}

void AInteractableTriggerVolume::OnInteractStateChangedDelegateFired(int32 NewState, int32 OldState) {
}

void AInteractableTriggerVolume::OnFpvAnimProxyCompleteDelegateFired() {
}

TArray<EInteractionType> AInteractableTriggerVolume::GetInteractions(const FInteractionDescription& Description) {
    return TArray<EInteractionType>();
}

float AInteractableTriggerVolume::GetInteractHoldTime(const FInteractionDescription& InteractionDescription) {
    return 0.0f;
}

void AInteractableTriggerVolume::CompleteInteract(const FInteractionDescription& InteractionDescription) {
}

bool AInteractableTriggerVolume::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}

void AInteractableTriggerVolume::CancelInteract(const FInteractionDescription& InteractionDescription) {
}


