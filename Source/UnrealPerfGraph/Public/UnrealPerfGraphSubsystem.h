#pragma once

#include <Runtime/Engine/Public/Subsystems/EngineSubsystem.h>

#include <Runtime/Core/Public/Containers/CircularQueue.h>

#include "UnrealPerfGraphSubsystem.generated.h"

UCLASS()
class UUnrealPerfGraphSubsystem : public UEngineSubsystem, public FTickableGameObject
{
	GENERATED_BODY()
public:
	UUnrealPerfGraphSubsystem();

	//UEngineSubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;
	// - UEngineSubsystem

	// FTickableGameObject
	virtual void Tick(float DeltaTime) override;

	virtual bool IsTickableInEditor() const override
	{
		return true;
	}


	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(UUnrealPerfGraphSubsystem, STATGROUP_Tickables);
	}
	// - FTickableGameObject

private:
	float TestStatFloat;
	bool MyTestToolIsOpen = false;
	float CurrentFrameTimeStamp;

	TArray<float> FrametimeQueue;
	TArray<float> FrameTimeStampQueue;



	//ImGui
	struct ImGuiContext* ImGuiContext;
};