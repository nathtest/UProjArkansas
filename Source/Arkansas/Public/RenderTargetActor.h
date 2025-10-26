#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <ConversationNavigator.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIFlowCharts -ObjectName=FlowChartNode -FallbackName=FlowChartNode
#include <SpeakerReference.h>
#include "RenderTargetDisplayInterface.h"
#include "RenderTargetActor.generated.h"

class ASceneCapture2D;
class UMaterialInterface;
class UMeshComponent;
class UStaticMeshComponent;
class UTexture;

UCLASS(Blueprintable, MinimalAPI)
class ARenderTargetActor : public AActor, public IRenderTargetDisplayInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float TVStaticValue;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* StandbyMatInterface;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* RenderTargetMatInterface;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* ImageMatInterface;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RenderTargetMatIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASceneCapture2D> Camera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FSpeakerReference, TSoftObjectPtr<ASceneCapture2D>> SpeakerCameraMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanAnimateStatic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoActivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAnimateCPDs;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMeshComponent*> RenderTargetMeshComponents;
    
public:
    ARenderTargetActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ShowImage(TSoftObjectPtr<UTexture> ImageTexture, int32 ClearNodeID);
    
    UFUNCTION(BlueprintCallable)
    void SetRenderShown(bool bNewRenderShown, FSpeakerReference Speaker);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnEnteredNode(const FConversationNavigator& Navigator, const FFlowChartNode& Node, bool bIsFirstVisit);
    
public:
    UFUNCTION(BlueprintCallable)
    void HideImage();
    

    // Fix for true pure virtual functions not being implemented
};

