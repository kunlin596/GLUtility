#include "IndexBuffer.hpp"
namespace GLUtility {
namespace Graphics {

    IndexBuffer::IndexBuffer()
    {
        glGenBuffers(1, &_id);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &_id);
    }

    IndexBuffer::Self& IndexBuffer::SetData(const Indices& indices)
    {
        _indices = indices;
        return *this;
    }

    IndexBuffer::Self& IndexBuffer::UseAs(const GLenum& usage)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<long>(_indices.size() * sizeof(Indices::value_type)), &_indices, usage);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        return *this;
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
    }

    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}
}
