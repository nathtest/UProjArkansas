#include "Pickable.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "ObsidianIDComponent.h"
#include "InteractableComponent.h"

APickable::APickable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bShouldSaveGameState = true;
    this->SceneComponent = (USceneComponent*)RootComponent;
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    this->UnpickedMesh = NULL;
    this->PickedMesh = NULL;
    this->Item = NULL;
    this->LootTable = NULL;
    this->Count = 1;
    this->InteractableComponent->SetupAttachment(RootComponent);
    this->StaticMeshComponent->SetupAttachment(RootComponent);
}

void APickable::OnPickablePicked() {
}


