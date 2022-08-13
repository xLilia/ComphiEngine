#include "cphipch.h"
#include "GraphicsAPI.h"

namespace Comphi {
    
    IShaderPipeline* GraphicsAPI::create::ShaderPipeline()
    {
        switch (activeAPI)
        {
        case RenderingAPI::OpenGL:
            return new OpenGL::ShaderPipeline();
        case RenderingAPI::Vulkan: 
        {
            Vulkan::ShaderPipeline::GraphicsPipelineSetupData data {};
            data.viewport = {};
            data.scissor = {};
            return new Vulkan::ShaderPipeline(data);
            break;
        }
        default:
            COMPHILOG_CORE_FATAL("No rendering API Selected!");
            break;
        }
        return nullptr;
    }

    IVertexBuffer* GraphicsAPI::create::VertexBuffer(const float& vertices, const uint& count)
    {
        switch (activeAPI)
        {
        case RenderingAPI::OpenGL:
            return new OpenGL::VertexBuffer(vertices, count);
        case RenderingAPI::Vulkan:
            return new Vulkan::VertexBuffer(vertices, count);
            break;
        default:
            COMPHILOG_CORE_FATAL("No rendering API Selected!");
            break;
        }
        return nullptr;
    }

    IIndexBuffer* GraphicsAPI::create::IndexBuffer(const uint& indices)
    {
        switch (activeAPI)
        {
        case RenderingAPI::OpenGL:
            return new OpenGL::IndexBuffer(indices);
        case RenderingAPI::Vulkan:
            return new Vulkan::IndexBuffer(indices);
            break;
        default:
            COMPHILOG_CORE_FATAL("No rendering API Selected!");
            break;
        }
        return nullptr;
    }

    IShaderProgram* GraphicsAPI::create::ShaderProgram(IGraphicsContext* currentGraphicsContext, Comphi::ShaderType shaderType, IFileRef& shaderFile)
    {
        switch (activeAPI)
        {
        case RenderingAPI::OpenGL:
            return new OpenGL::ShaderProgram(shaderType,shaderFile);
        case RenderingAPI::Vulkan:
        {
            auto graphicsContext = static_cast<Vulkan::GraphicsContext*>(currentGraphicsContext);
            return new Vulkan::ShaderProgram(shaderType, shaderFile, graphicsContext->logicalDevice);
            break;
        }
        default:
            COMPHILOG_CORE_FATAL("No rendering API Selected!");
            break;
        }
        return nullptr;
    }

    IGraphicsContext* GraphicsAPI::create::GraphicsContext(GLFWwindow& windowHandler)
    {
        switch (activeAPI)
        {
        case RenderingAPI::OpenGL:
            return new OpenGL::GraphicsContext(windowHandler);
        case RenderingAPI::Vulkan:
            return new Vulkan::GraphicsContext(windowHandler);
        default:
            COMPHILOG_CORE_FATAL("No rendering API Selected!");
            break;
        }
        return nullptr;
    }

}
