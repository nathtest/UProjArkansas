#pragma once
#include "CoreMinimal.h"
#include "MovieSceneNameableTrack.h"
#include "Compilation/IMovieSceneTrackTemplateProducer.h"
#include "MovieSceneCineActorTrack.generated.h"

class UMovieSceneSection;

UCLASS(Blueprintable)
class ARKANSAS_API UMovieSceneCineActorTrack : public UMovieSceneNameableTrack, public IMovieSceneTrackTemplateProducer {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMovieSceneSection*> Sections;
    
public:
    UMovieSceneCineActorTrack();

    virtual const TArray<UMovieSceneSection*>& GetAllSections() const override;
    virtual void RemoveAllAnimationData() override;
    virtual bool HasSection(const UMovieSceneSection& Section) const override;
    virtual void RemoveSection(UMovieSceneSection& Section) override;
    virtual bool IsEmpty() const override;

    virtual FMovieSceneEvalTemplatePtr CreateTemplateForSection(const UMovieSceneSection& InSection) const override;


    // Fix for true pure virtual functions not being implemented
};

