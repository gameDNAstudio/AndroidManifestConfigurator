// Android Manifest Configurator
// Created by Patryk Stepniewski
// Copyright (c) 2014-2019 gameDNA Ltd. All Rights Reserved.

#include "IAndroidManifestConfigurator.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "AndroidManifestConfiguratorClasses.h"
#include "AndroidManifestConfiguratorSettings.h"
#include "ISettingsModule.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAndroidManifestConfigurator, Log, All);
DEFINE_LOG_CATEGORY(LogAndroidManifestConfigurator);

#define LOCTEXT_NAMESPACE "AndroidManifestConfigurator"

class FAndroidManifestConfigurator : public IAndroidManifestConfigurator
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FAndroidManifestConfigurator, AndroidManifestConfigurator)

// Startup Module
void FAndroidManifestConfigurator::StartupModule()
{
	// Register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "AndroidManifestConfigurator",
			LOCTEXT("RuntimeSettingsName", "Android Manifest Configurator"),
			LOCTEXT("RuntimeSettingsDescription", "Configure the Android Manifest Configurator plugin"),
			GetMutableDefault<UAndroidManifestConfiguratorSettings>()
			);
	}
}

// Shutdown Module
void FAndroidManifestConfigurator::ShutdownModule()
{
}


#undef LOCTEXT_NAMESPACE
