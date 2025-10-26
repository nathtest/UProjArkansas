#include "OwCrowdActor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EAutoPossessAI -FallbackName=EAutoPossessAI
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESpawnActorCollisionHandlingMethod -FallbackName=ESpawnActorCollisionHandlingMethod
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICharacterCustomization -ObjectName=OEICCSkeletalMeshComponent -FallbackName=OEICCSkeletalMeshComponent
#include "OEICCSkeletalMeshComponent.h"

#include "CrowdMovementComponent.h"
#include "LocomotionLogicComponent.h"

AOwCrowdActor::AOwCrowdActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UOEICCSkeletalMeshComponent>(TEXT("CharacterMesh0")).SetDefaultSubobjectClass<UCrowdMovementComponent>(TEXT("CharMoveComp"))) {
    this->SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    this->AutoPossessAI = EAutoPossessAI::Disabled;
    this->LocomotionLogicComponent = CreateDefaultSubobject<ULocomotionLogicComponent>(TEXT("LocomotionLogicComponent"));
    this->OEIVoiceOverComponent = NULL;
    FProperty* p_Mesh_Prior = GetClass()->FindPropertyByName("Mesh");
    this->SkeletalMesh = (UOEIMultiSkeletalMeshComponent*)*p_Mesh_Prior->ContainerPtrToValuePtr<UOEICCSkeletalMeshComponent*>(this);
    this->MinWalkSpeed = 200.00f;
    this->MaxWalkSpeed = 200.00f;
    this->MinRunSpeed = 500.00f;
    this->MaxRunSpeed = 500.00f;
    FProperty* p_CharacterMovement_Prior = GetClass()->FindPropertyByName("CharacterMovement");
    this->NavMovementComponent = (UCharacterMovementComponent*)*p_CharacterMovement_Prior->ContainerPtrToValuePtr<UCrowdMovementComponent*>(this);
    this->TickUpdateScaleWhileMoving = 0.10f;
    this->Flags = 0;
    this->Code = EPathFollowingResult::Success;
    const FProperty* p_Mesh = GetClass()->FindPropertyByName("Mesh");
    (*p_Mesh->ContainerPtrToValuePtr<USkeletalMeshComponent*>(this))->SetupAttachment(RootComponent);
    this->SkeletalMesh->SetupAttachment(RootComponent);
}

float AOwCrowdActor::TakeDamage(float Damage, const FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser) {
    return 0.0f;
}

void AOwCrowdActor::NoticeCrime(AOwBaseCharacter* CommitingCrime, const FChatterEventReference& ChatterEvent, int32 Param1, int32 Param2, int32 Param3, int32 Param4) {
}

bool AOwCrowdActor::IsMovingToAProxy() const {
    return false;
}

bool AOwCrowdActor::IsInAProxy() const {
    return false;
}

bool AOwCrowdActor::IsInAdvancedState() const {
    return false;
}

bool AOwCrowdActor::IsDead() const {
    return false;
}

bool AOwCrowdActor::IsCombatActive() const {
    return false;
}

bool AOwCrowdActor::IsAvailable() const {
    return false;
}

bool AOwCrowdActor::CanNoticeCrime() const {
    return false;
}


