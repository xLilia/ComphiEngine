#pragma once
#include "Comphi/Renderer/Vulkan/GraphicsHandler.h"
#include "Comphi/Renderer/ICamera.h"

namespace Comphi::Vulkan {

	class Camera : public ICamera
	{
	public:
		// Inherited via ICamera
		virtual glm::mat4 getProjectionMatrix() override;

		// Inherited via ICamera
		virtual void cleanUp() override {};

	};

}