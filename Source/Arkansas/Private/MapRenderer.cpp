#include "MapRenderer.h"
#include "Components/BoxComponent.h"
#include "Camera/CameraComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

AMapRenderer::AMapRenderer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bRelevantForLevelBounds = false;
    this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CapturePlane"));
    this->RenderUnitsScale = 20.00f;
    this->CameraDistance = 10000.00f;
    this->CaptureTimeOfDay = 0.50f;
    this->bDisableFog = true;
    this->bDisableTonemapper = false;
    this->bDisableSceneFringe = true;
    this->bDisableParticles = true;
    this->bDisableGrass = false;
    this->bDisableExposure = false;
    this->bFixedExposure = false;
    this->FixedExposureBrightness = 0.10f;
    this->ExplicitHiddenActorClasses.AddDefaulted(3);
    this->FilteredActorNames.AddDefaulted(2);
    this->CapturePlane = (UBoxComponent*)RootComponent;
    this->CaptureCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CaptureCamera"));
    this->IncludeBoxes = CreateDefaultSubobject<USceneComponent>(TEXT("IncludeBoxes"));
    this->ExcludeBoxes = CreateDefaultSubobject<USceneComponent>(TEXT("ExcludeBoxes"));
    this->bPerspectiveCamera = false;
    this->PerspectiveCameraFoV = 5.00f;
    this->bIncludeHighResBufferVisualizationTargets = false;
}

void AMapRenderer::UpdateRenderUnitsScale() {
}

UTexture2D* AMapRenderer::TakeRenderSceneCapture() {
    return NULL;
}

UTexture2D* AMapRenderer::TakeRender() {
    return NULL;
}

void AMapRenderer::RestorePostMaskTextureRender() {
}

void AMapRenderer::RenderRoadMaskTexture() {
}

void AMapRenderer::RenderFoliageMaskTexture() {
}

void AMapRenderer::RenderBuildingMaskTexture() {
}

void AMapRenderer::PrepareRenderRoadMaskTexture() {
}

void AMapRenderer::PrepareRenderFoliageMaskTexture() {
}

void AMapRenderer::PrepareRenderBuildingMaskTexture() {
}

FVector2D AMapRenderer::GetMinBounds() {
    return FVector2D{};
}

FVector2D AMapRenderer::GetMaxBounds() {
    return FVector2D{};
}

FName AMapRenderer::GetFloorName() {
    return NAME_None;
}

FName AMapRenderer::GetAreaName() {
    return NAME_None;
}

void AMapRenderer::AddRenderSceneCapture(float TextureSize, FRotator DesiredRotation) {
}


