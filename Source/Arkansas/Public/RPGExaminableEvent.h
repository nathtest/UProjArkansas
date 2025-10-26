#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "InteractionEvent.h"
#include "RPGInteractableRequirements.h"
#include "RPGExaminableEvent.generated.h"

class UCodexDataAsset;
class URPGExaminableData;
class UScriptEvent;
class UTexture2D;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API URPGExaminableEvent : public UInteractionEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URPGExaminableData* RPGExaminableData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSinglePageExaminable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCodexDataAsset* Codex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString PageLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString PageText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString AltPageLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString AltPageText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString OverrideLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRPGInteractableRequirements AltPageRPGRequirements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UScriptEvent*> OnEnterScriptEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UScriptEvent*> OnExitScriptEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Image;
    
public:
    URPGExaminableEvent();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRPGExaminablePageExit(int32 PageIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRPGExaminablePageEnter(int32 PageIndex);
    
};

