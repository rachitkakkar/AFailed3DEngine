#include "Croire.hpp"

// Defines
#define WIDTH 500
#define HEIGHT 500

int main()
{
    std::vector<glm::vec3> points = {
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.8f, 0.8f, 1.0f),
        glm::vec3(0.0f, 0.8f, 1.0f)
    };

    glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 rotation_axis = glm::vec3(0.0f, 1.0f, 0.0f);
    float rotation_angle = 0.0f;

    std::vector<glm::vec3> projected_points;

    Croire::Renderer::create_window(500, 500, "Test");
    while (Croire::Renderer::is_open()) {
        Croire::Renderer::clear(0, 0, 0);

        projected_points = Croire::Projector::project_vectors(WIDTH, HEIGHT, points, translation, rotation_axis, rotation_angle);
        rotation_angle += 0.1f;
        Croire::Renderer::draw_triangle(projected_points, 0, 255, 0);
        Croire::Renderer::update();
    }
}