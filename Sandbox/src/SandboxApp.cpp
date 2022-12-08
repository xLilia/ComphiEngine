#include <Comphi.h>
#include <imgui.h>

using namespace Comphi;

class GameSceneLayer : public Comphi::Layer
{
public:

	//TODO: Comphi namepsace objects should use platform & renderer independent interfaces (API)

	Windows::FileRef textureFile;
	TextureInstance texture;

	Windows::FileRef vert;
	ShaderInstance vertShader;

	Windows::FileRef frag;
	ShaderInstance fragShader;

	MaterialInstance Albedo;

	Windows::FileRef modelMesh;
	MeshInstance meshObj;

	GameObjectInstance gameObj;

	CameraInstance camObj;

	SceneInstance scene;

	GameSceneLayer() : Layer("GameSceneLayer") { 

		//Texture
		/*MaterialProperties materialProperties;
		textureFile = Windows::FileRef("textures/viking_room.png");
		texture = GraphicsAPI::create::Texture(textureFile);

		//Shaders
		ShaderTextures textures = { texture.get() };
		materialProperties.shaderTextures = textures;

		vert = Windows::FileRef("shaders/vert.spv");
		frag = Windows::FileRef("shaders/frag.spv");
		vertShader = GraphicsAPI::create::ShaderProgram(ShaderType::VertexShader, vert);
		fragShader = GraphicsAPI::create::ShaderProgram(ShaderType::FragmentShader, frag);

		ShaderPrograms shaders = { &*vertShader , &*fragShader };
		materialProperties.shaderPrograms = shaders;

		//Material
		Albedo = GraphicsAPI::create::Material(materialProperties);

		//Mesh
		const VertexArray vertices = {
			{{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
			{{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
			{{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
			{{-0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},

			{{-0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
			{{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
			{{0.5f, 0.5f, -0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
			{{-0.5f, 0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
		};

		const IndexArray indices = {
			0, 1, 2, 2, 3, 0,
			4, 5, 6, 6, 7, 4
		};

		VertexArray cubeVx = {
			{{ 0.5f, 0.5f, 0.5f} , {1.0f, 1.0f, 1.0f} , {1.0f, 0.0f}},
			{{-0.5f, 0.5f, 0.5f} , {1.0f, 1.0f, 0.0f} , {0.0f, 0.0f}},
			{{-0.5f,-0.5f, 0.5f} , {1.0f, 0.0f, 0.0f} , {0.0f, 1.0f}},
			{{ 0.5f,-0.5f, 0.5f} , {1.0f, 0.0f, 1.0f} , {1.0f, 1.0f}},
			{{ 0.5f,-0.5f,-0.5f} , {0.0f, 0.0f, 1.0f} , {1.0f, 0.0f}},
			{{ 0.5f, 0.5f,-0.5f} , {0.0f, 1.0f, 1.0f} , {0.0f, 0.0f}},
			{{-0.5f, 0.5f,-0.5f} , {0.0f, 1.0f, 0.0f} , {0.0f, 1.0f}},
			{{-0.5f,-0.5f,-0.5f} , {0.0f, 0.0f, 0.0f} , {1.0f, 1.0f}}
		};

		IndexArray CubeIx = {
			0, 1, 2,   2, 3, 0,   // v0-v1-v2, v2-v3-v0 (front)
			0, 3, 4,   4, 5, 0,   // v0-v3-v4, v4-v5-v0 (right)
			0, 5, 6,   6, 1, 0,   // v0-v5-v6, v6-v1-v0 (top)
			1, 6, 7,   7, 2, 1,   // v1-v6-v7, v7-v2-v1 (left)
			7, 4, 3,   3, 2, 7,   // v7-v4-v3, v3-v2-v7 (bottom)
			4, 7, 6,   6, 5, 4    // v4-v7-v6, v6-v5-v4 (back)
		};

		modelMesh = Windows::FileRef("models/viking_room.obj");
		meshObj = GraphicsAPI::create::Mesh(modelMesh, Albedo);
		MeshData mesh{ meshObj };

		//GameObject
		gameObj = GraphicsAPI::create::GameObject(mesh);
		//gameObj1->action.updateCallback = [this](Time frameTime,void*) { //TODO: fix Lambda not defined when out of scope
		//	gameObj1->transform.position = glm::vec3(0, 0, glm::sin(frameTime.deltaTime()));
		//	gameObj1->transform.setEulerAngles(glm::vec3(0.0f, 0.0f, 45.0f) * frameTime.deltaTime());
		//};

		//Camera
		camObj = GraphicsAPI::create::Camera();
		camObj->transform.position = glm::vec3(0.0f, 4.0f, 0.0f);
		camObj->transform.lookAt(gameObj->transform.position);

		//camObj1->action.updateCallback = [this](Time frameTime,void*) {
		//	camObj1->transform.lookAt(gameObj1->transform.position);
		//};

		scene = GraphicsAPI::create::Scene();
		scene->sceneObjects.push_back(gameObj);
		scene->sceneCamera = (camObj);*/
	
	}; 

	
	void OnStart() override {}

	void OnEnd() override {};

	void OnUpdate() override {};

	void OnUIRender() override {};

	void OnEvent(Comphi::Event& e) override 
	{
		//Called once per event 
	};

private:
};

class Sandbox : public Comphi::Application
{
public:
	Sandbox() {
		GameSceneLayer* Renderlayer = new GameSceneLayer();
		PushLayer(*Renderlayer);
		PushScene(Renderlayer->scene);
	}
private:
};

Comphi::Application* Comphi::CreateApplication() {
	return new Sandbox();
}