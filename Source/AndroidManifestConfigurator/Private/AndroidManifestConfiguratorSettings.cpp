// Android Manifest Configurator
// Created by Patryk Stepniewski
// Copyright (c) 2014-2017 gameDNA. All Rights Reserved.

#include "AndroidManifestConfiguratorSettings.h"

UAndroidManifestConfiguratorSettings::UAndroidManifestConfiguratorSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bSmallScreens(true)
	, bNormalScreens(true)
	, bLargeScreens(true)
	, bXLargeScreens(true)
	, bAnyDensity(true)
	, bReqFiveWayNav(false)
	, bReqHardKeyboard(true)
{
}
