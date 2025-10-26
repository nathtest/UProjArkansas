#include "ComputerTerminal.h"
#include <AkComponent.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent

AComputerTerminal::AComputerTerminal(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bSkipAutomaticConversation = false;
    this->bIgnoreForCrime = false;
    this->MinPlayerDistance = 150.00f;
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("Ak"));
    this->MainScreenWidgetComponent = NULL;
    this->SpeakerInfoComponent = NULL;
    this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyStaticMesh"));
    this->LockScreenStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LockScreenStaticMesh"));
    this->ComputerTerminalWidgetComponent = NULL;
    this->SkeletalMeshComponent = NULL;
    this->VoiceOverAudioComponent = CreateDefaultSubobject<UAkComponent>(TEXT("VoiceOverFaceFXExternalAudio"));
    this->HackDifficulty = EOCLDifficulty::Medium;
    this->bForceHackTier = false;
    this->ForcedHackTier = ESkillDifficultyTier::One;
    this->bHackable = false;
    this->AutoHackItem = NULL;
    this->bRemoveAutoHackItemAfterUse = true;
    this->HackResourceItem = NULL;
    this->AkComponent->SetupAttachment(RootComponent);
    this->LockScreenStaticMeshComponent->SetupAttachment(RootComponent);
    this->StaticMeshComponent->SetupAttachment(RootComponent);
    this->VoiceOverAudioComponent->SetupAttachment(RootComponent);
}

void AComputerTerminal::UpdateInteractHold(float ElapsedTime) {
}

void AComputerTerminal::UnlockComputer(bool bFireComputerUnlockedEvent) {
}

void AComputerTerminal::StartInteract(const FInteractionDescription& InteractionDescription) {
}

void AComputerTerminal::SetRenderShown(bool bNewRenderShown, FSpeakerReference Speaker) {
}

bool AComputerTerminal::PassesRPGRequirements(uint8 InteractionIndex) {
    return false;
}

void AComputerTerminal::OnFPVAnimationComplete() {
}

void AComputerTerminal::LockComputer(bool bFireComputerLockedEvent) {
}

bool AComputerTerminal::IsLocked() const {
    return false;
}

FRPGInteractableRequirements AComputerTerminal::GetRPGRequirements(EInteractionType InteractionType) {
    return FRPGInteractableRequirements{};
}

void AComputerTerminal::ConversationInstanceStart(UOwConversationInstance* OwConversationInstance) {
}

void AComputerTerminal::ConversationInstanceEnd(UOwConversationInstance* OwConversationInstance) {
}

void AComputerTerminal::ChangeState(EComputerHackState State) {
}

void AComputerTerminal::CancelInteract(const FInteractionDescription& InteractionDescription) {
}


