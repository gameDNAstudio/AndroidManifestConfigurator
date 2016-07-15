// Android Manifest Configurator
// Created by Patryk Stepniewski
// Copyright (c) 2014-2016 gameDNA studio. All Rights Reserved.

#include "AndroidManifestConfiguratorPrivatePCH.h"
#include "AndroidManifestConfiguratorSettings.h"

UAndroidManifestConfiguratorSettings::UAndroidManifestConfiguratorSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bSmallScreens(true)
	, bNormalScreens(true)
	, bLargeScreens(true)
	, bXLargeScreens(true)
	, bAnyDensity(true)
	, bReqFiveWayNav(false)
	, bReqHardKeyboard(false)
{
}
