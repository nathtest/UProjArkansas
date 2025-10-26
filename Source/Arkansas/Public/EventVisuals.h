#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include <GameplayTagContainer.h>
#include "EventEffectsStruct.h"
#include "EventVisuals.generated.h"

class AActor;
class UEventEffectState;
class USkeletalMeshComponent;

UCLASS(Abstract, Blueprintable)
class UEventVisuals : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FEventEffectsStruct> EventEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FEventEffectsStruct> EventStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> CustomEventTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEventEffectState* EventEffectState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> TPVWeaponMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> FPVWeaponMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> TPVCharacterMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> FPVCharacterMesh;
    
public:
    UEventVisuals();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UninitializeBP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TriggerEventBP(FGameplayTag EventTag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void LeaveStateBP(FGameplayTag StateTag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitializeBP(AActor* NewTarget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnterStateBP(FGameplayTag StateTag);
    
};

