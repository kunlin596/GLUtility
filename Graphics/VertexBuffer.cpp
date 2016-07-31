#include "VertexBuffer.hpp"
namespace GLUtility {
namespace Graphics {
    VertexBuffer::VertexBuffer()
    {
        glGenBuffers(1, &_id);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &_id);
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, _id);
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    VertexBuffer::Self& VertexBuffer::SetData(const Vertices& vertices)
    {
        _vertices = vertices;

        return *this;
    }

    VertexBuffer::Self& VertexBuffer::UseAs(const GLenum& usage)
    {
        glBindBuffer(1, _id);
        glBufferData(GL_ARRAY_BUFFER, static_cast<long>(_vertices.size()), _vertices.data(), usage);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        return *this;
    }
}
}
