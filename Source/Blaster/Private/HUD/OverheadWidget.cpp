// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/OverheadWidget.h"

#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;
	switch (RemoteRole)
	{
	case ENetRole::ROLE_Authority:
		Role = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role = FString("AutonomousProxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		Role = FString("SimulatedProxy");
		break;
	case ENetRole::ROLE_None:
		Role = FString("None");
		break;
	default:;
	}
	FString RemoteRoleString = FString::Printf(TEXT("Remote Role %s:"), *Role);

	// SetDisplayText(RemoteRoleString);
}

void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);

	RemoveFromParent();
}
