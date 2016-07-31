#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include "BufferObject.hpp"
#include <vector>

namespace GLUtility {
namespace Graphics {

    class IndexBuffer : public BufferObject {

        using Self = IndexBuffer;

    public:
        using Indices = std::vector<GLuint>;

        IndexBuffer();
        ~IndexBuffer();

        Self& SetData(const Indices& indices);
        Self& UseAs(const GLenum& usage);

        void Bind() const override;
        void Unbind() const override;

    private:
        Indices _indices;
    };
}
}
#endif // INDEXBUFFER_H
