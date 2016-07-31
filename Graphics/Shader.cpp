#include "Shader.hpp"
#include <glm/gtc/type_ptr.hpp>

namespace GLUtility {
namespace Graphics {

    template <ShaderProgram::MatrixType MatType>
    const std::string ShaderProgram::MatType2String<MatType>::Value = "None";

    template <>
    struct ShaderProgram::MatType2String<ShaderProgram::MatrixType::Model> {
        static const std::string Value;
    };

    template <>
    struct ShaderProgram::MatType2String<ShaderProgram::MatrixType::View> {
        static const std::string Value;
    };

    template <>
    struct ShaderProgram::MatType2String<ShaderProgram::MatrixType::Projection> {
        static const std::string Value;
    };
    const std::string ShaderProgram::MatType2String<ShaderProgram::MatrixType::Model>::Value = "ModelMatrix";
    const std::string ShaderProgram::MatType2String<ShaderProgram::MatrixType::View>::Value = "ViewMatrix";
    const std::string ShaderProgram::MatType2String<ShaderProgram::MatrixType::Projection>::Value = "ProjectionMatrix";

    ShaderProgram::ShaderProgram()
    {
        _programe_id = glCreateProgram();
    }

    ShaderProgram::~ShaderProgram()
    {
        glDeleteProgram(_programe_id);
    }

    ShaderProgram::Self& ShaderProgram::Create()
    {
        glLinkProgram(_programe_id);
        glValidateProgram(_programe_id);

        std::for_each(_ids.begin(), _ids.end(), [](GLenum id) { glDeleteShader(id); });
        _ids.clear();
        return *this;
    }

    void ShaderProgram::Enable() const

    {
        glUseProgram(_programe_id);
    }

    void ShaderProgram::Disable() const
    {
        glUseProgram(0);
    }

    ShaderProgram::Self& ShaderProgram::SetUniformVar1i(const std::__1::string& name, const int& var)
    {
        glUniform1i(_GetUniformLocation(name), var);
        return *this;
    }

    ShaderProgram::Self& ShaderProgram::SetUniformVarArr1i(const std::__1::string& name, const std::vector<int>& vars)
    {
        glUniform1iv(_GetUniformLocation(name), static_cast<int>(vars.size()), vars.data());
        return *this;
    }

    ShaderProgram::Self& ShaderProgram::SetUniformVec2f(const std::__1::string& name, const glm::vec2& vec)

    {
        glUniform2f(_GetUniformLocation(name), vec.x, vec.y);
        return *this;
    }

    ShaderProgram::Self& ShaderProgram::SetUniformVec3f(const std::__1::string& name, const glm::vec3& vec)
    {
        glUniform3f(_GetUniformLocation(name), vec.x, vec.y, vec.z);
        return *this;
    }

    ShaderProgram::Self& ShaderProgram::SetUniformVec4f(const std::__1::string& name, const glm::vec4& vec)
    {
        glUniform4f(_GetUniformLocation(name), vec.x, vec.y, vec.z, vec.w);
        return *this;
    }

    ShaderProgram::Self& ShaderProgram::SetUniformMat4f(const std::__1::string& name, const glm::mat4& mat)
    {
        glUniformMatrix4fv(_GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(mat));
        return *this;
    }
}
}
