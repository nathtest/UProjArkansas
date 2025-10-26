#include "BroadcastActorListener.h"
#include <AkComponent.h>

ABroadcastActorListener::ABroadcastActorListener(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("AkComponent"));
}


