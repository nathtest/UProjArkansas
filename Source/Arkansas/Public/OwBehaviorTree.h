#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AIFilterCharacter.h"
#include "AIFilterController.h"
#include "OwBehaviorTree.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API UOwBehaviorTree : public UBehaviorTree {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAIFilterCharacter> CharacterPassList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAIFilterCharacter> CharacterBlockList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAIFilterController> ControllerPassList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAIFilterController> ControllerBlockList;
    
public:
    UOwBehaviorTree();

};

