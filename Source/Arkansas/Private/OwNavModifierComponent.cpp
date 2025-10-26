#include "OwNavModifierComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=NavigationSystem -ObjectName=NavArea_Null -FallbackName=NavArea_Null
#include "NavAreas/NavArea_Null.h"

UOwNavModifierComponent::UOwNavModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bStartEnabled = true;
    this->AreaClass = UNavArea_Null::StaticClass();
    this->bPhysicsCollisionOnly = false;
    this->CollisionComponent = NULL;
    this->bIncludeAgentHeight = false;
    this->Extents = 0.00f;
    this->bUseComplexGeomAsNavEdges = false;
    this->bUseComponentBounds = false;
    this->bCustomCollisionOnly = false;
    this->bShouldSkipDirtyAreaOnAddOrRemove = false;
}

void UOwNavModifierComponent::SetModifierEnabled(bool bInEnabled) {
}

bool UOwNavModifierComponent::IsModifierEnabled() const {
    return false;
}


