#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AnimInstance -FallbackName=AnimInstance
#include <GameplayTagContainer.h>
#include "ThrowableAnimInstance.generated.h"

class AIndianaPlayerCharacter;
class UCharacterAnimInstance;
class UThrowable;

UCLASS(Abstract, Blueprintable, NonTransient)
class ARKANSAS_API UThrowableAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bThrowStateMachineInProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bThrowLoopAnimationRequested;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bThrowCancelRequested;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UThrowable* CurrentThrowable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UThrowable* QueuedThrowable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AIndianaPlayerCharacter* Player;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCharacterAnimInstance* OwningCharacterAnimInstance;
    
public:
    UThrowableAnimInstance();

protected:
    UFUNCTION(BlueprintCallable)
    void OnThrowingAnimationEnded(UThrowable* Throwable);
    
    UFUNCTION(BlueprintCallable)
    void OnInputReleased();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsThrowableTag(FGameplayTag ThrowableTag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsThrowableMine() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerMoving() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerCrouching() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UThrowable* GetCurrentThrowable() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void AnimNotify_OnThrowStateMachineComplete();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_OnThrowStateEntered();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_OnThrowLoopStartStateEntered();
    
};

