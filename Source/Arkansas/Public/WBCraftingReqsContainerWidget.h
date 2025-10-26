#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "IndianaUserWidget.h"
#include "WBCraftingReqsContainerWidget.generated.h"

class UInteractableRequirement;
class URPGInteractionContainerWidget;
class UTextBlockBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UWBCraftingReqsContainerWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* TitleTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URPGInteractionContainerWidget* RPGRequirementsContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TitleDisplayText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UInteractableRequirement*> CurrentItemRequirements;
    
public:
    UWBCraftingReqsContainerWidget();

};

