#pragma once
#include "CoreMinimal.h"
#include "GameFrameWork\CheatManager.h"

#include "ESkillDifficultyTier.h"
#include "OwCheatManager.generated.h"

UCLASS(Blueprintable)
class UOwCheatManager : public UCheatManager {
    GENERATED_BODY()
public:
    UOwCheatManager();

    UFUNCTION(BlueprintCallable, Exec)
    void ViewNearbyBugs(float Range);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleStageVisualization();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleFPVCameraMovement();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestAllPopupNotifications();
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetLevelNPC(int32 NewLevel);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RevokeEntitlement(const FString& Entitlement);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ResetFPVCameraMovement();
    
    UFUNCTION(BlueprintCallable, Exec)
    void RemoveCameraModifier(const FString& CameraModifierName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LootTableDebug(const FString& LootTable, int32 NumTimes, ESkillDifficultyTier SkillDiffultyTier);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LockFPVCameraMovement();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GivePlayerAllItems();
    
    UFUNCTION(BlueprintCallable, Exec)
    void EnableCameraModifier(const FString& CameraModifierName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DropAllItemsDebug(bool bSplitStacks);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DisableCameraModifier(const FString& CameraModifierName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddCameraModifier(const FString& CameraModifierName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AcquireEntitlement(const FString& Entitlement);
    
};

