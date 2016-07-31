#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <glm/glm.hpp>
#include <vector>

namespace GLUtility {
namespace Graphics {

    struct Vertex {
        glm::vec3 position;
        glm::vec2 uv;
        float tid;
        unsigned int color;
    };

    using Vertices = std::vector<Vertex>;

    const size_t VertexByteSize = sizeof(Vertex);
}
}

#endif // VERTEX_HPP
