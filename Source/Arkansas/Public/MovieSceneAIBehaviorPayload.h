#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=SoftClassPath -FallbackName=SoftClassPath
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=MemberReference -FallbackName=MemberReference
#include "FunctionPropertyDataWithObjects.h"
#include "MovieSceneAIBehaviorPayload.generated.h"

USTRUCT(BlueprintType)
struct ARKANSAS_API FMovieSceneAIBehaviorPayload {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AIBehaviorName;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMemberReference FunctionReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftClassPath FunctionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UClass* FunctionClassInst;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFunctionPropertyDataWithObjects PropertyDataWithObjects;
    
public:
    FMovieSceneAIBehaviorPayload();
};

