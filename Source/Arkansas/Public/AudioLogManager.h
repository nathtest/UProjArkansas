#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include <SpeakerReference.h>
#include <LocString.h>
#include "EAudioLogPlayState.h"
#include "ELoadGameResult.h"
#include "AudioLogManager.generated.h"

class UAkAudioEvent;
class UAudioLogItem;
class UOwConversationInstance;
class UWorld;

UCLASS(Abstract, Blueprintable)
class ARKANSAS_API UAudioLogManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString InvalidAudioLogName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* PauseEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* ResumeEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TempAudioLogName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostCombatTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostConversationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAudioLogPlayState CurrentAudioLogPlayState;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOwConversationInstance* CurrentPlayingAudioLog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAudioLogItem*> AudioLogs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FSpeakerReference> AudioLogSpeakers;
    
public:
    UAudioLogManager();

    UFUNCTION(BlueprintCallable)
    void StopCurrentAudioLog(bool bForce);
    
    UFUNCTION(BlueprintCallable)
    void ResumeCurrentAudioLog(bool bForce, bool bFromPlay);
    
    UFUNCTION(BlueprintCallable)
    void PlayAudioLog(const FGuid& AudioLogID);
    
    UFUNCTION(BlueprintCallable)
    void PauseCurrentAudioLog(bool bForce, bool bFromStop);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPreMapLoad(const FString& MapName);
    
    UFUNCTION(BlueprintCallable)
    void OnPostMapLoad(UWorld* World);
    
    UFUNCTION(BlueprintCallable)
    void OnLoadComplete(const FString& Filename, ELoadGameResult Result);
    
    UFUNCTION(BlueprintCallable)
    void OnConversationEnded(UOwConversationInstance* ConversationInstance);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayingAudioLog() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAudioLogPlayState GetCurrentAudioLogPlayState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanStopCurrentAudioLog(bool bExclusive) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanResumeCurrentAudioLog(bool bExclusive) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPauseCurrentAudioLog(bool bExclusive) const;
    
};

