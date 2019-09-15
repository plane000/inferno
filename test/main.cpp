#include <iostream>

#include "../src/inferno.hpp"

static const int width = 1000;
static const int height = 1000;

int main(int argc, char** argv) {
	InfernoEngine inferno;

	inferno.SetMode(MODE_OPERATION_PROGRESSIVE_GUI);

	bool status = inferno.InitWindow(width, height);

	if (!status) {
		std::cout << "Error initializing window: " << inferno.LastError() << std::endl;
	}

	Scene* scene = new Scene(width, height);

	Sky* sky = new GradientSky({ 35.0f / 255.0f, 148.0f / 255.0f, 235.0f / 255.0f }, { 1.0f, 1.0f, 1.0f }, 5.0f);
	scene->sky = sky;

    scene->camera = new Camera(width, height);
	
	//Sphere sphere1({ 1.3f, -0.8f, -5.0f }, 0.2f, new Material({ 0.817f, 0.374, 0.574 }));
	//scene->objects.push_back(&sphere1);

	//Sphere sphere({ 0.0f, 0.0f, -5.0f }, 1.0f, new Material({ 0.817f, 0.374, 0.574 }));
	// sphere.material->NormalTexture = new Texture("E:/Projects/Inferno/resources/textures/dirt-normal.jpg");
	// sphere.material->NormalTexture = new Texture("/home/ben/programming/inferno/resources/textures/dirt-normal.jpg");
	//scene->objects.push_back(&sphere);

	//Sphere light({ 35.0f, 50.0f, 25.0f }, 25.0f, new Material({ 1.0f, 1.0f, 1.0f }, 0.0f, 200.0f));
	//scene->objects.push_back(&light);

	//Plane plane({ 0.0f,-1.0f, 0.0f }, { 0.0f, -1.0f, 0.0f }, new Material({ 0.2f, 0.2f, 0.2f }));
	// plane.material->NormalTexture = new Texture("E:/Projects/Inferno/resources/textures/normals.png");
	// plane.material->NormalTexture = new Texture("/home/ben/programming/inferno/resources/textures/normals.png");
	//scene->objects.push_back(&plane);

	scene->objects.push_back(new Sphere({ 35.0f, 26.0f, 25.0f }, 15.0f, new Material({ 1.0f, 1.0f, 1.0f }, 0.0f, 50.0f)));
	scene->objects.push_back(new Sphere({-0.457001f, 0.19f, -3.53899f}, 0.02f,  new Material({ 1.0f, 0.9f, 0.8f }, 0.0f, 5000.0f)));
	scene->objects.push_back(new Plane( { 0.0f, -1.0f, 0.0f }, { 0.0f, -1.0f, 0.0f }, new Material({ 0.847f, 0.792f, 0.658f }, 0.2f)));

	//std::vector<Triangle*> tris = LoadTrianglesBasic("//home//ben//programming//inferno//resources//dragon-normals.obj", "//home//ben//programming//inferno//resources//resources");
	std::vector<Triangle*> tris = LoadTrianglesBasic("E://Projects//Inferno//resources//models//dragon-normals.obj", "E://Projects//Inferno//resources//models");

    Mesh* mesh = new Mesh(tris);
	mesh->Translate({ 0.2f, -1.04, -3.8f });
	//mesh->Translate({ 0.0f, -1.0, -4.0f });
    mesh->Optimise();
    scene->meshs.push_back(mesh);
	inferno.SetScene(scene);

    inferno.Ready();
    inferno.Render();

	return 0;
}
