#pragma once
#include "CoreMinimal.h"
#include <GlobalVariableReference.h>
#include <LocString.h>
#include "ESpeechFlavorTag.h"
#include "DialogTrait.generated.h"

USTRUCT(BlueprintType)
struct FDialogTrait {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference GlobalVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<ESpeechFlavorTag> SpeechFlavorTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TraitName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BonusAmount;
    
public:
    ARKANSAS_API FDialogTrait();
};

