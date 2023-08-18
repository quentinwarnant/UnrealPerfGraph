#include "UnrealPerfGraphModule.h"

#include <Runtime/Core/Public/Logging/LogMacros.h>
#include "Logging/MessageLog.h"

#include <Editor/UnrealEd/Public/Editor.h>
// -----------------------------------------------------------------------------

DEFINE_LOG_CATEGORY(LogUnrealPerfGraph)

// -----------------------------------------------------------------------------

IMPLEMENT_MODULE( FUnrealPerfGraphModule, UnrealPerfGraph )

// -----------------------------------------------------------------------------

void FUnrealPerfGraphModule::StartupModule()
{   
    if (!FPlatformProcess::SupportsMultithreading()) 
    {
        UE_LOG(LogUnrealPerfGraph, Warning, TEXT("Platform doesn't support Multithreading."));
    }
	
    /*PerfGraphThread = MakeShared<FUnrealPerfGraphThread>();
	FWorldDelegates::OnPostWorldCreation.AddRaw(this, &FUnrealPerfGraphModule::OnReadyToStartPerfGraphThread);*/

}

// -----------------------------------------------------------------------------

void FUnrealPerfGraphModule::ShutdownModule()
{
	UE_LOG(LogUnrealPerfGraph, Log, TEXT("Closing Unreal Perf Graph module."));
	//PerfGraphThread->Stop();
}

// -----------------------------------------------------------------------------

void FUnrealPerfGraphModule::OnReadyToStartPerfGraphThread(UWorld* World)
{
	//PerfGraphThread->SetWorld(World);
	//FRunnableThread::Create(PerfGraphThread.Get(), TEXT("PerfGraph Thread"), 128 * 1024);
}