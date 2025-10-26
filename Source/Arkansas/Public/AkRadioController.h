#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include <GameplayTagContainer.h>
#include "StationStruct.h"
#include "AkRadioController.generated.h"

class UAkAudioEvent;
class UAkEventArrayWithStation;
class UAkRtpc;
class UOEIWwiseObjectPoolWrapper;
class URadioStationDataAsset;
class UWorld;

UCLASS(Abstract, Blueprintable)
class ARKANSAS_API UAkRadioController : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStationStruct> Stations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URadioStationDataAsset*> RadioStationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAkEventArrayWithStation*> Channels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAkEventArrayWithStation*> Ads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOEIWwiseObjectPoolWrapper* EmitterPoolWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayBetweenSongs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkRtpc* RadioVolumeRTPC;
    
public:
    UAkRadioController();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlaySong(UAkAudioEvent* SongToPlay);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPostMapLoad(UWorld* World);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UAkAudioEvent* GetCurrentSongOnStation(const FGameplayTag& RadioStation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GamePauseChanged(bool bPaused);
    
};

