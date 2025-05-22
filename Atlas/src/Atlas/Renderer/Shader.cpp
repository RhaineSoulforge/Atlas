#include "atpch.h"
#include "Shader.h"

#include <glad/glad.h>

namespace Atlas
{
    CShader::CShader(const std::string &vertexSrc, const std::string &fragmentSrc)
    {
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *source = vertexSrc.c_str();
        glShaderSource(vertexShader,1,&source,0);

        glCompileShader(vertexShader);

        GLint isCompiled = 0;
        glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&isCompiled);
        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(vertexShader,GL_INFO_LOG_LENGTH,&maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(vertexShader,maxLength,&maxLength,infoLog.data());

            glDeleteShader(vertexShader);

            AT_LOG_ERROR("{s}",infoLog.data())
            AT_ASSERT(true,"Vertex shader compilation failed!!")
            return;
        }

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        source = fragmentSrc.c_str();
        glShaderSource(fragmentShader,1,&source,0);

        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&isCompiled);
        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(fragmentShader,GL_INFO_LOG_LENGTH,&maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(fragmentShader,maxLength,&maxLength,infoLog.data());

            glDeleteShader(fragmentShader);

            AT_LOG_ERROR("{s}",infoLog.data())
            AT_ASSERT(true,"Fragment shader compilation failed!!!")
            return;
        }

        m_RendererID = glCreateProgram();

        glAttachShader(m_RendererID,vertexShader);
        glAttachShader(m_RendererID,fragmentShader);

        glLinkProgram(m_RendererID);

        GLint isLinked = 0;
        glGetProgramiv(m_RendererID,GL_LINK_STATUS,(int*)&isLinked);
        if(isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(m_RendererID,GL_INFO_LOG_LENGTH,&maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(m_RendererID,maxLength,&maxLength,infoLog.data());

            glDeleteProgram(m_RendererID);

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            AT_LOG_ERROR("{s}",infoLog.data())
            AT_ASSERT(true,"Shader link failure!")
            return;
        }

        glDetachShader(m_RendererID,vertexShader);
        glDetachShader(m_RendererID,fragmentShader);
    }

    CShader::~CShader(void)
    {
        glDeleteProgram(m_RendererID);
    }

    void CShader::Bind(void) const
    {
        glUseProgram(m_RendererID);
    }

    void CShader::Unbind(void) const
    {
        glUseProgram(0);
    }
}