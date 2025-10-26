#pragma once
#include "CoreMinimal.h"
#include "OEIMusicManager.h"
#include "OEIMusicManager.h"

#include "EArithmeticOperation.h"
#include "EPhaseOfDay.h"
#include "OnLevelMusicLoadedDelegate.h"
#include "OnMusicBeatSyncDelegate.h"
#include "OwMusicManager.generated.h"

class AIndianaCharacter;
class UAkAudioEvent;
class UMapMusicData;

UCLASS(Blueprintable)
class UOwMusicManager : public UOEIMusicManager {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMusicBeatSync OnMusicBeatSync;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLevelMusicLoaded OnLevelMusicLoaded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMapMusicData* CurrentMapMusic;
    
public:
    UOwMusicManager();

    UFUNCTION(BlueprintCallable)
    void PostEvent(UAkAudioEvent* AkEvent);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPhaseOfDayChanged(EPhaseOfDay NewPhase);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnMusicSyncEntry(const float BarDuration, const float BeatDuration);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCombatStateChange(AIndianaCharacter* InCharacter, bool bInCombat, bool bRestoring);
    
public:
    UFUNCTION(BlueprintCallable)
    static void BP_SetMusicIntensityLimit(bool bCombat, bool bMinimum, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void BP_SetMusicIntensityLerpTime(bool bCombat, bool bEnter, float LerpTime);
    
    UFUNCTION(BlueprintCallable)
    static void BP_AddMusicIntensityModifier(bool bCombat, EArithmeticOperation ArithmeticOperation, float Value);
    
};

