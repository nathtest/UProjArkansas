#pragma once
#include "CoreMinimal.h"
#include "ScriptEvent.h"
#include "Templates/SubclassOf.h"
#include "StartConversationEvent.generated.h"

class AActor;
class AIndianaCharacter;
class AStagePrefabActor;
class UConversationAsset;
class UOwConversationInstance;
class UOwFPVPresentationMode;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API UStartConversationEvent : public UScriptEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConversationAsset* Conversation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AIndianaCharacter* Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AStagePrefabActor* Stage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StartNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UOwFPVPresentationMode> PresentationMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UOwConversationInstance> ConversationInstanceClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> OverrideCharacters;
    
public:
    UStartConversationEvent();

};

