#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace {
std::string read_file(const char* file_path)
{
    FILE* file = fopen(file_path, "rt");
    fseek(file, 0, SEEK_END);
    unsigned long length = ftell(file);
    char* data = new char[length + 1];
    memset(data, 0, length + 1);
    fseek(file, 0, SEEK_SET);
    fread(data, 1, length, file);
    fclose(file);

    std::string result(data);
    delete[] data;
    return result;
}
}

namespace GLUtility {
namespace Graphics {

    class ShaderProgram {
    private:
        using Self = ShaderProgram;

        template <GLenum ShaderType>
        class ShaderComponent {

            using Self = ShaderComponent;

        public:
            ShaderComponent()
                : _id(0)
            {
            }

            Self& CreateFromFile(const std::string& file_name)
            {
                _id = glCreateShader(ShaderType);
                auto src = read_file(file_name.c_str()).c_str();

                GLint result = 0;

                glShaderSource(_id, 1, &src, nullptr);
                glCompileShader(_id);
                glGetShaderiv(_id, GL_COMPILE_STATUS, &result);
                return *this;
            }

            GLuint GetID() const { return _id; }

        private:
            GLuint _id;
        };

    public:
        enum class MatrixType {
            Model,
            View,
            Projection
        };

        template <MatrixType MatType>
        struct MatType2String {
            static const std::string Value;
        };

        ShaderProgram();
        ~ShaderProgram();

        ShaderProgram(const ShaderProgram& other) = default;

        template <GLenum ShaderType>
        Self& AttachShader(const std::string& file_name)
        {
            auto shader = ShaderComponent<ShaderType>{};
            shader.CreateFromFile(file_name);
            _ids.emplace_back(shader.GetID());
            glAttachShader(_programe_id, shader.GetID());
            return *this;
        }
        Self& Create();

        void Enable() const;
        void Disable() const;

        Self& SetUniformVarArr1i(const std::string& name, const std::vector<int>& vars);
        Self& SetUniformVar1i(const std::string& name, const int& var);
        Self& SetUniformVec2f(const std::string& name, const glm::vec2& vec);
        Self& SetUniformVec3f(const std::string& name, const glm::vec3& vec);
        Self& SetUniformVec4f(const std::string& name, const glm::vec4& vec);
        Self& SetUniformMat4f(const std::string& name, const glm::mat4& mat);

        template <MatrixType MatType>
        Self& SetMatrix(const glm::mat4& mat)
        {
            SetUniformMat4f(MatType2String<MatType>::Value, mat);
            return *this;
        }

    private:
        GLuint _programe_id;
        std::vector<GLenum> _ids;

        inline GLint _GetUniformLocation(const std::string& name)
        {
            return glGetUniformLocation(_programe_id, name.c_str());
        }
    };
}
}
namespace {

void test_shader()
{
    using namespace GLUtility;
    using namespace Graphics;

    auto shader = ShaderProgram{}
                      .AttachShader<GL_VERTEX_SHADER>("path")
                      .AttachShader<GL_FRAGMENT_SHADER>("path")
                      .AttachShader<GL_GEOMETRY_SHADER>("path")
                      .Create()
                      .SetMatrix<ShaderProgram::MatrixType::Model>(glm::mat4());

    shader.Enable();
    shader.Disable();
}
}

#endif // SHADER_H
