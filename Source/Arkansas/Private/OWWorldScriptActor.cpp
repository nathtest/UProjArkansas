#include "OWWorldScriptActor.h"
#include "ObsidianIDComponent.h"

AOWWorldScriptActor::AOWWorldScriptActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IDComponent = CreateDefaultSubobject<UObsidianIDComponent>(TEXT("ObsidianIDComponent"));
}


