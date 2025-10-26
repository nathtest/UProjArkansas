#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "AIPossessable.h"
#include "EAIDisableMask.h"
#include "EAlertState.h"
#include "ESearchType.h"
#include "EStateOfBeing.h"
#include "OwBlackboardComponent.generated.h"

class AActor;
class ACharacterSpawner;
class AEnvironmentalDistraction;
class ASearchPoint;
class UHealthComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UOwBlackboardComponent : public UBlackboardComponent, public IAIPossessable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAlertState AlertState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAlertState PreviousAlertState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAIDisableMask DisabledMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AEnvironmentalDistraction> EnvironmentalDistraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> TargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStateOfBeing StateOfBeing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ACharacterSpawner> CurrentCharacterSpawner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsCompanion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASearchPoint> SearchPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESearchType SearchType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCrimeResponseRequested;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CrimeIDString;
    
public:
    UOwBlackboardComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnNewStateOfBeing(UHealthComponent* InHealthComponent, EStateOfBeing NewStateOfBeing, EStateOfBeing OldStateOfBeing);
    

    // Fix for true pure virtual functions not being implemented
};

