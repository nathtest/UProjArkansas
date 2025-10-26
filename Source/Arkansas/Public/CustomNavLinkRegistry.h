#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=NavLinkAuxiliaryId -FallbackName=NavLinkAuxiliaryId
#include "NavRelevantComponent.h"
#include "PendingNavLinkChunk.h"
#include "CustomNavLinkRegistry.generated.h"

class UCustomNavLinkBase;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCustomNavLinkRegistry : public UNavRelevantComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UCustomNavLinkBase*> CustomNavLinkPtrs;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavLinkAuxiliaryId CustomNavLinkAuxiliaryId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPendingNavLinkChunk> PendingNavLinkChunks;
    
public:
    UCustomNavLinkRegistry(const FObjectInitializer& ObjectInitializer);

};

