#include "Projectile.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent
#include "Components\SphereComponent.h"

#include "HealthComponent.h"
#include "IndianaProjMovementComponent.h"

AProjectile::AProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
    this->ProjectileMovement = CreateDefaultSubobject<UIndianaProjMovementComponent>(TEXT("ProjMovementComponent"));
    this->MainCollisionComponent = (USphereComponent*)RootComponent;
    this->DamageCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("DamageSphereComp"));
    this->VisualRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VisualRoot"));
    this->HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
    this->bUseNonHomingInitialSpeed = false;
    this->NonHomingInitialSpeed = 0.00f;
    this->NonHomingGravityScale = 0.00f;
    this->bOverlapDamageCollision = false;
    this->bSweepOverlapDamageCollision = false;
    this->bLineCheckOverlapDamageCollision = false;
    this->bSubstepLineChecks = false;
    this->LineCheckRate = 100.00f;
    this->ProjectileLifetime = 5.00f;
    this->bShouldActivateAtRest = true;
    this->AtRestTime = 0.10f;
    this->Impulse = 10000.00f;
    this->bRotate = false;
    this->bRandomRotateOnBounce = false;
    this->ProjectileBounceMinForce = 100.00f;
    this->MaxCharacterPenetration = -1;
    this->ShiftedVisualsInterpSpeed = 25.00f;
    this->bDestroyOnImpact = true;
    this->bFallFromBlockingHit = false;
    this->bDeflectFromBlockingHit = false;
    this->ImpactDataSet = NULL;
    this->BounceDataSet = NULL;
    this->AtRestDataSet = NULL;
    this->DestroyedImpactDataSet = NULL;
    this->DestroyedProjectileSpawnData = NULL;
    this->DestroyedSpawnData = NULL;
    this->OverrideDestroyedSpawnData = NULL;
    this->bApplyDamageOnImpact = false;
    this->bAttachOnImpact = false;
    this->AttachSpell = NULL;
    this->AttachAudioEvent = NULL;
    this->bApplyDamageOnDestroy = true;
    this->ThrowableLoopingAudio = NULL;
    this->bUseHealthComponent = false;
    this->bBlockWeaponTraces = false;
    this->bBlockProjectileTraces = false;
    this->bCanBeSeen = false;
    this->bCanBeHeard = true;
    this->bShouldBeAvoided = false;
    this->LifetimeStat = NULL;
    this->DamageStat = NULL;
    this->bShouldShowIndicator = true;
    this->bApplyDeathClassToCorpses = false;
    this->TracerSound = NULL;
    this->bEnablePlayerProximityNotification = false;
    this->PlayerProximityBufferDistance = 0.00f;
    this->PlayerProximityCollisionComponent = NULL;
    this->ProximityIndicatorDelay = 3.00f;
    this->DamageCollisionComponent->SetupAttachment(RootComponent);
    this->VisualRoot->SetupAttachment(RootComponent);
}

bool AProjectile::ShouldActorAvoid(AActor* Actor) {
    return false;
}

void AProjectile::SetLifetimeTimer(float InLifetime) {
}

void AProjectile::SetDetonationTraceDirectionOverride(FVector InDetonationTraceDirectionOverride) {
}

void AProjectile::OnProjectileStop(const FHitResult& HitResult) {
}

void AProjectile::OnPlayerProximityCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AProjectile::OnPlayerProximityCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AProjectile::OnPlayerPerspectiveChanged(bool bIsThirdPerson) {
}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void AProjectile::OnDamageEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AProjectile::OnDamageBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AProjectile::OnBounce(const FHitResult& ImpactResult, const FVector& ImpactVelocity) {
}

bool AProjectile::IsValidProjectile() const {
    return false;
}

void AProjectile::Init(EProjectileMode InMode) {
}

bool AProjectile::GetShouldBeAvoided() const {
    return false;
}


float AProjectile::GetPlayerProximityDistance() const {
    return 0.0f;
}

float AProjectile::GetOverlapCollisionSize() const {
    return 0.0f;
}

EProjectileMode AProjectile::GetMode() const {
    return EProjectileMode::Active;
}

FVector AProjectile::GetInitPosition() const {
    return FVector{};
}

float AProjectile::GetCollisionSize() const {
    return 0.0f;
}

float AProjectile::GetChargeAmount() const {
    return 0.0f;
}

float AProjectile::GetAvoidanceMaxDistance() const {
    return 0.0f;
}


