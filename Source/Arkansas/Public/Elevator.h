#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RuntimeFloatCurve -FallbackName=RuntimeFloatCurve
#include <LocString.h>
#include "ECarriageWallDir.h"
#include "EInteractionType.h"
#include "ElevatorFloorData.h"
#include "ElevatorMoveEndDelegate.h"
#include "ElevatorMoveStartDelegate.h"
#include "ElevatorUseDelegate.h"
#include "ElevatorWaitLocationData.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "MapFloorTrackedActor.h"
#include "RPGInteractableRequirements.h"
#include "Elevator.generated.h"

class AIndianaCharacter;
class UAkComponent;
class UBeaconComponent;
class UBoxComponent;
class UChildActorComponent;
class UInteractableAudioComponent;
class UInteractableComponent;
class UMovingStageBoxComponent;
class UObsidianIDComponent;
class UPointOfInterestData;
class USceneComponent;
class USplineComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ARKANSAS_API AElevator : public AActor, public IMapFloorTrackedActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FElevatorUse OnElevatorUse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FElevatorMoveStart OnElevatorMoveStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FElevatorMoveEnd OnElevatorMoveEnd;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialSplineTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceMovedPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* CarriageComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* FrameMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* AkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBeaconComponent* WPBeaconComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMovingStageBoxComponent* MovingStageBoxComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FElevatorFloorData> Floors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString ElevatorDisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* WallMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* DoorMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* LeftDoorPanelMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* RightDoorPanelMesh;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector GhostNavOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableAudioComponent* InteractableAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartDisabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasDoorPanels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideTransition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEscapeBlockers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bActivateBlockersOnFloorSelect;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuppressWaitLocationMapCheckWarnings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve TargetFloorProximitySpeedScalarCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UChildActorComponent*> FloorGhostNavMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* FrontDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* RightDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BackDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* LeftDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* FrontRightDoorPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* FrontLeftDoorPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* RightRightDoorPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* RightLeftDoorPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BackRightDoorPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BackLeftDoorPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* LeftRightDoorPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* LeftLeftDoorPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UBoxComponent*> EscapeBlockers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* WaitLocationLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* WaitLocationMiddle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* WaitLocationRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<USceneComponent*, FElevatorWaitLocationData> CachedWaitLocationDatas;
    
public:
    AElevator(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateCurrentFloor();
    
    UFUNCTION(BlueprintCallable)
    void TeleportToFloor(int32 FloorIndex, bool bUpdateCarriage);
    
    UFUNCTION(BlueprintCallable)
    void StartMove();
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetDoorPanelsOpenWidth(ECarriageWallDir Dir, float Width);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetDistanceMovedPerSecond(float NewDistanceMovedPerSecond);
    
    UFUNCTION(BlueprintCallable)
    void SetDisabled(bool bNewDisabled);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentFloor(int32 FloorIndex, bool bIgnoreRequirements);
    
    UFUNCTION(BlueprintCallable)
    bool PassesRPGRequirements(uint8 InteractionIndex);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnUpdateEmissiveMaterials();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStationary() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMoving() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPointOfInterestData* GetTravelDestinationData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTargetFloor() const;
    
    UFUNCTION(BlueprintCallable)
    FRPGInteractableRequirements GetRPGRequirements(EInteractionType InteractionType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumberOfFloors() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<EInteractionType> GetInteractions(const FInteractionDescription& Description) const;
    
    UFUNCTION(BlueprintCallable)
    float GetInteractHoldTime(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECarriageWallDir GetGroundFloorDir() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetGroundFloor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FElevatorFloorData GetFloorData(int32 FloorIndex) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetDisabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECarriageWallDir GetCurrentFloorDir() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentFloor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FRotator GetCarriageWiggleRotation(float TimelineTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FElevatorFloorData> GetAllFloorData() const;
    
    UFUNCTION(BlueprintCallable)
    void CompleteInteract(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAccessFloor(int32 FloorIndex) const;
    

    // Fix for true pure virtual functions not being implemented
};

