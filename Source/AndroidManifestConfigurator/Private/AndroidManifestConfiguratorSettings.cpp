// Android Manifest Configurator
// Created by Patryk Stepniewski
// Copyright (c) 2014-2019 gameDNA Ltd. All Rights Reserved.

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
