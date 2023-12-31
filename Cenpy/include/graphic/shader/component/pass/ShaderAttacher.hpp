#pragma once

#include <memory>
#include <graphic/Api.hpp>

namespace cenpy::graphic::shader
{
    namespace component::pass
    {
        /**
         * @interface IShaderAttacher
         * @brief Interface for attaching shaders in a shader pass.
         *
         * This interface defines a single method for attaching shaders to a shader pass.
         * It is intended to be implemented by graphics API-specific classes.
         */
        template <typename API>
        class IShaderAttacher
        {
        public:
            virtual ~IShaderAttacher() = default;

            /**
             * @brief Attach shaders to the pass.
             * @param context PassContext containing pass details.
             *
             * This method is responsible for attaching all the shaders that are part of the pass
             * context to the shader program. The method should handle any API-specific details
             * involved in attaching shaders.
             */
            virtual void attachShaders(std::shared_ptr<typename API::PassContext> context) = 0;
        };
    }

    namespace opengl::component::pass
    {
        /**
         * @class OpenGLPassAttacher
         * @brief OpenGL implementation of IShaderAttacher.
         *
         * This class implements the shader attaching process for an OpenGL shader pass.
         * It attaches all shaders within the given PassContext to an OpenGL program.
         */
        class OpenGLShaderAttacher : public graphic::shader::component::pass::IShaderAttacher<graphic::api::OpenGL>
        {
        public:
            /**
             * @brief Attach shaders to the pass in OpenGL context.
             * @param context PassContext containing pass details specific to OpenGL.
             *
             * This implementation casts the generic PassContext to an OpenGLPassContext,
             * and attaches each shader to the OpenGL program. If the context casting fails
             * or if any shader context is invalid, an exception is thrown.
             */
            void attachShaders(std::shared_ptr<typename graphic::api::OpenGL::PassContext> openglContext) override;
        };
    }
}
