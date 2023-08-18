#include "UnrealPerfGraphThread.h"

#include <Runtime/Engine/Classes/Engine/GameViewportClient.h>

FUnrealPerfGraphThread::FUnrealPerfGraphThread()
{
}

FUnrealPerfGraphThread::~FUnrealPerfGraphThread()
{
}

//void FUnrealPerfGraphThread::Wait(float Seconds)
//{
//  FPlatformProcess::Sleep(Seconds);
//}

void FUnrealPerfGraphThread::Tick(float DeltaTime)
{
	bool Test = true;
	float Val = 0.0f;
	if (Test)
	{
		Val += 5.3f;
	}

}

void FUnrealPerfGraphThread::SetWorld(UWorld* InWorld)
{
	World = InWorld;
}



bool FUnrealPerfGraphThread::Init()
{
	if (World)
	{

		OnGameViewportTickDelegate = World->GetGameViewport()->OnTick().AddRaw(this, &FUnrealPerfGraphThread::Tick);
		return true;
	}

	return false;
}


uint32 FUnrealPerfGraphThread::Run()
{
	
  return 0;
}

void FUnrealPerfGraphThread::Stop()
{
	OnGameViewportTickDelegate.Reset();
//   SetPaused(true);
//   bStopping = true;
}

void FUnrealPerfGraphThread::Exit()
{
}
