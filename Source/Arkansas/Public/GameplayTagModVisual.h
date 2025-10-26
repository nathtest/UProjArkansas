#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "ModVisual.h"
#include "GameplayTagModVisual.generated.h"

class UModVisualCollection;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UGameplayTagModVisual : public UModVisual {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GameplayTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModVisualCollection* ModVisualCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyToBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyToChildren;
    
public:
    UGameplayTagModVisual();

};

