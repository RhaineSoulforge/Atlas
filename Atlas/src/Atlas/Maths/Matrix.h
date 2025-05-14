#pragma once
#include "..\atpch.h"
#include "Vector.h"

namespace Maths
{
    struct mat4
    {
        float values[16];

        mat4(void)
        {
            SetIdentity();
        }

        mat4(const mat4 &rhs)
        {
            memcpy(values,rhs.values,sizeof(rhs.values));
        }

        mat4(const std::initializer_list<float> vals)
        {
            int i = 0;
            for(float value : vals)
            {
                values[i] = value;
                i++;
            }
        }

        mat4(const vec4 &right, const vec4 &up, const vec4 &at, const vec4 &position)
        {
            //Right
            values[0] = right.m_arfDirection[0];
            values[4] = right.m_arfDirection[1];
            values[8] = right.m_arfDirection[2];
            values[12] = right.m_arfDirection[3];
            
            //Up
            values[1] = up.m_arfDirection[0];
            values[5] = up.m_arfDirection[1];
            values[9] = up.m_arfDirection[2];
            values[13] = up.m_arfDirection[3];

            //At
            values[2] = at.m_arfDirection[0];
            values[6] = at.m_arfDirection[1];
            values[10] = at.m_arfDirection[2];
            values[14] = at.m_arfDirection[3];

            //Position
            values[3] = position.m_arfDirection[0];
            values[7] = position.m_arfDirection[1];
            values[11] = position.m_arfDirection[2];
            values[15] = position.m_arfDirection[3];
        }

        void SetIdentity(void)
        {
            memset(values,0,sizeof(values));
            values[0] = values[5] = values[10] = values[15] = 1.0f;
        }

        std::string to_string(void)const
        {
            std::stringstream buffer;
            buffer << std::fixed << std::setprecision(4) << std::setfill(' ');
            buffer << '|' << values[0] << " " << values[1] << " " << values[2] << " " << values[3] << "|\n";
            buffer << '|' << values[4] << " " << values[5] << " " << values[6] << " " << values[7] << "|\n";
            buffer << '|' << values[8] << " " << values[9] << " " << values[10] << " " << values[11] << "|\n";
            buffer << '|' << values[12] << " " << values[13] << " " << values[14] << " " << values[15] << "|\n";
            return buffer.str().c_str();
        }

        void rotateX(float angle)
        { 
            float fRads = DegreestoRadians(angle);
            mat4 rotation;

            rotation.values[5] = std::cos(fRads);
            rotation.values[9] = std::sin(fRads);

            rotation.values[6] = -std::sin(fRads);
            rotation.values[10] = std::cos(fRads);

            this->Multiply(rotation);
        }

        void rotateY(float angle)
        {
            float fRads = DegreestoRadians(angle);
            mat4 rotation;

            rotation.values[0] = std::cos(fRads);
            rotation.values[8] = -std::sin(fRads);

            rotation.values[2] = std::sin(fRads);
            rotation.values[10] = std::cos(fRads);

            this->Multiply(rotation);
        }

        void rotateZ(float angle)
        { 
            float fRads = DegreestoRadians(angle);
            mat4 rotation;

            rotation.values[0] = std::cos(fRads);
            rotation.values[4] = std::sin(fRads);

            rotation.values[1] = -std::sin(fRads);
            rotation.values[5] = std::cos(fRads);

            this->Multiply(rotation);
        }

        void scale(float x=1.0f, float y=1.0f, float z=1.0f)
        { 
            mat4 scalingMatrix;
            scalingMatrix.values[0] = x;
            scalingMatrix.values[5] = y;
            scalingMatrix.values[10] = z;

            this->Multiply(scalingMatrix);
        }

        void translate(float x, float y, float z)
        {
            values[3] += x;
            values[7] += y;
            values[11] += z;
        }

        void translate(const vec4 &distance)
        { 
            values[3] += distance._X;
            values[7] += distance._Y;
            values[11] += distance._Z;
        }
        
        void Multiply(const mat4 &rhs)
        {
            mat4 lhs(*this);

            //Row 1
            values[0] = (lhs.values[0] * rhs.values[0]) + (lhs.values[1] * rhs.values[4]) + (lhs.values[2] * rhs.values[8]) + (lhs.values[3] * rhs.values[12]);
            values[1] = (lhs.values[0] * rhs.values[1]) + (lhs.values[1] * rhs.values[5]) + (lhs.values[2] * rhs.values[9]) + (lhs.values[3] * rhs.values[13]);
            values[2] = (lhs.values[0] * rhs.values[2]) + (lhs.values[1] * rhs.values[6]) + (lhs.values[2] * rhs.values[10]) + (lhs.values[3] * rhs.values[14]);
            values[3] = (lhs.values[0] * rhs.values[3]) + (lhs.values[1] * rhs.values[7]) + (lhs.values[2] * rhs.values[11]) + (lhs.values[3] * rhs.values[15]);

            //Row 2
            values[4] = (lhs.values[4] * rhs.values[0]) + (lhs.values[5] * rhs.values[4]) + (lhs.values[6] * rhs.values[8]) + (lhs.values[7] * rhs.values[12]);
            values[5] = (lhs.values[4] * rhs.values[1]) + (lhs.values[5] * rhs.values[5]) + (lhs.values[6] * rhs.values[9]) + (lhs.values[7] * rhs.values[13]);
            values[6] = (lhs.values[4] * rhs.values[2]) + (lhs.values[5] * rhs.values[6]) + (lhs.values[6] * rhs.values[10]) + (lhs.values[7] * rhs.values[14]);
            values[7] = (lhs.values[4] * rhs.values[3]) + (lhs.values[5] * rhs.values[7]) + (lhs.values[6] * rhs.values[11]) + (lhs.values[7] * rhs.values[15]);

            //Row 3
            values[8] = (lhs.values[8] * rhs.values[0]) + (lhs.values[9] * rhs.values[4]) + (lhs.values[10] * rhs.values[8]) + (lhs.values[11] * rhs.values[12]);
            values[9] = (lhs.values[8] * rhs.values[1]) + (lhs.values[9] * rhs.values[5]) + (lhs.values[10] * rhs.values[9]) + (lhs.values[11] * rhs.values[13]);
            values[10] = (lhs.values[8] * rhs.values[2]) + (lhs.values[9] * rhs.values[6]) + (lhs.values[10] * rhs.values[10]) + (lhs.values[11] * rhs.values[14]);
            values[11] = (lhs.values[8] * rhs.values[3]) + (lhs.values[9] * rhs.values[7]) + (lhs.values[10] * rhs.values[11]) + (lhs.values[11] * rhs.values[15]);

            //Row 4
            values[12] = (lhs.values[12] * rhs.values[0]) + (lhs.values[13] * rhs.values[4]) + (lhs.values[14] * rhs.values[8]) + (lhs.values[15] * rhs.values[12]);
            values[13] = (lhs.values[12] * rhs.values[1]) + (lhs.values[13] * rhs.values[5]) + (lhs.values[14] * rhs.values[9]) + (lhs.values[15] * rhs.values[13]);
            values[14] = (lhs.values[12] * rhs.values[2]) + (lhs.values[13] * rhs.values[6]) + (lhs.values[14] * rhs.values[10]) + (lhs.values[15] * rhs.values[14]);
            values[15] = (lhs.values[12] * rhs.values[3]) + (lhs.values[13] * rhs.values[7]) + (lhs.values[14] * rhs.values[11]) + (lhs.values[15] * rhs.values[15]);

        }

        mat4 &operator*(const mat4 &rhs)
        {
            this->Multiply(rhs);
            return *this;
        }
    };
}
