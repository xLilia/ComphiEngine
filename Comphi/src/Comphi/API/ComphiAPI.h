#pragma once

//API
#include "Comphi/Allocation/IObjectPool.h"

#include "Comphi/Renderer/IGraphicsContext.h"

#include "Comphi/Utils/Time.h"

#include "Comphi/API/SceneGraph/Scene.h"
#include "Comphi/API/SceneGraph/Entity.h"

#include "Comphi/API/Components/Camera.h"
#include "Comphi/API/Components/Transform.h"
#include "Comphi/API/Components/Renderer.h"

#include "Comphi/API/Rendering/MeshObject.h"
#include "Comphi/API/Rendering/ShaderBufferData.h"
#include "Comphi/API/Rendering/ShaderObject.h"
#include "Comphi/API/Rendering/TextureObject.h"
#include "Comphi/API/Rendering/Material.h"
#include "Comphi/API/Rendering/MaterialInstance.h"

namespace Comphi {

	class ComphiAPI
	{
	public:
		
		enum RenderingAPI {
			None,
			Vulkan
		};

		struct select {
			static void None() {
				COMPHILOG_CORE_ERROR("No rendering API Selected.");
				activeAPI = RenderingAPI::None;
			}
			static void Vulkan() {
				COMPHILOG_CORE_INFO("Vulkan rendering API Selected.");
				activeAPI = RenderingAPI::Vulkan;
			}
		};
		
		static inline RenderingAPI getActiveAPI() { return activeAPI; }

		struct SceneGraph {
			static ScenePtr Scene();
			static EntityPtr Entity(IObjectPool* pool = &objectPool);
		};

		struct Components {
			static CameraPtr Camera(CameraProperties CameraProperties, IObjectPool* pool = &objectPool);
			static TransformPtr Transform(IObjectPool* pool = &objectPool);
			static RendererPtr Renderer(MaterialInstance& material, MeshData& mesh, IObjectPool* pool = &objectPool);
			//TODO: new components
			//Light
			//Script
		};

		struct Rendering {
			//Material
			static MaterialPtr Material(GraphicsPipelineConfiguration config, IObjectPool* pool = &objectPool);
			static ShaderObjectPtr Shader(ShaderType shaderType, IFileRef& file, IObjectPool* pool = &objectPool);

			//Material Instance
			static MaterialInstancePtr MaterialInstance(MaterialPtr& parent, IObjectPool* pool = &objectPool);
			static TexturePtr Texture(IFileRef& fileref, IObjectPool* pool = &objectPool);
			template<typename T>
			static ShaderBufferDataPtr ShaderBufferData (const T& dataArray, const uint count, BufferUsage usage = BufferUsage::UniformBuffer, IObjectPool* pool = &objectPool);

			static VertexBufferDataPtr	VertexBufferData(const VertexArray& dataArray, IObjectPool* pool = &objectPool);
			static IndexBufferDataPtr	IndexBufferData(const IndexArray& dataArray, IObjectPool* pool = &objectPool);
			
			template<typename T>
			static UniformBufferDataPtr UniformBufferData(const T& dataArray, const uint count, IObjectPool* pool = &objectPool);


			//Renderer
			static MeshObjectPtr MeshObject(IFileRef& modelFile, MeshBuffers& meshBuffers, IObjectPool* pool = &objectPool);
			static MeshObjectPtr MeshObject(MeshData& data, MeshBuffers& meshBuffers, IObjectPool* pool = &objectPool);
			static MeshObjectPtr MeshObject(VertexArray& vertexData, IndexArray& indexData, MeshBuffers& meshBuffers, IObjectPool* pool = &objectPool);
		};


		struct Init {
			static IGraphicsContext* GraphicsContext(void* windowHandler);
		};

		static IObjectPool objectPool;
		static void cleanUpInstances();

	private:
		static inline RenderingAPI activeAPI = RenderingAPI::None;
		static inline std::shared_ptr<IGraphicsContext> currentGraphicsContext = nullptr;

	};

}
