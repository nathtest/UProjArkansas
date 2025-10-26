#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AnimNotify -FallbackName=AnimNotify
#include <GameplayTagContainer.h>
#include "ETriggerTarget.h"
#include "AnimNotify_InteractableActor.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ARKANSAS_API UAnimNotify_InteractableActor : public UAnimNotify {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Event;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ETriggerTarget TriggerTarget;
    
public:
    UAnimNotify_InteractableActor();

};

