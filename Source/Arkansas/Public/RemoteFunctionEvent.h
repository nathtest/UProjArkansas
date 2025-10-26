#pragma once
#include "CoreMinimal.h"
#include "ScriptEvent.h"
#include "RemoteFunctionEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API URemoteFunctionEvent : public UScriptEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RemoteEventOnExaminationEnd;
    
public:
    URemoteFunctionEvent();

};

