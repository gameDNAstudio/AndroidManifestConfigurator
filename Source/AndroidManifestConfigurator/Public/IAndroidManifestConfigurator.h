// Android Manifest Configurator
// Created by Patryk Stepniewski
// Copyright (c) 2014-2019 gameDNA Ltd. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

class IAndroidManifestConfigurator : public IModuleInterface
{
public:
	static inline IAndroidManifestConfigurator& Get()
	{
		return FModuleManager::LoadModuleChecked< IAndroidManifestConfigurator >("AndroidManifestConfigurator");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("AndroidManifestConfigurator");
	}
};
