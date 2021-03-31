#pragma once
#include "Projecter.hpp"

namespace Croire {
    namespace Clipper {
        bool behind_screen(glm::vec3 projected_point) {
            if (projected_point.z < 0.0f) {
                return true;
            }
            
            return false;
        }
    }
}