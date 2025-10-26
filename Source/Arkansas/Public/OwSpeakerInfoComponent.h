#pragma once
#include "CoreMinimal.h"
#include <EOEIGender.h>
#include "ConversationReference.h"
#include "SpeakerInfoComponent.h"


#include <SpeakerReference.h>
#include <LocString.h>
#include "ConversationDescription.h"
#include "ConversationInstanceBlueprintParams.h"
#include "OwSpeakerInfo.h"
#include "SpeakerConditional.h"
#include "SpeakerCustomCameraData.h"
#include "StageConditional.h"
#include "Templates/SubclassOf.h"
#include "OwSpeakerInfoComponent.generated.h"

class AActor;
class ACameraActor;
class AOwStageMarkActor;
class AStagePrefabActor;
class UAkAuxBus;
class UOwFPVPresentationMode;
class UStagePrefabAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UOwSpeakerInfoComponent : public USpeakerInfoComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationInstanceBlueprintParams ConversationInstanceBlueprintParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> CharacterOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpeakerReference> SpeakerOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpeakerConditional> RemovedSpeakerConditionals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* LookTargetOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FConversationReference, AActor*> LookTargetOverrideMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowBarkConversationDuringCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOwSpeakerInfo OwSpeakerInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString OverrideName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideSpeakerName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideFactionInfoInConversation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationDescription InterrogationDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsesStageMarks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoAlignToAssignedStageMarks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStageConditional> StageConditionals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AStagePrefabActor* StageInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStagePrefabAsset* StageAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableSpawnedStageLightingRigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* StageSpawnLocationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMovePlayerToMark;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UOwFPVPresentationMode> CustomPresentationMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FConversationReference, TSoftObjectPtr<ACameraActor>> CustomConversationCameras;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FConversationReference, FSpeakerCustomCameraData> CustomConversationCameraData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AOwStageMarkActor*> BackupStageMarkActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAuxBus* DefaultDynamicFxAuxBus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AttenuationScaling;
    
public:
    UOwSpeakerInfoComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSpeakerReference GetSpeakerReference() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EOEIGender GetGender() const;
    
};

