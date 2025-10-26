#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree\BehaviorTreeComponent.h"

#include "AIPossessable.h"
#include "BehaviorClassTaskMigrationData.h"
#include "OwBehaviorTreeComponent.generated.h"

class UOwBehaviorTree;
class UOwBlackboardComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOwBehaviorTreeComponent : public UBehaviorTreeComponent, public IAIPossessable {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UOwBlackboardComponent* BlackboardComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsInGroupBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsGroupBehaviorLockActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsInInterrupt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCanTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBehaviorClassTaskMigrationData PendingClassTaskMigrationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOwBehaviorTree* BehaviorTreeData;
    
public:
    UOwBehaviorTreeComponent(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

