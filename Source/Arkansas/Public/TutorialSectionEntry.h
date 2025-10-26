#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "ETutorialType.h"
#include "LogicalExpression.h"
#include "TutorialCenterScreenData.h"
#include "TutorialFullScreenData.h"
#include "TutorialSectionEntry.generated.h"

USTRUCT(BlueprintType)
struct FTutorialSectionEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag TutorialGameplayTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETutorialType TutorialType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTutorialFullScreenData FullScreenTutorial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTutorialCenterScreenData CenterScreenTutorial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 TutorialSortOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicalExpression Conditional;
    
    ARKANSAS_API FTutorialSectionEntry();
};

