#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include <GameplayTagContainer.h>
#include "EEmotion.h"
#include "EmotionDataSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UEmotionDataSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FGameplayTag IgnoreBarkWhileInBLEBranchTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FGameplayTag IgnoreIfHelmetIsVisibleTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FGameplayTag IgnoreIfWithinTalkRangeTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FGameplayTag IgnoreIfOutsideOfTalkRangeTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FGameplayTag IgnoreIfInDialogTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FGameplayTag IgnoreIfOutOfDialogTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FGameplayTag IgnoreIfInConversation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FGameplayTag IgnoreIfOutOfConversation;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TMap<EEmotion, FGameplayTag> EmotionToGampelayTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FGameplayTag> OEIEmotionToGameplayTag;
    
public:
    UEmotionDataSettings();

};

