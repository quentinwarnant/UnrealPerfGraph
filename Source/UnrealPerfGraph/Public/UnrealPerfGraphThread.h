#pragma once

#include "HAL/Runnable.h"
#include "Misc/SingleThreadRunnable.h"
#include "imgui.h"

class UNREALPERFGRAPH_API FUnrealPerfGraphThread : public FRunnable, FSingleThreadRunnable
{
public:  
  FUnrealPerfGraphThread();
  virtual ~FUnrealPerfGraphThread();

  void Wait(float Seconds);
  virtual FSingleThreadRunnable* GetSingleThreadInterface() override { return this; }
  virtual void Tick() override;

  virtual bool Init() override;
  virtual uint32 Run() override;
  virtual void Stop() override;
  virtual void Exit() override;

//   void SetPaused(bool MakePaused);
//   bool IsThreadPaused();
//   bool IsThreadVerifiedSuspended();
//   bool HasThreadStopped();

};