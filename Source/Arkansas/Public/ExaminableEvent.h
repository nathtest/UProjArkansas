#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "RPGInteractableRequirements.h"
#include "ScriptingEvent.h"
#include "ExaminableEvent.generated.h"

class UCodexDataAsset;
class UScriptEvent;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UExaminableEvent : public UScriptingEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString OverrideLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCodexDataAsset* Codex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RemoteEventOnExaminationEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString AltDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UScriptEvent*> AltScriptEvents;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRPGInteractableRequirements AlternateTextRPGRequirements;
    
public:
    UExaminableEvent();

};

