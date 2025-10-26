#include "IdleCameraComponent.h"
#include "Camera/CameraComponent.h"

UIdleCameraComponent::UIdleCameraComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ComponentTags.AddDefaulted(1);
    this->bInheritPitch = false;
    this->bInheritRoll = false;
    this->bUseCameraLagSubstepping = false;
    this->bEnableIfIdle = true;
    this->SecondsToWait = 60.00f;
    this->bRotateIndependentOfCharacter = false;
    this->IdleRotationSpeed = 7.50f;
    this->IdleListenerPositioningSettings = NULL;
    this->IdleCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("IdleCamera_Camera"));
    this->IdleInputDetectionComponent = NULL;
}


