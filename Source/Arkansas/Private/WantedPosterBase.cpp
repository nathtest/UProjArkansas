#include "WantedPosterBase.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TextRenderComponent -FallbackName=TextRenderComponent
#include "Components/TextRenderComponent.h"

AWantedPosterBase::AWantedPosterBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PosterStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PosterStaticMesh"));
    this->PlayerNameTextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("PlayerNameText"));
    this->BountyAmountTextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("BountyAmountText"));
    this->Faction = NULL;
    this->MaterialElementIndex = 0;
}

void AWantedPosterBase::UpdatedWantedPoster() {
}


