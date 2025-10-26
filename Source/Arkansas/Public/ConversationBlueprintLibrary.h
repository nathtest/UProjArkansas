#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICommon -ObjectName=EBoolResult -FallbackName=EBoolResult
#include "ConversationReference.h"
#include "ConversationInstanceBlueprintParams.h"
#include "ESpecialObsidianID.h"
#include "Templates/SubclassOf.h"
#include "ConversationBlueprintLibrary.generated.h"

class AActor;
class AIndianaCharacter;
class AStagePrefabActor;
class UBroadcastStationAsset;
class UConversationAsset;
class UObject;
class UOwConversationInstance;
class UOwFPVPresentationMode;

UCLASS(Blueprintable, MinimalAPI)
class UConversationBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UConversationBlueprintLibrary();

    UFUNCTION(BlueprintCallable)
    static void StopRadioStation(UBroadcastStationAsset* Station);
    
    UFUNCTION(BlueprintCallable)
    static void StartRadioStation(UBroadcastStationAsset* Station, int32 StartNode, bool bAllowRestart);
    
    UFUNCTION(BlueprintCallable)
    static UOwConversationInstance* StartConversationWithCompanion(ESpecialObsidianID CompanionID, UConversationAsset* Conversation, int32 StartNode, AStagePrefabActor* Stage, const FConversationInstanceBlueprintParams& InstanceBlueprintParams, EBoolResult& Result, bool bAllowBarkConversationDuringCombat);
    
    UFUNCTION(BlueprintCallable)
    static UOwConversationInstance* StartConversationWithActor(AActor* Speaker, int32 StartNode, AStagePrefabActor* Stage, EBoolResult& Result, bool bAllowBarkConversationDuringCombat);
    
    UFUNCTION(BlueprintCallable)
    static UOwConversationInstance* StartConversation(UConversationAsset* Conversation, AIndianaCharacter* Owner, AStagePrefabActor* Stage, TSubclassOf<UOwFPVPresentationMode> PresentationMode, int32 StartNode, const FConversationInstanceBlueprintParams& InstanceBlueprintParams, TArray<AActor*> OverrideCharacters, EBoolResult& Result, bool bAllowBarkConversationDuringCombat);
    
    UFUNCTION(BlueprintCallable)
    static void SetRadioStation(UBroadcastStationAsset* Station);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsMatchingSpeaker(const AActor* SpeakerActor, FGuid SpeakerID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsMatchingConversation(const FConversationReference& InConversation, FGuid ConversationID);
    
    UFUNCTION(BlueprintCallable)
    static FGuid GetConversationInstanceID(const UOwConversationInstance* Instance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UOwConversationInstance* GetActivePlayerConversation();
    
    UFUNCTION(BlueprintCallable)
    static void ForceRadioStation(UBroadcastStationAsset* Station);
    
    UFUNCTION(BlueprintCallable)
    static void EndRadioStation(UBroadcastStationAsset* Station);
    
    UFUNCTION(BlueprintCallable)
    static void EndConversationInstance(const UOwConversationInstance* Instance);
    
    UFUNCTION(BlueprintCallable)
    static void EndConversation(FGuid ConversationID);
    
    UFUNCTION(BlueprintCallable)
    static void DiscoverRadioStation(UBroadcastStationAsset* Station, bool bDiscovered);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool CompareSpeakerIDs(FGuid SpeakerA, FGuid SpeakerB);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool CanStartConversation(const UObject* WorldContextObject, UConversationAsset* Conversation, EBoolResult& Result, bool bAllowBarkConversationDuringCombat);
    
    UFUNCTION(BlueprintCallable)
    static void AdvanceConversationInstance(UOwConversationInstance* Instance);
    
};

