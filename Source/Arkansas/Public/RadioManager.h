#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RuntimeFloatCurve -FallbackName=RuntimeFloatCurve
#include <GameplayTagContainer.h>
#include "ELoadGameResult.h"
#include "ERadioPlayerType.h"
#include "LiveStationData.h"
#include "RadioPlayerWeakArray.h"
#include "RadioTypeRTPCData.h"
#include "SavedRadioStationInfo.h"
#include "RadioManager.generated.h"

class ARadioPlayer;
class UAkAudioEvent;
class URadioManager;
class URadioStationDataAsset;
class UWorld;

UCLASS(Abstract, Blueprintable)
class ARKANSAS_API URadioManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSoftObjectPtr<URadioStationDataAsset>> AlwaysPlayRadioStations;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<URadioStationDataAsset>> LoadedRadioStations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, TSoftObjectPtr<URadioStationDataAsset>> TaggedRadioStations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERadioPlayerType, FRadioTypeRTPCData> RadioTypeRTPCData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConversationFailureRetryTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RTPCStaticFrequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InCombatVoiceOverVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InConversationVoiceOverVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultVoiceOverVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InCombatMusicVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InConversationMusicVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultMusicVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InCombatTransitionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InConversationTransitionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RestorationTransitionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve InCombatTransition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve InConversationTransition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve RestorationTransition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* PauseEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* ResumeEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<URadioStationDataAsset*, FLiveStationData> LiveStationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<URadioStationDataAsset*, float> FailedConversationStations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<URadioStationDataAsset*, FRadioPlayerWeakArray> WorldRadios;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<ARadioPlayer>> RadiosLoadingStations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSoftObjectPtr<URadioStationDataAsset>> StationsWaitingOnConversationsToStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSoftObjectPtr<URadioStationDataAsset>> StationsLoadingToStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSoftObjectPtr<URadioStationDataAsset>> StationsQueuedForAlwaysPlaying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<URadioStationDataAsset>, FSavedRadioStationInfo> DiscoveredStations;
    
public:
    URadioManager();

protected:
    UFUNCTION(BlueprintCallable)
    void SongFinishedPlaying(const URadioStationDataAsset* Station);
    
    UFUNCTION(BlueprintCallable)
    void OnPreMapLoad(const FString& MapName);
    
    UFUNCTION(BlueprintCallable)
    void OnPostMapLoad(UWorld* World);
    
    UFUNCTION(BlueprintCallable)
    void OnLoadComplete(const FString& Filename, ELoadGameResult Result);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URadioStationDataAsset* GetStationAsset(const FGameplayTag& StationTag) const;
    
    UFUNCTION(BlueprintCallable)
    TArray<ARadioPlayer*> GetRadiosForStationWithTag(const FGameplayTag& StationTag);
    
    UFUNCTION(BlueprintCallable)
    TArray<ARadioPlayer*> GetRadiosForStation(const URadioStationDataAsset* StationAsset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static URadioManager* GetRadioManagerBP();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPlayerTuneToStationTag(FGameplayTag StationTag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPlayerTuneToStation(TSoftObjectPtr<URadioStationDataAsset> StationAsset) const;
    
};

