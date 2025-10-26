#include "ActorStage.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneCaptureComponent2D -FallbackName=SceneCaptureComponent2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "Components/SceneCaptureComponent2D.h"
#include "Components/SceneComponent.h"

AActorStage::AActorStage(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->AttachPointSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("AttachPointSceneComponent"));
    this->FinalColorCaptureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCaptureComponent"));
    this->AlphaCaptureComponent = NULL;
    this->bEnableManualRotation = true;
    this->IdleResetSeconds = 3.00f;
    this->IdleTransitionSeconds = 1.50f;
    this->bLimitPitch = false;
    this->MaxPitch = 45.00f;
    this->bShowWeapon = true;
    this->ActiveVisuals = NULL;
    this->AttachPointSceneComponent->SetupAttachment(RootComponent);
    this->FinalColorCaptureComponent->SetupAttachment(RootComponent);
}


