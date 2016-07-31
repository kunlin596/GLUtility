#ifndef BUFFEROBJECT_HPP
#define BUFFEROBJECT_HPP

#include <GL/glew.h>

namespace GLUtility {
namespace Graphics {

    class BufferObject {
    protected:
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        inline virtual GLuint GetID() { return _id; }
        virtual ~BufferObject() = 0;

        GLuint _id;
    };
}
}

#endif // BUFFEROBJECT_HPP
