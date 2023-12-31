#pragma once

#include <gmock/gmock.h>
#include <graphic/MockApi.hpp>
#include <graphic/context/MockShaderContext.hpp>
#include <graphic/shader/Shader.hpp>

namespace cenpy::mock::graphic::shader
{
    namespace api = cenpy::mock::graphic::api;
    namespace context = cenpy::graphic::context;
    namespace shader = cenpy::graphic::shader;

    class MockShader : public shader::Shader<api::MockOpenGL>
    {
    public:
        MockShader()
            : shader::Shader<api::MockOpenGL>("", context::ShaderType::VERTEX)
        {
        }
        MockShader(const std::string &shaderPath, const context::ShaderType &shaderType)
            : shader::Shader<api::MockOpenGL>(shaderPath, shaderType)
        {
        }

        MOCK_METHOD(void, free, (), (override));
        MOCK_METHOD(void, load, (), (override));
        MOCK_METHOD(const std::shared_ptr<typename api::MockOpenGL::ShaderContext> &, getContext, (), (const, override));
    };

}
