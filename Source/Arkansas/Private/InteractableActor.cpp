#include "InteractableActor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"
#include "InteractableComponent.h"

AInteractableActor::AInteractableActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bShouldSaveGameState = true;
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->Interactable = CreateDefaultSubobject<UInteractableComponent>(TEXT("Interactable"));
    this->AnimProxyComponent = NULL;
    this->ObsidianIDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->bUseInteractHoldTime = false;
    this->bTurnOffVideoMaterialOnVideoEnd = true;
    this->bTurnOnStaticVideoMaterialOnVideoEnd = false;
    this->InteractableAudioComponent = NULL;
    this->PreviewSkeletalMesh = NULL;
    this->Interactable->SetupAttachment(RootComponent);
}

void AInteractableActor::OnPageExitDelegateFired(URPGExaminableData* RPGExaminableData, int32 PageIndex, bool bWasUIClosed) {
}

void AInteractableActor::OnPageEnterDelegateFired(URPGExaminableData* RPGExaminableData, int32 PageIndex) {
}

void AInteractableActor::OnPageChoiceSelectDelegateFired(URPGExaminableData* RPGExaminableData, int32 PageIndex, int32 PageChoiceIndex) {
}

void AInteractableActor::OnInteractStateInteractDelegateFired(int32 StateIndex) {
}

void AInteractableActor::OnInteractStateChangedDelegateFired(int32 NewState, int32 OldState) {
}


void AInteractableActor::OnFpvAnimProxyCompleteDelegateFired() {
}

void AInteractableActor::OnBinkMediaOpened(const FString& OpenedUrl) {
}

void AInteractableActor::OnBinkMediaClosed() {
}

void AInteractableActor::OnAnimProxySkipped(AIndianaPlayerCharacter* PlayerCharacter, const FGameplayTag& SkippedAnimProxyKey) {
}

bool AInteractableActor::IsInConversation() const {
    return false;
}

bool AInteractableActor::HasPotentialConversationPresentationModeStarted() {
    return false;
}

TArray<EInteractionType> AInteractableActor::GetInteractions(const FInteractionDescription& Description) const {
    return TArray<EInteractionType>();
}

float AInteractableActor::GetInteractHoldTime(const FInteractionDescription& Description) {
    return 0.0f;
}

UInteractableComponent* AInteractableActor::GetInteractableComponent() const {
    return NULL;
}

FGameplayTag AInteractableActor::GetGameplayTag() const {
    return FGameplayTag{};
}

void AInteractableActor::CompleteInteract(const FInteractionDescription& Description) {
}

bool AInteractableActor::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}


