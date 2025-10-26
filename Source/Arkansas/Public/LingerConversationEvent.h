#pragma once
#include "CoreMinimal.h"
#include "ConversationReference.h"
#include "ConversationInstanceBlueprintParams.h"
#include "LingerConversationEvent.generated.h"

class AActor;
class AIndianaCharacter;
class AStagePrefabActor;

USTRUCT(BlueprintType)
struct FLingerConversationEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationReference Conversation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StartNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* StageInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AStagePrefabActor* StageAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AIndianaCharacter* ConversationOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationInstanceBlueprintParams ConversationInstanceBlueprintParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> CharacterOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowBarkConversation;
    
    ARKANSAS_API FLingerConversationEvent();
};

