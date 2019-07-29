#include "camera.hpp"

Camera::Camera(glm::vec3 point, glm::vec3 dir, float w, float h, float f) {
    point = point;
    direction = dir;
    w = w; h = h; focalLen = f;
}

void Camera::Update() {
    //     Vector3 x_c = c->position;
    // Vector3 u_c = c->direction;
    // double z_p = c->focalLength;
    // Vector3 v_up = vec3_make(0.0, -1.0, 0.0);
    // Vector3 c_0 = vec3_add(x_c, vec3_mult(u_c, z_p));
    // Vector3 u_x = vec3_unit(vec3_cross(u_c, v_up));
    // Vector3 u_y = vec3_cross(vec3_mult(u_c, -1.0), u_x);
    // c->planeCenter = c_0;
    // c->planeDirectionX = u_x;
    // c->planeDirectionY = u_y;
    // //    Vector3 u_z = vec3_mult(u_c, -1.0); // Normal to the view plane
}
