#pragma once
#include "CoreMinimal.h"
#include <Engine/TriggerData.h>
#include "ObservationGate.h"
#include "OnLookedAtEventDelegate.h"
#include "OnTargetedEventDelegate.h"
#include "TargetableComponent.h"
#include "LookAtTriggerComponent.generated.h"

class AActor;
class UCapsuleComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API ULookAtTriggerComponent : public UTargetableComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLookedAtEvent OnLookedAtEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTargetedEvent OnTargetStartEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTargetedEvent OnTargetEndEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTriggerData TriggerData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequiresLoS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumTriggerDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoldTimeToActivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowProgressBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCapsuleComponent> CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObservationGate ObservationRequirement;
    
public:
    ULookAtTriggerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetObservationEnabled(bool bNewObservationEnabled);
    
    UFUNCTION(BlueprintCallable)
    static void ActivateTrigger_BP(AActor* Actor);
    
};

