#include "shader.h"
#include <iostream>

namespace Engine::Graphics
{
    const std::optional<Uniform> Shader::getUniform(std::string name)
    {
        std::optional<Uniform> result;
        if (m_uniforms.count(name) > 0)
        {
            result = std::optional<Uniform>(m_uniforms[name]);
        }
        else
        {
            result = std::nullopt;
        }
        
        return result;
    }
}