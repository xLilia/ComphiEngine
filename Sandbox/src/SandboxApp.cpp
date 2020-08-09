#include <Comphi.h>

class TestLayer : public Comphi::Layer
{
public:
	TestLayer() : Layer("Test") {};

	void OnUpdate() override 
	{
		//COMPHI_TRACE("UPDATE");
	};
	void OnEvent(Comphi::Event& e) override 
	{
		COMPHI_TRACE("{0}", e);
	};

private:

};

class Sandbox : public Comphi::Application
{
public:
	Sandbox(){
		PushLayer(new TestLayer());
		PushOverlay(new Comphi::ImGuiLayer());
	}

	~Sandbox(){}

private:

};

Comphi::Application* Comphi::CreateApplication() {
	return new Sandbox();
}