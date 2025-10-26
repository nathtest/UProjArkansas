#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "ScriptingEvent.h"
#include "FPVAnimProxyEvent.generated.h"

class UAnimMontage;
class UAnimSequenceBase;
class UAnimationProxyData;
class UStaticMesh;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API UFPVAnimProxyEvent : public UScriptingEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAnimationProxyData> AnimationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AnimProxyKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag BackAnimProxyKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* PropMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* InteractableAnimSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LoopInteractableAnimSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, UAnimMontage*> MontageToPlayForScriptedGoToState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInstantAnimate;
    
public:
    UFPVAnimProxyEvent();

    UFUNCTION(BlueprintCallable)
    void OnAnimProxyComplete();
    
};

