// UniformContext.hpp

#pragma once

#include <gmock/gmock.h>
#include <graphic/MockApi.hpp>
#include <graphic/context/UniformContext.hpp>

namespace cenpy::mock::graphic
{
    namespace shader::opengl::component::uniform
    {
        template <typename T>
        struct mockSetter;
    }

    namespace opengl::context
    {
        class MockUniformContext : public cenpy::graphic::context::UniformContext
        {
        public:
            template <typename T>
            using Setter = shader::opengl::component::uniform::mockSetter<T>;

            MOCK_METHOD(void, setUniformID, (GLuint uniformId), ());
            MOCK_METHOD(GLuint, getUniformID, (), (const));
            MOCK_METHOD(void, setGLType, (GLenum type), ());
            MOCK_METHOD(GLenum, getGLType, (), (const));
            MOCK_METHOD(void, setSize, (GLuint size), ());
            MOCK_METHOD(GLuint, getGLSize, (), (const));
        };
    }
}