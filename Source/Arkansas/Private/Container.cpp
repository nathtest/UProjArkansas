#include "Container.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"
#include "InteractableComponent.h"
#include "InventoryComponent.h"
#include "OCLComponent.h"

AContainer::AContainer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bShouldSaveGameState = true;
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->OCLComponent = CreateDefaultSubobject<UOCLComponent>(TEXT("OCL"));
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));
    this->InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->bLootManagerLootApplied = false;
    this->LootManagerLootList = NULL;
    this->LootManagerTier = ESkillDifficultyTier::One;
    this->LootManagerListEntriesToApply = 0;
    this->InteractableComponent->SetupAttachment(RootComponent);
}

bool AContainer::PassesRPGRequirements(uint8 InteractionIndex) {
    return false;
}

void AContainer::OnInteractionTargetChanged(const FInteractionDescription& Description) {
}

void AContainer::OnContainerInteractableTargeted() {
}

bool AContainer::IsLightEnabled() const {
    return false;
}

void AContainer::HandleItemRemoved(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack) {
}

void AContainer::HandleItemAdded(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack) {
}

FRPGInteractableRequirements AContainer::GetRPGRequirements(EInteractionType InteractionType) {
    return FRPGInteractableRequirements{};
}

void AContainer::GetItemsInContainer(TArray<UItem*>& OutItems) {
}

FLocString AContainer::GetInteractName() const {
    return FLocString{};
}

float AContainer::GetInteractHoldTime(const FInteractionDescription& InteractionDescription) {
    return 0.0f;
}

FGameplayTag AContainer::GetGameplayTag() const {
    return FGameplayTag{};
}


