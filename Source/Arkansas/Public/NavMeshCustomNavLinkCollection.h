#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=NavLinkId -FallbackName=NavLinkId
#include "NavMeshCustomNavLinkCollection.generated.h"

class UCustomNavLinkBase;

UCLASS(Blueprintable)
class UNavMeshCustomNavLinkCollection : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UCustomNavLinkBase*> CustomNavLinkPtrs;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FNavLinkId, UCustomNavLinkBase*> CustomNavLinkMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNavLinksOuteredUnderCollection;
    
    UNavMeshCustomNavLinkCollection();

};

