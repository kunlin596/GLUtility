#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "BufferObject.hpp"
#include "Vertex.hpp"

namespace GLUtility {
namespace Graphics {
    class VertexBuffer : public BufferObject {
        using Self = VertexBuffer;

    public:
        VertexBuffer();
        ~VertexBuffer();

        void Bind() const override;
        void Unbind() const override;

        Self& SetData(const Vertices& vertices);
        Self& UseAs(const GLenum& usage);

        inline size_t GetCount() const
        {
            return _vertices.size();
        }

    private:
        Vertices _vertices;
    };
}
}

#endif // VERTEXBUFFER_H
