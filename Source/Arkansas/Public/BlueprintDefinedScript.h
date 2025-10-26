#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=MemberReference -FallbackName=MemberReference
#include "EBlueprintDefinedScriptCategory.h"
#include "FunctionPropertyDataWithObjects.h"
#include "BlueprintDefinedScript.generated.h"

USTRUCT(BlueprintType)
struct ARKANSAS_API FBlueprintDefinedScript {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBlueprintDefinedScriptCategory BlueprintDefinedScriptCategory;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMemberReference FunctionReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* FunctionClassInst;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFunctionPropertyDataWithObjects PropertyDataWithObjects;
    
    FBlueprintDefinedScript();
};

