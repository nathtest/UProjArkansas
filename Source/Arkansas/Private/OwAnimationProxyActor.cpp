#include "OwAnimationProxyActor.h"
#include "ObsidianIDComponent.h"
#include "OwAnimationProxyComponent.h"
#include "OwNavModifierComponent.h"

AOwAnimationProxyActor::AOwAnimationProxyActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UOwAnimationProxyComponent>(TEXT("AnimationProxyComponent"))) {
    this->bShouldSaveGameState = true;
    this->NavModifierComponent = CreateDefaultSubobject<UOwNavModifierComponent>(TEXT("NavModifier"));
    this->bUseNavModifier = true;
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
    this->AutomaticLinkedAnimProxiesRange = -1.00f;
    this->AnimationProxyComponent->SetupAttachment(RootComponent);
}


void AOwAnimationProxyActor::OnAnimProxyComplete() {
}


