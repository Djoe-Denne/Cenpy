#include <memory>
#include <gtest/gtest.h>
#include <graphic/shader/Program.hpp>
#include <graphic/Api.hpp>
#include <graphic/context/ProgramContext.hpp>
#include <graphic/context/PassContext.hpp>
#include <OpenGLComponentTests.hpp>

namespace api = cenpy::graphic::api;
namespace context = cenpy::graphic::context;
namespace shader = cenpy::graphic::shader;

class ProgramTest : public OpenGLComponentTest
{
protected:
    std::shared_ptr<shader::Pass<api::OpenGL>> pass1;
    std::shared_ptr<shader::Pass<api::OpenGL>> pass2;

    void SetUp() override
    {
        OpenGLComponentTest::SetUp();
        // Initialize Passes with valid shaders
        auto vertexShader = std::make_shared<shader::Shader<api::OpenGL>>("test-datas/shaders/vertex/good/minimal.vert", context::ShaderType::VERTEX);
        auto fragmentShader = std::make_shared<shader::Shader<api::OpenGL>>("test-datas/shaders/fragment/good/minimal.frag", context::ShaderType::FRAGMENT);
        pass1 = std::shared_ptr<shader::Pass<api::OpenGL>>(new shader::Pass<api::OpenGL>({vertexShader, fragmentShader}));
        pass2 = std::shared_ptr<shader::Pass<api::OpenGL>>(new shader::Pass<api::OpenGL>({vertexShader, fragmentShader}));
    }
};

TEST_F(ProgramTest, ProgramCreationTest)
{
    ASSERT_NO_THROW(shader::Program program({pass1, pass2}));
}

TEST_F(ProgramTest, UsePassTest)
{
    shader::Program program({pass1, pass2});

    // Test using the first pass
    ASSERT_NO_THROW(program.use(0));
    // Add checks if there are specific observable effects of using a pass

    // Test using the second pass
    ASSERT_NO_THROW(program.use(1));
    // Add checks for the second pass
}

TEST_F(ProgramTest, UseNextPassTest)
{
    shader::Program program({pass1, pass2});

    // Use the first pass and then the next
    ASSERT_TRUE(program.hasNext());
    ASSERT_TRUE(program.useNext());
    ASSERT_FALSE(program.useNext());
}

TEST_F(ProgramTest, ResetProgramTest)
{
    shader::Program program({pass1, pass2});

    program.use(0);
    ASSERT_NO_THROW(program.reset());
    // Add checks to ensure the program is reset to its initial state
}

TEST_F(ProgramTest, PassesCountTest)
{
    shader::Program program({pass1, pass2});

    ASSERT_EQ(program.getPassesCount(), 2);
}

// Additional tests can be added based on other functionalities of the Program class
