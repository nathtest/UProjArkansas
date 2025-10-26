#include "Corpse.h"
#include "Components\CapsuleComponent.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
#include "ObsidianIDComponent.h"
#include "AppearanceComponent.h"
#include "CharacterDeathComponent.h"
#include "EquipmentComponent.h"
#include "InteractableComponent.h"
#include "InventoryComponent.h"

ACorpse::ACorpse(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->bShouldSaveGameState = true;
    this->Gender = EOEIGender::Male;
    this->DeathPose = NULL;
    this->CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
    this->SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
    this->AppearanceComponent = CreateDefaultSubobject<UAppearanceComponent>(TEXT("Appearance"));
    this->InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("Interactable"));
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("IDComponent"));
    this->EquipmentComponent = CreateDefaultSubobject<UEquipmentComponent>(TEXT("EquipmentComponent"));
    this->DeathComponent = CreateDefaultSubobject<UCharacterDeathComponent>(TEXT("DeathComponent"));
    this->bApplyFrost = false;
    this->FrostCPDIndex = 25;
    this->FrostCPDValue = 1.00f;
    this->CapsuleComponent->SetupAttachment(RootComponent);
    this->InteractableComponent->SetupAttachment(SkeletalMeshComponent);
    this->SkeletalMeshComponent->SetupAttachment(CapsuleComponent);
}

void ACorpse::OnLootGenerated() {
}

void ACorpse::HandleItemRemoved(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack) {
}

void ACorpse::HandleItemAdded(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack) {
}

void ACorpse::GetItemsOnCorpse(TArray<UItem*>& OutItems) {
}

FLocString ACorpse::GetInteractName() const {
    return FLocString{};
}

TArray<EInteractionType> ACorpse::GetInteractions(const FInteractionDescription& Description) const {
    return TArray<EInteractionType>();
}

FGameplayTag ACorpse::GetGameplayTag() const {
    return FGameplayTag{};
}

void ACorpse::DisableHighlight() {
}

bool ACorpse::CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const {
    return false;
}


