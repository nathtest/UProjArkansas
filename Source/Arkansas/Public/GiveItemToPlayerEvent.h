#pragma once
#include "CoreMinimal.h"
#include "ScriptEvent.h"
#include "Templates/SubclassOf.h"
#include "GiveItemToPlayerEvent.generated.h"

class UItem;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API UGiveItemToPlayerEvent : public UScriptEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItem> Item;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Count;
    
public:
    UGiveItemToPlayerEvent();

};

