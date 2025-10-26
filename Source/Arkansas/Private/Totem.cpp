#include "Totem.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent
#include "Components\SphereComponent.h"

ATotem::ATotem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EffectOverlapComponent = CreateDefaultSubobject<USphereComponent>(TEXT("EffectOverlapComponent"));
    this->StatusEffect = NULL;
    this->EffectOverlapComponent->SetupAttachment(RootComponent);
}

void ATotem::OnTotemDeactivated(FGuid ActiveID, AIndianaCharacter* Target) {
}

void ATotem::OnTotemActivated(FGuid ActiveID, AIndianaCharacter* Target) {
}

void ATotem::OnActorExited(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ATotem::OnActorEntered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ATotem::Detonate_BP() {
}


