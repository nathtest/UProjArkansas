#include "Mine.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent
#include "Components\SphereComponent.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "HealthComponent.h"

AMine::AMine(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TrapAudioClass = NULL;
    this->DestructibleAudioClass = NULL;
    this->DetonationVolume = CreateDefaultSubobject<USphereComponent>(TEXT("Detonation Volume"));
    this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    this->bPlayerPlaced = false;
    this->DetonateDestructibleDamageType = NULL;
    this->ArmTime = 0.00f;
    this->ElevatorSearchDistance = 30.00f;
    this->LOSCheckOffset = 0.00f;
    this->ThrowableActorClass = NULL;
    this->ImpactDataSet = NULL;
    this->DestroyedDataSet = NULL;
    this->AISoundRadius = 1000.00f;
    this->AISoundVolume = 80.00f;
    this->InnerMaterialIndex = 1;
    this->OuterMaterialIndex = 2;
    this->HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
    this->TrapAudioComponent = NULL;
    this->DestructibleAudioComponent = NULL;
    this->bPooled = false;
    this->OwningPool = NULL;
    this->DetonationVolume->SetupAttachment(RootComponent);
    this->StaticMeshComponent->SetupAttachment(RootComponent);
}

bool AMine::TriggerMine_BP(AActor* Initiator, bool bForce) {
    return false;
}

bool AMine::TriggerMine(AActor* Initiator, bool bForce) {
    return false;
}

void AMine::OnTrapDeployed() {
}

void AMine::OnStopCrouch(UIndianaCharMovementComponent* InMovementComponent, bool bPlayerToggled) {
}



void AMine::OnPlayerPlacedMineCountIncremented() {
}

void AMine::OnHealthChanged(UHealthComponent* InHealthComponent, float PrevNormalizedHealth, float CurrNormalizedHealth, AActor* InInstigator) {
}


void AMine::OnDetonationVolumeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AMine::OnDetonationVolumeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}


void AMine::OnCrouch() {
}

void AMine::OnActivationTriggerExited(AActor* Initiator) {
}

void AMine::OnActivationTriggerEntered(AActor* Initiator) {
}

bool AMine::GetInActorPool() {
    return false;
}

void AMine::FreeToPoolBP() {
}

void AMine::ExecuteOnDestructibleDestroyed(AActor* Initiator) {
}


