#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
#include <GameplayTagContainer.h>
#include "Gadget.h"
#include "GadgetXray.generated.h"

class AActor;
class UNewPropData;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UGadgetXray : public UGadget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNewPropData> NRayProp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNewPropData> NRayPropTPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag NRayCustomVisualTag;
    
public:
    UGadgetXray();

    UFUNCTION(BlueprintCallable)
    void OnPlayerConversationChange(AActor* Participant, const FGuid& NavigatorID, bool bEntered);
    
};

