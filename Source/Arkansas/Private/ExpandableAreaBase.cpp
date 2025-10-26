#include "ExpandableAreaBase.h"

UExpandableAreaBase::UExpandableAreaBase() {
    this->HeaderWidgetStyle = NULL;
    this->bCenterSweepHitTest = false;
    this->bIsExpanded = false;
    this->MaxHeight = 0.00f;
    this->HeaderContent = NULL;
    this->BodyContent = NULL;
}

void UExpandableAreaBase::SetIsExpanded_Animated(bool IsExpanded) {
}

void UExpandableAreaBase::SetIsExpanded(bool IsExpanded) {
}

bool UExpandableAreaBase::GetIsExpanded() const {
    return false;
}

void UExpandableAreaBase::GetSlotNames(TArray<FName>& SlotNames) const
{
}

UWidget* UExpandableAreaBase::GetContentForSlot(FName SlotName) const
{
    return nullptr;
}

void UExpandableAreaBase::SetContentForSlot(FName SlotName, UWidget* Content)
{
}


