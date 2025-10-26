#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "InteractableAnimProxyActor.h"
#include "OnAnimNotifyDelegate.h"
#include "RPGInteractableState.h"
#include "Templates/SubclassOf.h"
#include "RPGInteractable.generated.h"

class URPGInteractableAudioComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ARKANSAS_API ARPGInteractable : public AInteractableAnimProxyActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAnimNotify OnAnimNotifyEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseInteractableStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanOnlyBeUsedOnce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FRPGInteractableState> InteractableStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DefaultInteractableState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneToAttachMeshTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* MeshToAttachTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* AttachedMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URPGInteractableAudioComponent> AudioComponentClass;
    
public:
    ARPGInteractable(const FObjectInitializer& ObjectInitializer);

};

