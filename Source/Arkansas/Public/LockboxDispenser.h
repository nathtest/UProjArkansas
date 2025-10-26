#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "ECycleDirection.h"
#include "InteractableActor.h"
#include "ItemStack.h"
#include "OnCycleCompleteEventDelegate.h"
#include "LockboxDispenser.generated.h"

class AActor;
class ASWITCH;
class UAnimationAsset;
class UInventoryComponent;
class URPGExaminableData;

UCLASS(Blueprintable)
class ARKANSAS_API ALockboxDispenser : public AInteractableActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCycleCompleteEvent OnCycleCompleteEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASWITCH* UpSwitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASWITCH* DownSwitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* UpMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* DownMontage;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OpenLockboxPageIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OpenLockboxChoiceIndex;
    
public:
    ALockboxDispenser(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnSwitchStateChangedUp(AActor* Initiator, int32 StateIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnSwitchStateChangedDown(AActor* Initiator, int32 StateIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnPageChoiceSelected(URPGExaminableData* RPGExaminableData, int32 PageIndex, int32 PageChoiceIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnItemAdded(UInventoryComponent* InventoryComponent, const FItemStack& Item);
    
    UFUNCTION(BlueprintCallable)
    void OnCycleRacksComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnAnimNotifyEventTriggered(FGameplayTag EventTag);
    
    UFUNCTION()
    void CycleRacks(ECycleDirection Direction);
    
};

