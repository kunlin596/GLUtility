#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "BufferObject.hpp"
#include "VertexBuffer.hpp"

namespace GLUtility {
namespace Graphics {

    enum class AttributeIndex : int {
        Position,
        UV,
        TID,
        Color
    };

    class VertexArray : public BufferObject {

        using Self = VertexArray;
        using VertexBufferPointers = std::vector<VertexBuffer*>;

    public:
        VertexArray();
        ~VertexArray();

        template <AttributeIndex Index>
        Self& AddVertexBuffer(VertexBuffer* buffer)
        {
            Bind();
            buffer->Bind();

            glEnableVertexAttribArray(static_cast<int>(Index));
            glVertexAttribPointer(static_cast<int>(Index), VertexByteSize, GL_FLOAT, GL_FALSE, 0, 0);

            buffer->Unbind();
            Unbind();

            _buffer_ptrs.emplace_back(buffer);

            return *this;
        }

        void Bind() const override;
        void Unbind() const override;

    private:
        VertexBufferPointers _buffer_ptrs;
    };
}
}
#endif // VERTEXARRAY_H
