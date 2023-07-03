#pragma once

#include "Modules/ModuleInterface.h"
#include <Runtime/Core/Public/Templates/SharedPointer.h>
#include "Public/UnrealPerfGraphThread.h"

// -----------------------------------------------------------------------------

DECLARE_LOG_CATEGORY_EXTERN(LogUnrealPerfGraph, Log, All);

// -----------------------------------------------------------------------------

class UNREALPERFGRAPH_API FUnrealPerfGraphModule final : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedPtr<FUnrealPerfGraphThread> PerfGraphThread;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------