#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <glm/glm.hpp>

namespace GLUtility {
namespace Math {
    class Transformation {
    public:
        Transformation();

        glm::mat4 _mat;
    };
}
}

#endif // TRANSFORMATION_H
