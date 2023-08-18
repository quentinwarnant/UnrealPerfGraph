#include "UnrealPerfGraphSubsystem.h"

//#include "imgui.h"
#include <imgui.h>
#include <implot.h>

#define UPG_ENABLED 0

UUnrealPerfGraphSubsystem::UUnrealPerfGraphSubsystem()
	: TestStatFloat(3.14f)
	, MyTestToolIsOpen(false)
	, CurrentFrameTimeStamp(0.0f)
	, FrametimeQueue()
	, FrameTimeStampQueue()
{
}


void UUnrealPerfGraphSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

}

void UUnrealPerfGraphSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UUnrealPerfGraphSubsystem::Tick(float DeltaTime)
{

#if UPG_ENABLED
	const FString Label = TEXT("blablabla");

	ImGui::Begin(TCHAR_TO_ANSI(*Label), nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::SliderFloat("Scale", &TestStatFloat, 0.1f, 5.0f);
	ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);

	FrametimeQueue.Emplace(ImGui::GetIO().Framerate);
	CurrentFrameTimeStamp += DeltaTime;
	FrametimeQueue.Emplace(CurrentFrameTimeStamp);


	if (ImPlot::BeginPlot("My Plot")) {
		ImPlot::PlotBars("My Bar Plot", FrametimeQueue.GetData(), FrametimeQueue.Num());
		ImPlot::PlotLine("My Line Plot", FrameTimeStampQueue.GetData(), FrametimeQueue.GetData(), FrameTimeStampQueue.Num());
		ImPlot::EndPlot();
	}
	ImGui::End();


#endif
}
