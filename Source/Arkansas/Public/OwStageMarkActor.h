#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=NavAgentInterface -FallbackName=NavAgentInterface
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICinematics -ObjectName=StageMarkActor -FallbackName=StageMarkActor
#include "StageMarkActor.h"

#include "ConversationReference.h"
#include "OwStageMarkActor.generated.h"

class AOwStageMarkActor;
class UConversationLightingRigComponent;

UCLASS(Blueprintable)
class ARKANSAS_API AOwStageMarkActor : public AStageMarkActor, public INavAgentInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AcceptableRangeRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AOwStageMarkActor* LinkedMarkActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AOwStageMarkActor* LinkedRelativePositionMarkActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationReference RequiredConversation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConversationLightingRigComponent* ConversationLightingRigComponent;
    
public:
    AOwStageMarkActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetMarkPriority(uint8 InMarkPriority);
    

    // Fix for true pure virtual functions not being implemented
};

