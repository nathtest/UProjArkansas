#include "MapTextEntry.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent
#include "Components\SphereComponent.h"


AMapTextEntry::AMapTextEntry(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsEditorOnlyActor = true;
    this->RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
}


