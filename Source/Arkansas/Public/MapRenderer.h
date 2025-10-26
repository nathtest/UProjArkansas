#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <GameplayTagContainer.h>
#include "MapRenderer.generated.h"

class UBoxComponent;
class UCameraComponent;
class USceneComponent;
class UTexture2D;

UCLASS(Blueprintable)
class ARKANSAS_API AMapRenderer : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AreaName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FloorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RenderUnitsScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D OutputResolution;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CameraDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CaptureTimeOfDay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableFog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableTonemapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableSceneFringe;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableGrass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableExposure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFixedExposure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FixedExposureBrightness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ExternalIncludeBoxes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ExternalExcludeBoxes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<AActor>> ExplicitHideActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> ExplicitHiddenActorClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer FilteredAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> FilteredActorNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* CapturePlane;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraComponent* CaptureCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* IncludeBoxes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* ExcludeBoxes;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPerspectiveCamera;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerspectiveCameraFoV;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeHighResBufferVisualizationTargets;
    
public:
    AMapRenderer(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateRenderUnitsScale();
    
    UFUNCTION(BlueprintCallable)
    UTexture2D* TakeRenderSceneCapture();
    
    UFUNCTION(BlueprintCallable)
    UTexture2D* TakeRender();
    
    UFUNCTION(BlueprintCallable)
    void RestorePostMaskTextureRender();
    
    UFUNCTION(BlueprintCallable)
    void RenderRoadMaskTexture();
    
    UFUNCTION(BlueprintCallable)
    void RenderFoliageMaskTexture();
    
    UFUNCTION(BlueprintCallable)
    void RenderBuildingMaskTexture();
    
    UFUNCTION(BlueprintCallable)
    void PrepareRenderRoadMaskTexture();
    
    UFUNCTION(BlueprintCallable)
    void PrepareRenderFoliageMaskTexture();
    
    UFUNCTION(BlueprintCallable)
    void PrepareRenderBuildingMaskTexture();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetMinBounds();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetMaxBounds();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetFloorName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetAreaName();
    
    UFUNCTION(BlueprintCallable)
    void AddRenderSceneCapture(float TextureSize, FRotator DesiredRotation);
    
};

