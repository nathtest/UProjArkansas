#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include <GameplayTagContainer.h>
#include <GameplayTagContainer.h>
#include "EIndianaRadioAudioEvent.h"
#include "ERadioPlayerType.h"
#include "RadioAudioEventArray.h"
#include "RadioPlayerComponent.generated.h"

class UAkAudioEvent;
class UAkComponent;
class UOEIWwiseEmitterComponent;
class URadioStationDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API URadioPlayerComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERadioPlayerType RadioType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<URadioStationDataAsset> StartingStation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URadioStationDataAsset* CurrentStationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer TunableStations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInitialState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EIndianaRadioAudioEvent, FRadioAudioEventArray> AudioEventBanks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAkAudioEvent*> BeginPlayAudioEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAkAudioEvent*> EndPlayAudioEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAkAudioEvent*> EnabledAudioEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAkAudioEvent*> DisabledAudioEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAkAudioEvent*> TunedAudioEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowUserOnOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowUserTune;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTuneOnStartUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAkComponent* AkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UOEIWwiseEmitterComponent* EmitterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CurrentStation;
    
public:
    URadioPlayerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TurnRadioOn();
    
    UFUNCTION(BlueprintCallable)
    void TurnRadioOff();
    
    UFUNCTION(BlueprintCallable)
    void TuneToStation(const URadioStationDataAsset* StationAsset, bool bShouldEnableRadio, bool bIsPlayer);
    
    UFUNCTION(BlueprintCallable)
    void TuneRadio(bool bSeekNext);
    
    UFUNCTION(BlueprintCallable)
    void ToggleRadio();
    
    UFUNCTION(BlueprintCallable)
    void SetState(bool bSetToOn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RadioTurnedOn();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RadioTurnedOff();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RadioTuned();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTunedToStation(const URadioStationDataAsset* RadioStation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetState() const;
    
};

