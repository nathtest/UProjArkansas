#include "OWRichTextBlockBase.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=ESlateVisibility -FallbackName=ESlateVisibility

UOWRichTextBlockBase::UOWRichTextBlockBase() {
    //this->Visibility = ESlateVisibility::Visible;
    this->AutoWrapText = true;
    this->bUseShadowOffset = true;
    this->bUseOutline = false;
    this->MaxFontScaling = 10;
    this->TextScalingType = ETextScalingType::EStandardFontScaling;
}

void UOWRichTextBlockBase::UseTextStyleShadowOffset(bool bShouldUse) {
}

void UOWRichTextBlockBase::UseTextStyleOutline(bool bShouldUse) {
}

void UOWRichTextBlockBase::SetWrapTextAt(float ShouldWrapTextAt) {
}

void UOWRichTextBlockBase::SetMarshallerColorOverride(EIndianaUIColorType IndianaColorType) {
}


