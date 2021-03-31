#pragma once
#include <vector>
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Utils.hpp"

// This projector has functions that project 3D vectors in X and Y points on a 2D screen. Heavily Integrated With GLM.

namespace Croire {
    namespace Projector {
        // Projection Of Single Point
        glm::vec3 project_point(int width, int height, glm::vec3 position, glm::vec3 translation, glm::vec3 rotation_axis, float rotation_angle) {
            // Rotate and translate
            glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(rotation_angle), rotation_axis);
            model = glm::translate(model, translation);
            
            // Project
            glm::mat4 projection = glm::frustum(1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 100.0f);
            glm::vec4 viewport(0.0f, 0.0f, width, height);
            glm::vec3 projected = glm::project(position, model, projection, viewport);

            return projected;
        }

        // Projection Of A List Of Vectors
        std::vector<glm::vec3> project_vectors(int width, int height, std::vector<glm::vec3> points, glm::vec3 translation, glm::vec3 rotation_axis, float rotation_angle) {
            std::vector<glm::vec3> projected_points;

            for (auto position : points) {
                projected_points.push_back(project_point(width, height, position, translation, rotation_axis, rotation_angle));
            }

            return projected_points;
        }
    }
}