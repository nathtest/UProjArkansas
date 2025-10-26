#pragma once
#include "CoreMinimal.h"
#include "Perception\AISightTargetInterface.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <GameplayTagContainer.h>
#include "EDistractionDeviceState.h"
#include "EDistractionDeviceTypeChatterParam.h"
#include "EInteractionType.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "OnDistractionStateChangeDelegate.h"
#include "OnLifetimeThresholdHitDelegate.h"
#include "EnvironmentalDistraction.generated.h"

class AIndianaAiCharacter;
class AIndianaCharacter;
class UEnvironmentalDistractionComponent;
class UInteractableComponent;

UCLASS(Blueprintable, MinimalAPI)
class AEnvironmentalDistraction : public AActor, public IAISightTargetInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnvironmentalDistractionComponent* DistractionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DistractionTypeTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDistractionDeviceState DefaultDistractionState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeSeen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistractionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bContinuousDistraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistractionInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Lifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistractionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldFireThresholdEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LifeTimeEventThresholdPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LifeTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwitchedTargetTimeRemaining;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldDestroyOnInteract;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bShouldPlayDeathVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDistractionDeviceTypeChatterParam ChatterParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChatterEnabled;
    
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLifetimeThresholdHit OnLifetimeThresholdHit;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AIndianaAiCharacter> CurrentDistractee;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDistractionStateChange OnDistractionStateChange;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDistractionDeviceState DistractionState;
    
public:
    AEnvironmentalDistraction(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetDistractionState(EDistractionDeviceState InDistractionState);
    
protected:
    UFUNCTION(BlueprintCallable)
    void K2_SetCurrentDistractee(AIndianaAiCharacter* InCurrentDistractee);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_HasChatterParam() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetDistractionTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AIndianaAiCharacter* K2_GetCurrentDistractee() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 K2_GetChatterParam() const;
    
public:
    UFUNCTION(BlueprintCallable)
    TArray<EInteractionType> GetInteractions(const FInteractionDescription& Description) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EDistractionDeviceState GetDistractionState() const;
    
    UFUNCTION(BlueprintCallable)
    void CompleteInteract(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const;
    

    // Fix for true pure virtual functions not being implemented
};

