#pragma once
#include "..\atpch.h"

namespace Maths
{
    #define _X m_arfDirection[0]
    #define _Y m_arfDirection[1]
    #define _Z m_arfDirection[2]
    #define _W m_arfDirection[3]

    inline float DegreestoRadians(float angle)
    {
        return angle * (180/M_PI);
    }

    struct vec4
    {
        float m_arfDirection[4];

        vec4()
        {
            m_arfDirection[0] = 0.0f;
            m_arfDirection[1] = 0.0f;
            m_arfDirection[2] = 0.0f;
            m_arfDirection[3] = 1.0f;
        }

        vec4(const vec4 &value)
        {
            m_arfDirection[0] = value.m_arfDirection[0];
            m_arfDirection[1] = value.m_arfDirection[1];
            m_arfDirection[2] = value.m_arfDirection[2];
            m_arfDirection[3] = value.m_arfDirection[3];
        }

        vec4(float x, float y, float z, float w = 0.0f)
        {
            m_arfDirection[0] = x;
            m_arfDirection[1] = y;
            m_arfDirection[2] = z;
            m_arfDirection[3] = w;
        }

        vec4(const float *values)
        {
            int size = sizeof(values) / sizeof(values[0]);
            switch(size)
            {
                case 4:
                {
                    m_arfDirection[0] = values[0];
                    m_arfDirection[1] = values[1];
                    m_arfDirection[2] = values[2];
                    m_arfDirection[3] = values[3];        
                } break;                
                case 3:
                {
                    m_arfDirection[0] = values[0];
                    m_arfDirection[1] = values[1];
                    m_arfDirection[2] = values[2];
                    m_arfDirection[3] = 1.0f;
                } break;
                case 2:
                {
                    m_arfDirection[0] = values[0];
                    m_arfDirection[1] = values[1];
                    m_arfDirection[2] = 0.0f;
                    m_arfDirection[3] = 1.0f;
                } break;
                case 1:
                {
                    m_arfDirection[0] = values[0];
                    m_arfDirection[1] = 0.0f;
                    m_arfDirection[2] = 0.0f;
                    m_arfDirection[3] = 1.0f;
                } break;

            };
        }

        vec4 &operator=(const vec4 &rhs)
        {
            m_arfDirection[0] = rhs.m_arfDirection[0];
            m_arfDirection[1] = rhs.m_arfDirection[1];
            m_arfDirection[2] = rhs.m_arfDirection[2];
            m_arfDirection[3] = rhs.m_arfDirection[3];
            return *this;
        }

        vec4 &operator+=(const vec4 &rhs)
        {
            m_arfDirection[0] += rhs.m_arfDirection[0];
            m_arfDirection[1] += rhs.m_arfDirection[1];
            m_arfDirection[2] += rhs.m_arfDirection[2];
            return *this;
        }

        vec4 &operator-=(const vec4 &rhs)
        {
            m_arfDirection[0] -= rhs.m_arfDirection[0];
            m_arfDirection[1] -= rhs.m_arfDirection[1];
            m_arfDirection[2] -= rhs.m_arfDirection[2];
            return *this;
        }

        vec4 &operator*=(const float rhs)
        {
            m_arfDirection[0] *= rhs;
            m_arfDirection[1] *= rhs;
            m_arfDirection[2] *= rhs;
            return *this;
        }

        std::string to_string(void)
        {
            std::stringstream buffer;
            buffer << '[' << std::to_string(m_arfDirection[0]) << ", ";
            buffer << std::to_string(m_arfDirection[1]) << ", ";
            buffer << std::to_string(m_arfDirection[2]) << ", ";
            buffer << std::to_string(m_arfDirection[3]) << ']';

            return buffer.str();
        }

        float Magnitude(void) const
        {
            return std::sqrt(std::pow(m_arfDirection[0],2) + std::pow(m_arfDirection[1],2) +
                    std::pow(m_arfDirection[2],2));
        }

        void Normalize(void)
        {
            float mag = Magnitude();

            //Zero check!!! NO DIVISION BY ZERO!!!!
            if(!mag)
            {
                m_arfDirection[0] = 1.0f;
                return;
            }

            for(int i=0;i<3;i++)
                m_arfDirection[i] /= mag;
        }

        float Dot(const vec4 &rhs)
        {
            float result = 0.0f;
            for(int i=0; i<3; i++)
                result += m_arfDirection[i] * rhs.m_arfDirection[i];
            return result;
        }

        vec4 CrossProduct(const vec4 &rhs)
        {
            vec4 result;

            result.m_arfDirection[0] = (m_arfDirection[1] * rhs.m_arfDirection[2]) - (m_arfDirection[2] * rhs.m_arfDirection[1]);
            result.m_arfDirection[1] = (m_arfDirection[2] * rhs.m_arfDirection[0]) - (m_arfDirection[0] * rhs.m_arfDirection[2]);
            result.m_arfDirection[2] = (m_arfDirection[0] * rhs.m_arfDirection[1]) - (m_arfDirection[1] * rhs.m_arfDirection[0]);

            return result;
        }

        float AngleBetween(const vec4 &rhs)
        {
            float result = std::acos(Dot(rhs)) / (Magnitude() * rhs.Magnitude());
            return result;
        }

        friend vec4 operator+(const vec4 &lhs, const vec4 &rhs)
        {
            vec4 result;
            for(int i=0; i<3; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] + rhs.m_arfDirection[i];
            return result;
        }

        friend vec4 operator-(const vec4 &lhs, const vec4 &rhs)
        {
            vec4 result;
            for(int i=0; i<3; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] - rhs.m_arfDirection[i];
            return result;
        }

        friend vec4 operator*(const vec4 &lhs, const float rhs)
        {
            vec4 result;
            for(int i=0; i<3; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] * rhs;
            return result;
        }
    };

    struct vec3
    {
        float m_arfDirection[3];

        vec3()
        {
            m_arfDirection[0] = 0.0f;
            m_arfDirection[1] = 0.0f;
            m_arfDirection[2] = 0.0f;
        }

        vec3(const vec3 &value)
        {
            m_arfDirection[0] = value.m_arfDirection[0];
            m_arfDirection[1] = value.m_arfDirection[1];
            m_arfDirection[2] = value.m_arfDirection[2];
        }

        vec3(float x, float y, float z)
        {
            m_arfDirection[0] = x;
            m_arfDirection[1] = y;
            m_arfDirection[2] = z;
        }

        vec3 &operator=(const vec3 &rhs)
        {
            m_arfDirection[0] = rhs.m_arfDirection[0];
            m_arfDirection[1] = rhs.m_arfDirection[1];
            m_arfDirection[2] = rhs.m_arfDirection[2];
            return *this;
        }

        vec3 &operator+=(const vec3 &rhs)
        {
            m_arfDirection[0] += rhs.m_arfDirection[0];
            m_arfDirection[1] += rhs.m_arfDirection[1];
            m_arfDirection[2] += rhs.m_arfDirection[2];
            return *this;
        }

        vec3 &operator-=(const vec3 &rhs)
        {
            m_arfDirection[0] -= rhs.m_arfDirection[0];
            m_arfDirection[1] -= rhs.m_arfDirection[1];
            m_arfDirection[2] -= rhs.m_arfDirection[2];
            return *this;
        }

        vec3 &operator*=(const float rhs)
        {
            m_arfDirection[0] *= rhs;
            m_arfDirection[1] *= rhs;
            m_arfDirection[2] *= rhs;
            return *this;
        }

        std::string to_string(void)
        {
            std::stringstream buffer;
            buffer << '[' << std::to_string(m_arfDirection[0]) << ", ";
            buffer << std::to_string(m_arfDirection[1]) << ", ";
            buffer << std::to_string(m_arfDirection[2]) << ']';

            return buffer.str();
        }

        float Magnitude(void) const
        {
            return std::sqrt(std::pow(m_arfDirection[0],2) + std::pow(m_arfDirection[1],2) +
                    std::pow(m_arfDirection[2],2));
        }

        void Normalize(void)
        {
            float mag = Magnitude();

            //Zero check!!! NO DIVISION BY ZERO!!!!
            if(!mag)
            {
                m_arfDirection[0] = 1.0f;
                return;
            }

            for(int i=0;i<3;i++)
                m_arfDirection[i] /= mag;
        }

        float Dot(const vec3 &rhs)
        {
            float result = 0.0f;
            for(int i=0; i<3; i++)
                result += m_arfDirection[i] * rhs.m_arfDirection[i];
            return result;
        }

        vec3 CrossProduct(const vec3 &rhs)
        {
            vec3 result;

            result.m_arfDirection[0] = (m_arfDirection[1] * rhs.m_arfDirection[2]) - (m_arfDirection[2] * rhs.m_arfDirection[1]);
            result.m_arfDirection[1] = (m_arfDirection[0] * rhs.m_arfDirection[2]) - (m_arfDirection[2] * rhs.m_arfDirection[1]);
            result.m_arfDirection[2] = (m_arfDirection[0] * rhs.m_arfDirection[1]) - (m_arfDirection[1] * rhs.m_arfDirection[0]);

            return result;
        }

        float AngleBetween(const vec3 &rhs)
        {
            float result = std::acos(Dot(rhs)) / (Magnitude() * rhs.Magnitude());
            return result;
        }

        friend vec3 operator+(const vec3 &lhs, const vec3 &rhs)
        {
            vec3 result;
            for(int i=0; i<3; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] + rhs.m_arfDirection[i];
            return result;
        }

        friend vec3 operator-(const vec3 &lhs, const vec3 &rhs)
        {
            vec3 result;
            for(int i=0; i<3; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] - rhs.m_arfDirection[i];
            return result;
        }

        friend vec3 operator*(const vec3 &lhs, const float rhs)
        {
            vec3 result;
            for(int i=0; i<3; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] * rhs;
            return result;
        }
    };

    struct vec2
    {
        float m_arfDirection[2];

        vec2()
        {
            m_arfDirection[0] = 0.0f;
            m_arfDirection[1] = 0.0f;
        }

        vec2(const vec2 &value)
        {
            m_arfDirection[0] = value.m_arfDirection[0];
            m_arfDirection[1] = value.m_arfDirection[1];
        }

        vec2(float x, float y)
        {
            m_arfDirection[0] = x;
            m_arfDirection[1] = y;
        }

        vec2 &operator=(const vec2 &rhs)
        {
            m_arfDirection[0] = rhs.m_arfDirection[0];
            m_arfDirection[1] = rhs.m_arfDirection[1];
            return *this;
        }

        vec2 &operator+=(const vec2 &rhs)
        {
            m_arfDirection[0] += rhs.m_arfDirection[0];
            m_arfDirection[1] += rhs.m_arfDirection[1];
            return *this;
        }

        vec2 &operator-=(const vec2 &rhs)
        {
            m_arfDirection[0] -= rhs.m_arfDirection[0];
            m_arfDirection[1] -= rhs.m_arfDirection[1];
            return *this;
        }

        vec2 &operator*=(const float rhs)
        {
            m_arfDirection[0] *= rhs;
            m_arfDirection[1] *= rhs;
            return *this;
        }

        std::string to_string(void)
        {
            std::stringstream buffer;
            buffer << '[' << std::to_string(m_arfDirection[0]) << ", ";
            buffer << std::to_string(m_arfDirection[1]) << ']';

            return buffer.str();
        }

        float Magnitude(void) const
        {
            return std::sqrt(std::pow(m_arfDirection[0],2) + std::pow(m_arfDirection[1],2));
        }

        void Normalize(void)
        {
            float mag = Magnitude();

            //Zero check!!! NO DIVISION BY ZERO!!!!
            if(!mag)
            {
                m_arfDirection[0] = 1.0f;
                return;
            }

            for(int i=0;i<2;i++)
                m_arfDirection[i] /= mag;
        }

        float Dot(const vec2 &rhs)
        {
            float result = 0.0f;
            for(int i=0; i<2; i++)
                result += m_arfDirection[i] * rhs.m_arfDirection[i];
            return result;
        }

        float AngleBetween(const vec2 &rhs)
        {
            float result = std::acos(Dot(rhs)) / (Magnitude() * rhs.Magnitude());
            return result;
        }

        friend vec2 operator+(const vec2 &lhs, const vec2 &rhs)
        {
            vec2 result;
            for(int i=0; i<2; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] + rhs.m_arfDirection[i];
            return result;
        }

        friend vec2 operator-(const vec2 &lhs, const vec2 &rhs)
        {
            vec2 result;
            for(int i=0; i<2; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] - rhs.m_arfDirection[i];
            return result;
        }

        friend vec2 operator*(const vec2 &lhs, const float rhs)
        {
            vec2 result;
            for(int i=0; i<2; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] * rhs;
            return result;
        }
    };

    inline bool operator==(const vec4 &lhs, const vec4 &rhs)
    {
        for(int i=0; i<3; i++)
        {
            if(lhs.m_arfDirection[i] != rhs.m_arfDirection[i])
                return false;
        }

        return true;
    }

    inline bool operator!=(const vec4 &lhs, const vec4 &rhs)
    {
        for(int i=0; i<3; i++)
        {
            if(lhs.m_arfDirection[i] == rhs.m_arfDirection[i])
                return false;
        }

        return true;
    }

    inline bool operator==(const vec3 &lhs, const vec3 &rhs)
    {
        for(int i=0; i<3; i++)
        {
            if(lhs.m_arfDirection[i] != rhs.m_arfDirection[i])
                return false;
        }

        return true;
    }

    inline bool operator!=(const vec3 &lhs, const vec3 &rhs)
    {
        for(int i=0; i<3; i++)
        {
            if(lhs.m_arfDirection[i] == rhs.m_arfDirection[i])
                return false;
        }

        return true;
    }

    inline bool operator==(const vec2 &lhs, const vec2 &rhs)
    {
        for(int i=0; i<2; i++)
        {
            if(lhs.m_arfDirection[i] != rhs.m_arfDirection[i])
                return false;
        }

        return true;
    }

    inline bool operator!=(const vec2 &lhs, const vec2 &rhs)
    {
        for(int i=0; i<2; i++)
        {
            if(lhs.m_arfDirection[i] == rhs.m_arfDirection[i])
                return false;
        }

        return true;
    }

}
