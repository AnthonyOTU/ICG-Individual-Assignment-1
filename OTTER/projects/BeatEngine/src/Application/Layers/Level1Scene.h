#pragma once
#include "Application/ApplicationLayer.h"
#include "json.hpp"

/**
 * This example layer handles creating a default test scene, which we will use
 * as an entry point for creating a sample scene
 */
class Level1Scene final : public ApplicationLayer {
public:
	MAKE_PTRS(Level1Scene)

	Level1Scene();
	virtual ~Level1Scene();

	// Inherited from ApplicationLayer

	virtual void OnAppLoad(const nlohmann::json& config) override;

protected:
	void _CreateScene();
};