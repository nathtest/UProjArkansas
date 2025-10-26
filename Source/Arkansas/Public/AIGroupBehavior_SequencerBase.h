#pragma once
#include "CoreMinimal.h"
#include <LevelSequenceCameraSettings.h>
#include <TemplateSequencePlayer.h>

//CROSS-MODULE INCLUDE V2: -ModuleName=MovieScene -ObjectName=MovieSceneSequencePlaybackSettings -FallbackName=MovieSceneSequencePlaybackSettings
#include "AIGroupBehaviorRoleSelector.h"
#include "AIGroupBehavior_BlueprintBase.h"
#include "AIGroupBehavior_SequencerBase.generated.h"

class ULevelSequence;
class ULevelSequencePlayer;

UCLASS(Abstract, Blueprintable)
class ARKANSAS_API UAIGroupBehavior_SequencerBase : public UAIGroupBehavior_BlueprintBase, public IMovieScenePlaybackClient {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelSequence* LevelSequenceAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneSequencePlaybackSettings PlaybackSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelSequenceCameraSettings CameraSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelSequencePlayer* SequencePlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableAutoRole;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FAIGroupBehaviorRoleSelector, FName> RoleToSequencerTrackMap;
    
public:
    UAIGroupBehavior_SequencerBase();

protected:
    UFUNCTION(BlueprintCallable)
    void StopSequence();
    
    UFUNCTION(BlueprintCallable)
    void StartSequence();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSequenceStop();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSequenceFinished();
    
    UFUNCTION(BlueprintCallable)
    void Internal_OnSequenceStop();
    
    UFUNCTION(BlueprintCallable)
    void Internal_OnSequenceFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ULevelSequencePlayer* GetSequencePlayer() const;
    
    virtual bool RetrieveBindingOverrides(const FGuid& InBindingId, FMovieSceneSequenceID InSequenceID, TArray<UObject*, TInlineAllocator<1>>& OutObjects) const override;

    virtual UObject* GetInstanceData() const override;

    // Fix for true pure virtual functions not being implemented
};

