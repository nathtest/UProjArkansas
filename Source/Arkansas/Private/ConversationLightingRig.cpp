#include "ConversationLightingRig.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "Components/SpotLightComponent.h"

AConversationLightingRig::AConversationLightingRig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->KeyLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("KeyLight"));
    this->FillLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("FillLight"));
    this->BackLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("BackLight"));
    this->bFollowSpeaker = true;
    this->ReferenceBoneName = TEXT("head_JNT");
    this->BackLight->SetupAttachment(RootComponent);
    this->FillLight->SetupAttachment(RootComponent);
    this->KeyLight->SetupAttachment(RootComponent);
}


