#pragma once
#include "Comphi/Events/Event.h"
#include "Comphi/Core/LayerStack.h"
#include "Comphi/UI/ImGui/ImGuiLayer.h"
#include "Comphi/API/SceneGraph/SceneGraph.h"

namespace Comphi{
	
	struct WindowProperties {
		std::string Title;
		uint Width;
		uint Height;
		bool VSync = true;
		EventCallback EventCallback;

		WindowProperties(const std::string& title = "[Comphi Engine]",
			uint width = 1920, uint height = 1080)
			: Title(title), Width(width), Height(height) {}
	};

	class IWindow
	{
	public:

		virtual ~IWindow() {};

		virtual void OnWindowResized(uint x, uint y) = 0;
		virtual void OnFramebufferResized(uint x, uint y) = 0;
		virtual void OnBeginUpdate(SceneGraphPtr& sceneGraph) = 0;
		virtual void OnUpdate() = 0;
		virtual void Shutdown() = 0;

		virtual uint GetWidth() const = 0;
		virtual uint GetHeight() const = 0;

		//Attributes
		virtual void SetEventCallback(const EventCallback& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;
		virtual void* GetGraphicsContext() const = 0;

		//Implement in Platform Specific File
		static Comphi::IWindow* Create(const WindowProperties& props = WindowProperties());
	};

}
