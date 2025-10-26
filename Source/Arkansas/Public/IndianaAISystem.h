#pragma once
#include "CoreMinimal.h"
#include "AISystem.h"

#include "IndianaAISystem.generated.h"

class UAITokenManager;
class USearchCoordinator;

UCLASS(Blueprintable, Config=Game)
class UIndianaAISystem : public UAISystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAITokenManager* TokenManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USearchCoordinator* SearchCoordinator;
    
public:
    UIndianaAISystem(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetArkansasAIDebugLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetArkansasAIDebugKeyword();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetAIDebugSearchLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetAIDebugNavLevel();
    
};

