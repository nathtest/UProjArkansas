#include "Pickup.h"
#include "ObsidianIDComponent.h"
#include "InteractableComponent.h"

APickup::APickup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShouldSaveGameState = true;
    this->MeshLoadDistance = 2000.00f;
    this->MeshUnloadDistance = 4000.00f;
    this->LootList = NULL;
    this->LootListItem = NULL;
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->bOverrideNonPlayerOwnership = false;
    this->bOverridePlayerOwnership = false;
    this->OwningFaction = NULL;
    this->bPlayerOwned = false;
    this->bAddItemToInventory = true;
    this->bIsOneOff = true;
    this->bIsChildActor = false;
    this->bAllowDebugBehavior = false;
    this->bLeaveOriginal = false;
    this->bAllowEasyApply = false;
    this->bOnlyAllowEasyApply = false;
    this->LootSeed = -1;
    this->InteractableComponent->SetupAttachment(RootComponent);
}

void APickup::ShutdownDropPhysics(bool bUpdateTransforms) {
}

void APickup::SetupDropPhysics() {
}

void APickup::SetSeedFromActor(AActor* SeedActor) {
}

void APickup::RegenerateSeed() {
}

void APickup::OnPhysicsWake(UPrimitiveComponent* WakingComponent, FName BoneName) {
}

void APickup::OnPhysicsSleep(UPrimitiveComponent* SleepingComponent, FName BoneName) {
}

void APickup::LockLootListItem() {
}

FItemStack APickup::GetItemStack() const {
    return FItemStack{};
}

UItem* APickup::GetItem() const {
    return NULL;
}

void APickup::ClearOwnership() {
}


