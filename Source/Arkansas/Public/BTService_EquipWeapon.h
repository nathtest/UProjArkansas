#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "EEquipType.h"
#include "BTService_EquipWeapon.generated.h"

UCLASS(Blueprintable)
class UBTService_EquipWeapon : public UBTService {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEquipType EquipOnBecomeRelevant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEquipType EquipOnCeaseRelevant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInstantEquip;
    
public:
    UBTService_EquipWeapon();

};

