// Copyright © All Rights Reserved to Daniel 'Numsgil' Grondin

#pragma once

#include "ModuleManager.h"

class FNoisePluginModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
