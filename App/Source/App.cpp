#include <Code.h>
#include <iostream>

#include "CodePen/Events/KeyEvent.h"

class ExampleLayer : public CodePen::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate(float deltaTime) override
	{
	}

	bool OnEvent(CodePen::Event& event) override
	{
		return false;
	}
};

class SandboxApp : public CodePen::Application
{
public:
	SandboxApp()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new CodePen::uiLayer());
	}
	~SandboxApp()
	{
	}
};

CodePen::Application* CodePen::CreateApplication()
{
	return new SandboxApp();
}

int main()
{
	CodePen::Application* app = CodePen::CreateApplication();

	app->Run();

	delete app;
	return 0;
}
