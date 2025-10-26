#include "Rift.h"
#include "Components/BoxComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=CameraShakeSourceComponent -FallbackName=CameraShakeSourceComponent
#include "Camera\CameraShakeSourceComponent.h"

#include "Components\PostProcessComponent.h"
#include "Components\SphereComponent.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Niagara -ObjectName=NiagaraComponent -FallbackName=NiagaraComponent
#include "NiagaraComponent.h"

#include "OEIWwiseAmbientEmitterComponent.h"
#include "OwAnimationProxyComponent.h"
#include "OwNavModifierComponent.h"

ARift::ARift(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DataLayerAsset = NULL;
    this->RiftDuration = 15.00f;
    this->RiftIndex = 0;
    this->RiftMaterialStatic = NULL;
    this->RiftMaterialSkeletal = NULL;
    this->MaterialParameterCollection = NULL;
    this->WwiseRiftCoreOpen = NULL;
    this->WwiseRiftCoreClosed = NULL;
    this->WwiseRiftOpenPlayerStart = NULL;
    this->WwiseRiftOpenPlayerStop = NULL;
    this->WwiseRiftCoreProximityRadiusIn = NULL;
    this->WwiseRiftCoreProximityRadiusOut = NULL;
    this->WwiseRiftCoreConditionStateOpen = NULL;
    this->WwiseRiftCoreConditionStateClosed = NULL;
    this->WwiseRiftCoreConditionRTPC = NULL;
    this->WwiseMomentsRiftAnimRTPC = NULL;
    this->RiftAmbientFXTickRate = 0.05f;
    this->RiftAmbientFXExponentialCurve = NULL;
    this->RiftAmbientFXIntensityCurve = NULL;
    this->RiftAmbientFXPlayerDistanceModifierCurve = NULL;
    this->bIsRiftOpen = false;
    this->bIsRiftedRift = false;
    this->bIsBurstActive = false;
    this->bIsBurstForward = false;
    this->RiftOpenTime = 0.00f;
    this->bIsRiftCountdownActive = false;
    this->RiftCountdownTime = 0.00f;
    this->bIsScalarActive = false;
    this->ScalarTime = 0.00f;
    this->bScalarTimelineDirectionForward = false;
    this->PlayerCharacter = NULL;
    this->InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
    this->KillSphere = CreateDefaultSubobject<USphereComponent>(TEXT("KillSphere"));
    this->NiagaraCore = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraCore"));
    this->NiagaraCoreCalm = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraCoreCalm"));
    this->CalmGlobalVarValue = 0;
    this->NiagaraBurst = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraBurst"));
    this->PostProcessBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PostProcessBox"));
    this->PostProcessComponent = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcessComponent"));
    this->AmbientEmitterComponent = CreateDefaultSubobject<UOEIWwiseAmbientEmitterComponent>(TEXT("OEIWwiseAmbientEmitter"));
    this->AnimationProxyComponent = CreateDefaultSubobject<UOwAnimationProxyComponent>(TEXT("OwAnimationProxy"));
    this->CameraShakeSourceComponent = CreateDefaultSubobject<UCameraShakeSourceComponent>(TEXT("CameraShakeSource"));
    this->ClosedNavModifierComponent = CreateDefaultSubobject<UOwNavModifierComponent>(TEXT("ClosedNavModifier"));
    this->CachedDataLayerAsset = NULL;
    this->DataLayerManager = NULL;
    this->DataLayerInstance = NULL;
    this->MaterialParameterCollectionInstance = NULL;
    this->AmbientEmitterComponent->SetupAttachment(RootComponent);
    this->AnimationProxyComponent->SetupAttachment(RootComponent);
    this->CameraShakeSourceComponent->SetupAttachment(InteractionSphere);
    this->InteractionSphere->SetupAttachment(RootComponent);
    this->KillSphere->SetupAttachment(InteractionSphere);
    this->NiagaraBurst->SetupAttachment(InteractionSphere);
    this->NiagaraCore->SetupAttachment(InteractionSphere);
    this->NiagaraCoreCalm->SetupAttachment(InteractionSphere);
    this->PostProcessBox->SetupAttachment(InteractionSphere);
    this->PostProcessComponent->SetupAttachment(PostProcessBox);
}

void ARift::UpdateRiftPositionParam() {
}


void ARift::UnpauseRift(UOwConversationInstance* Instance) {
}

void ARift::UnloadActors() {
}

void ARift::ShowRifts() {
}

void ARift::SetRiftTransitionParam(float Value) {
}

void ARift::SetRiftCountDownParam(float Value) {
}

void ARift::SetIsRiftedRift(bool bIsRifted) {
}

void ARift::SetBaseMeshVisibility(bool bIsVisible) {
}





void ARift::PauseRift(UOwConversationInstance* Instance) {
}


void ARift::OnRiftTimerHandleEnd() {
}

void ARift::OnRiftAmbientFXTimerHandleEnd() {
}

void ARift::OnPostProcessEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ARift::OnPostProcessBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ARift::OnNavTimerHandleEnd() {
}

void ARift::OnKillSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ARift::OnGlobalVariableChanged(const FGuid& GlobalVariable, int32 Value) {
}

void ARift::OnAnimNotifyEventTriggered(FGameplayTag Event) {
}

void ARift::HideRifts() {
}

void ARift::CloseRift() {
}

void ARift::BP_SetRiftCalm(bool bInCalm) {
}


void ARift::ActivateActors() {
}


