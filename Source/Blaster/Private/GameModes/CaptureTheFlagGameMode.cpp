// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/CaptureTheFlagGameMode.h"
#include "Weapon/Flag.h"
#include "CaptureTheFlag/FlagZone.h"
#include "GameState/BlasterGameState.h"

void ACaptureTheFlagGameMode::PlayerEliminated(class ABlasterCharacter* ElimmedCharacter, class ABlasterPlayerController* ElimmedController, ABlasterPlayerController* AttackerController)
{
	ABlasterGameMode::PlayerEliminated(ElimmedCharacter, ElimmedController, AttackerController);
}

void ACaptureTheFlagGameMode::FlagCaptured(AFlag* Flag, AFlagZone* Zone)
{
	bool bValidCapture = Flag->GetTeam() != Zone->Team;
	ABlasterGameState* BGameState = Cast<ABlasterGameState>(GameState);
	if (BGameState)
	{
		if (Zone->Team == ETeam::ET_BlueTeam)
		{
			BGameState->BlueTeamScores();
		}
		if (Zone->Team == ETeam::ET_RedTeam)
		{
			BGameState->RedTeamScores();
		}
	}
}
