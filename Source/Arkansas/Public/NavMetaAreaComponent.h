#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Box -FallbackName=Box
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "NavRelevantComponent.h"
#include "NavModifierCylinder.h"
#include "RotatedBox.h"
#include "NavMetaAreaComponent.generated.h"

class ARecastNavMesh;
class UPrimitiveComponent;

UCLASS(Blueprintable, DefaultConfig, Deprecated, NotPlaceable, ClassGroup=Custom, Config=Engine, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UDEPRECATED_NavMetaAreaComponent : public UNavRelevantComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAffectsGroundPoly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAffectsOffMeshPoly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseComplexGeomAsNavEdges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPhysicsCollisionOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCustomCollisionOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCustomCollisionRelative;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeAgentHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* CollisionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRotatedBox> CustomCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNavModifierCylinder> CustomCollisionCylinders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Extents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultMetaDataToAdd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultMetaDataToRemove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DefaultInvalidatePaths;
    
    UDEPRECATED_NavMetaAreaComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void K2_RequestInvalidatePaths();
    
    UFUNCTION(BlueprintCallable)
    void K2_RemoveMetaData(int32 MetaData);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void K2_ProcessSinglePoly(ARecastNavMesh* NavigationData, FVector PolyCenter, FBox AreaBounds);
    
    UFUNCTION(BlueprintCallable)
    void K2_MarkAreaDirtyCustom(int32 MetaDataToAdd, int32 MetaDataToRemove, bool bInvalidatePaths);
    
    UFUNCTION(BlueprintCallable)
    void K2_MarkAreaDirty();
    
    UFUNCTION(BlueprintCallable)
    void K2_AddMetaData(int32 MetaData);
    
};

