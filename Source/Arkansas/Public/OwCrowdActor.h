#pragma once
#include "CoreMinimal.h"
#include "Navigation\CrowdAgentInterface.h"

#include "Navigation/PathFollowingComponent.h"

#include "Engine\DamageEvents.h"
#include "AnimationProxyOwnerInterface.h"
#include <AnimationProxyTask.h>
#include <CrowdCharacterData.h>

#include "OEICrowdCharacter.h"
#include <ChatterEventReference.h>
#include "OwBaseCharacter.h"
#include "OwSpeaker.h"
#include "OwCrowdActor.generated.h"

class AActor;
class AController;
class UCharacterMovementComponent;
class UOEIMultiSkeletalMeshComponent;
class UOEIVoiceOverComponent;

UCLASS(Blueprintable)
class ARKANSAS_API AOwCrowdActor : public AOwBaseCharacter, public IOEICrowdCharacter, public IAnimationProxyOwnerInterface, public ICrowdAgentInterface, public IOwSpeaker {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOEIVoiceOverComponent* OEIVoiceOverComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationProxyTask AnimationProxyTask;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCrowdCharacterData CrowdCharacterData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOEIMultiSkeletalMeshComponent* SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinWalkSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxWalkSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinRunSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxRunSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCharacterMovementComponent* NavMovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TickUpdateScaleWhileMoving;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint16 Flags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EPathFollowingResult::Type> Code;
    
    AOwCrowdActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    float TakeDamage(float Damage, const FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
    
    UFUNCTION(BlueprintCallable)
    void NoticeCrime(AOwBaseCharacter* CommitingCrime, const FChatterEventReference& ChatterEvent, int32 Param1, int32 Param2, int32 Param3, int32 Param4);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMovingToAProxy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInAProxy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInAdvancedState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDead() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCombatActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAvailable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanNoticeCrime() const;
    

    // Fix for true pure virtual functions not being implemented
};

