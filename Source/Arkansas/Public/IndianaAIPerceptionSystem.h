#pragma once
#include "CoreMinimal.h"
#include "Perception/AIPerceptionSystem.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ESoundDetectionType.h"
#include "IndianaAIPerceptionSystem.generated.h"

class AActor;
class UShapeComponent;

UCLASS(Blueprintable)
class UIndianaAIPerceptionSystem : public UAIPerceptionSystem {
    GENERATED_BODY()
public:
    UIndianaAIPerceptionSystem();

    UFUNCTION(BlueprintCallable)
    static void TriggerAISoundStimulus(FVector NoiseLocation, AActor* ShoutTarget, FVector ShoutTargetLocation, ESoundDetectionType SoundType, AActor* Instigator, float SoundRadius, float AwarenessFromSound, int32 StimulusGroupID);
    
    UFUNCTION(BlueprintCallable)
    static void ActivateTurretsInShapeComponent(AActor* Target, UShapeComponent* ShapeComponent);
    
    UFUNCTION(BlueprintCallable)
    static void ActivateTurretsInShapeActor(AActor* Target, AActor* ShapeActor);
    
    UFUNCTION(BlueprintCallable)
    static void ActivateTurretsInRadius(AActor* Target, float ActivationRadius);
    
    UFUNCTION(BlueprintCallable)
    static void ActivateTurret(AActor* Target, AActor* Turret);
    
};

