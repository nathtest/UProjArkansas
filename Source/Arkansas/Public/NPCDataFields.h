#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "GeneralDataFields.h"
#include "NPCDataFields.generated.h"

class AIndianaAiCharacter;

USTRUCT(BlueprintType)
struct FNPCDataFields : public FGeneralDataFields {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Occupation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AIndianaAiCharacter> ReferenceNPC;
    
public:
    ARKANSAS_API FNPCDataFields();
};

