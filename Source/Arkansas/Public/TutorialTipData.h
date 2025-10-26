#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "RenderSafeInputLabelDescription.h"
#include "TutorialTipData.generated.h"

USTRUCT(BlueprintType)
struct FTutorialTipData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasInputLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSafeInputLabelDescription InputLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasSecondaryInputLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSafeInputLabelDescription SecondaryInputLabel;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString LoadingTipText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldPrioritize;
    
public:
    ARKANSAS_API FTutorialTipData();
};

