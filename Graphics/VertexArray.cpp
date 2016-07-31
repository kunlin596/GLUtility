#include "VertexArray.hpp"

namespace GLUtility {
namespace Graphics {

    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &_id);
    }

    VertexArray::~VertexArray()
    {
        std::for_each(
            _buffer_ptrs.begin(),
            _buffer_ptrs.end(),
            [](VertexBuffer* buffer) { delete buffer; });
        _buffer_ptrs.clear();
        glDeleteVertexArrays(1, &_id);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(_id);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }
}
}
