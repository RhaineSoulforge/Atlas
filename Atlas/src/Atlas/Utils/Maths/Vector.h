#include <sstream>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

namespace Math
{
    inline float RadianToDegrees(float angle)
    {
        return angle * (180/M_PI);
    }

    struct Vector4f
    {
        float m_arfDirection[4];

        Vector4f()
        {
            m_arfDirection[0] = 0.0f;
            m_arfDirection[1] = 0.0f;
            m_arfDirection[2] = 0.0f;
            m_arfDirection[3] = 1.0f;
        }

        Vector4f(const Vector4f &value)
        {
            m_arfDirection[0] = value.m_arfDirection[0];
            m_arfDirection[1] = value.m_arfDirection[1];
            m_arfDirection[2] = value.m_arfDirection[2];
            m_arfDirection[3] = value.m_arfDirection[3];
        }

        Vector4f(float x, float y, float z, float w = 1.0f)
        {
            m_arfDirection[0] = x;
            m_arfDirection[1] = y;
            m_arfDirection[2] = z;
            m_arfDirection[3] = w;
        }

        Vector4f &operator=(const Vector4f &rhs)
        {
            m_arfDirection[0] = rhs.m_arfDirection[0];
            m_arfDirection[1] = rhs.m_arfDirection[1];
            m_arfDirection[2] = rhs.m_arfDirection[2];
            m_arfDirection[3] = rhs.m_arfDirection[3];
            return *this;
        }

        Vector4f &operator+=(const Vector4f &rhs)
        {
            m_arfDirection[0] += rhs.m_arfDirection[0];
            m_arfDirection[1] += rhs.m_arfDirection[1];
            m_arfDirection[2] += rhs.m_arfDirection[2];
            return *this;
        }

        Vector4f &operator-=(const Vector4f &rhs)
        {
            m_arfDirection[0] -= rhs.m_arfDirection[0];
            m_arfDirection[1] -= rhs.m_arfDirection[1];
            m_arfDirection[2] -= rhs.m_arfDirection[2];
            return *this;
        }

        Vector4f &operator*=(const float rhs)
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

        float Dot(const Vector4f &rhs)
        {
            float result = 0.0f;
            for(int i=0; i<3; i++)
                result += m_arfDirection[i] * rhs.m_arfDirection[i];
            return result;
        }

        Vector4f CrossProduct(const Vector4f &rhs)
        {
            Vector4f result;

            result.m_arfDirection[0] = (m_arfDirection[1] * rhs.m_arfDirection[2]) - (m_arfDirection[2] * rhs.m_arfDirection[1]);
            result.m_arfDirection[1] = (m_arfDirection[2] * rhs.m_arfDirection[0]) - (m_arfDirection[0] * rhs.m_arfDirection[2]);
            result.m_arfDirection[2] = (m_arfDirection[0] * rhs.m_arfDirection[1]) - (m_arfDirection[1] * rhs.m_arfDirection[0]);

            return result;
        }

        float AngleBetween(const Vector4f &rhs)
        {
            float result = std::acos(Dot(rhs)) / (Magnitude() * rhs.Magnitude());
            return result;
        }

        friend Vector4f operator+(const Vector4f &lhs, const Vector4f &rhs)
        {
            Vector4f result;
            for(int i=0; i<3; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] + rhs.m_arfDirection[i];
            return result;
        }

        friend Vector4f operator-(const Vector4f &lhs, const Vector4f &rhs)
        {
            Vector4f result;
            for(int i=0; i<3; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] - rhs.m_arfDirection[i];
            return result;
        }

        friend Vector4f operator*(const Vector4f &lhs, const float rhs)
        {
            Vector4f result;
            for(int i=0; i<3; i++)
                result.m_arfDirection[i] = lhs.m_arfDirection[i] * rhs;
            return result;
        }
    };

    inline bool operator==(const Vector4f &lhs, const Vector4f &rhs)
    {
        for(int i=0; i<3; i++)
        {
            if(lhs.m_arfDirection[i] != rhs.m_arfDirection[i])
                return false;
        }

        return true;
    }

    inline bool operator!=(const Vector4f &lhs, const Vector4f &rhs)
    {
        for(int i=0; i<3; i++)
        {
            if(lhs.m_arfDirection[i] == rhs.m_arfDirection[i])
                return false;
        }

        return true;
    }
}
