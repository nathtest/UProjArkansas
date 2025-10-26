#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "AIGroupBehavior_CompanionCommandBase.h"
#include "ECompanionCombatAbilitySuccessAudioTiming.h"
#include "ECompanionCombatAbilityTargetType.h"
#include "AIGroupBehavior_CompanionCombatAbilityCommandBase.generated.h"

UCLASS(Abstract, Blueprintable, Config=Game)
class ARKANSAS_API UAIGroupBehavior_CompanionCombatAbilityCommandBase : public UAIGroupBehavior_CompanionCommandBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECompanionCombatAbilityTargetType TargetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationSoundRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SoundStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECompanionCombatAbilitySuccessAudioTiming AbilitySuccessAudioTiming;
    
public:
    UAIGroupBehavior_CompanionCombatAbilityCommandBase();

};

