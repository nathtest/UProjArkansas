#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "ScriptEvent.h"
#include "InteractionScriptEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API UInteractionScriptEvent : public UScriptEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ExecuteOnAnimNotifyTag;
    
public:
    UInteractionScriptEvent();

};

