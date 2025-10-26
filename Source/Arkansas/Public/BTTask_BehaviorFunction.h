#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=SoftClassPath -FallbackName=SoftClassPath
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=MemberReference -FallbackName=MemberReference
#include "BTTask_OwBase.h"
#include "FunctionPropertyDataWithObjects.h"
#include "BTTask_BehaviorFunction.generated.h"

class AIndianaAiCharacter;
class AIndianaAiController;
class UBlueprint;

UCLASS(Blueprintable)
class ARKANSAS_API UBTTask_BehaviorFunction : public UBTTask_OwBase {
    GENERATED_BODY()
public:
protected:
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMemberReference FunctionReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftClassPath FunctionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UClass* FunctionClassInst;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AIndianaAiCharacter* CharacterOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AIndianaAiController* ControllerOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFunctionPropertyDataWithObjects PropertyDataWithObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bWaitForDeferredResult: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bRestartFunctionOnResume: 1;
    
public:
    UBTTask_BehaviorFunction();

protected:
    UFUNCTION(BlueprintCallable)
    void OnFunctionClassBlueprintCompiled(UBlueprint* Blueprint);
    
    UFUNCTION(BlueprintCallable)
    void OnAIBehaviorFunctionDeferredResult(bool bSuccess);
    
};

