#include "cphipch.h"
#include "GraphicsContext.h"
#include "GLError.h"

#include "Comphi/Renderer/GraphicsAPI.h"
#include "Comphi/Platform/Windows/FileRef.h"

namespace Comphi::OpenGL {

	GraphicsContext::GraphicsContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{
		COMPHILOG_CORE_ASSERT(m_WindowHandle, "Window Handle is NULL!");
	}




	void GraphicsContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		COMPHILOG_CORE_ASSERT(status, "Could not initialize Glad!");

		COMPHILOG_CORE_INFO("OpenGL Info:");
		COMPHILOG_CORE_INFO("	OpenGL Vendor: {0}", glGetString(GL_VENDOR));
		COMPHILOG_CORE_INFO("	OpenGL Renderer: {0}", glGetString(GL_RENDERER));
		COMPHILOG_CORE_INFO("	OpenGL Version: {0}", glGetString(GL_VERSION));

		COMPHILOG_CORE_INFO("OpenGLContext Initialized.");

		GraphicsAPI::selectOpenGL();
		
		/***DEBUG***/

		check_gl_error_on();
		Windows::FileRef* vert = new Windows::FileRef("C:\\ComphiEngine\\bin\\Debug-windows-x86_64\\Sandbox\\vert.glsl");
		Windows::FileRef* frag = new Windows::FileRef("C:\\ComphiEngine\\bin\\Debug-windows-x86_64\\Sandbox\\frag.glsl");

		vertexShader.reset(GraphicsAPI::create::ShaderProgram(Comphi::ShaderType::VertexShader,vert));
		fragmentShader.reset(GraphicsAPI::create::ShaderProgram(Comphi::ShaderType::FragmentShader,frag));
		
		float vertices[3 * 3]{
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f
		};
		
		uint indexes[3] = { 0,1,2 };

		vbo.reset(GraphicsAPI::create::VertexBuffer(vertices,3));
		ibo.reset(GraphicsAPI::create::IndexBuffer(indexes));
		shaderPipe.reset(GraphicsAPI::create::ShaderPipeline());

		/***DEBUG***/
	}

	void GraphicsContext::Draw()
	{
		check_gl_error();

		glClearColor(0.3f, 0.6f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderPipe->InitPipeline();

		vbo->bind();
		shaderPipe->BindProgram(*vertexShader);
		shaderPipe->BindProgram(*fragmentShader);

		shaderPipe->BindPipeline();

		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

		check_gl_error();
	}

	void GraphicsContext::ResizeWindow(uint x, uint y)
	{
		glViewport(0, 0, x, y);
	}

	void GraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}