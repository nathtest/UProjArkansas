#pragma once
#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "CauseDamageInfo.h"
#include "ComponentDebugInterface.h"
#include "EChangeRelationshipSource.h"
#include "ECrimeType.h"
#include "TeamSettings.h"
#include "Templates/SubclassOf.h"
#include "TeamComponent.generated.h"

class AActor;
class AIndianaAiCharacter;
class UHealthComponent;
class UTeamData;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UTeamComponent : public UActorComponent, public IComponentDebugInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTeamSettings TeamSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFactionCritical;
    
public:
    UTeamComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTeam(TSubclassOf<UTeamData> InTeamData);
    
    UFUNCTION(BlueprintCallable)
    void SetRelationshipToPlayer(TEnumAsByte<ETeamAttitude::Type> InRelationship, EChangeRelationshipSource InSource, ECrimeType InCrimeType);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSetStasis(AActor* StasisActor, bool bIsInStasis, bool bTemporaryStasis);
    
    UFUNCTION(BlueprintCallable)
    void OnKilled(UHealthComponent* HealthComponent, FCauseDamageInfo CDI);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOnTeam(TSubclassOf<UTeamData> InTeamData) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UTeamData> GetTeamData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<ETeamAttitude::Type> GetRelationshipWithTeam(TSubclassOf<UTeamData> InTeamData) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<ETeamAttitude::Type> GetRelationshipWithPlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<ETeamAttitude::Type> GetRelationship(const AActor* InActor) const;
    
    UFUNCTION(BlueprintCallable)
    void ClearRelationshipToPlayer(EChangeRelationshipSource InSource);
    
    UFUNCTION(BlueprintCallable)
    static void BPSetRelationshipToPlayer(AIndianaAiCharacter* Character, TEnumAsByte<ETeamAttitude::Type> Relationship);
    
    UFUNCTION(BlueprintCallable)
    static void BPClearRelationshipToPlayer(AIndianaAiCharacter* Character);
    

    // Fix for true pure virtual functions not being implemented
};

