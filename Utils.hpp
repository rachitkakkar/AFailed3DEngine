#pragma once
#include "Projecter.hpp"
#include <iostream>

// Utils contains various utility functions that can be reused. Mostly used for logging and debugging.

namespace Croire {
    namespace Utils {
        // Log Vector
        void log_vector(glm::vec3 vector) {
            std::cout << "x: " << vector.x << " " << "y: " << vector.y << " " << "z: " << vector.z << std::endl;
        }

        // Log List Of Vectors
        void log_vectors(std::vector<glm::vec3> vectors) {
            for (auto vector : vectors) {
                log_vector(vector);
            } 
        }
    }
}