#include "PetKennel.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ObsidianIDComponent.h"
#include "InteractableComponent.h"
#include "Templates/SubclassOf.h"

APetKennel::APetKennel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bShouldSaveGameState = true;
    this->InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("Interactable"));
    this->SelectedPet = NULL;
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->InteractableComponent->SetupAttachment(RootComponent);
}

void APetKennel::SelectPet(TSubclassOf<UPetData> PetData) {
}


