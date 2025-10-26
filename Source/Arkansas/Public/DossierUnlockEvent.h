#pragma once
#include "CoreMinimal.h"
#include "ScriptEvent.h"
#include "DossierEntryGroup.h"
#include "DossierUnlockEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API UDossierUnlockEvent : public UScriptEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDossierEntryGroup EntriesToUnlock;
    
    UDossierUnlockEvent();

};

