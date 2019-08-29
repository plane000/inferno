#ifndef INFERNO_ENGINE_RENDERENGINE_H_
#define INFERNO_ENGINE_RENDERENGINE_H_

#include "../common.hpp"
#include "../maths.hpp"

class Primative;
class Scene;
class Ray;

class RenderEngine {
public:
	RenderEngine();

	void SetScene(Scene* scene);
	glm::vec3 GetColour(Ray ray, int depth);

	void PostProcess(glm::vec3* src, glm::vec3* dst, int w, int h);

	RenderMode Mode = MODE_RENDER_PATHTRACE;

	int SPP = 0;

private:
	glm::vec3 GetNormalColour(glm::vec3 normal);

	Scene* m_scene = nullptr;
};

#endif
