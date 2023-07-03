#include "UnrealPerfGraphThread.h"

FUnrealPerfGraphThread::FUnrealPerfGraphThread()
{
}

FUnrealPerfGraphThread::~FUnrealPerfGraphThread()
{
}

void FUnrealPerfGraphThread::Wait(float Seconds)
{
  FPlatformProcess::Sleep(Seconds);
}

void FUnrealPerfGraphThread::Tick()
{
}

bool FUnrealPerfGraphThread::Init()
{
  return true;
}


uint32 FUnrealPerfGraphThread::Run()
{
  return 0;
}

void FUnrealPerfGraphThread::Stop()
{
//   SetPaused(true);
//   bStopping = true;
}

void FUnrealPerfGraphThread::Exit()
{
}
