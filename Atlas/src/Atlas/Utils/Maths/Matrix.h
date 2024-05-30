#pragma once
#include <iomanip>
#include <iostream>
#include "Vector.h"

namespace Math
{
    struct Matrix3d
    {
        Vector3f m_right;
        Vector3f m_up;
        Vector3f m_position;

        Matrix3d()
        {
            m_right.m_arfDirection[0] = 1.0f;
            m_up.m_arfDirection[1] = 1.0f;
            m_position.m_arfDirection[2] = 1.0f;
        }

        Matrix3d(const Matrix3d &rhs)
        {
            m_right = rhs.m_right;
            m_up = rhs.m_up;
            m_position = rhs.m_position;
        }

        Matrix3d(const Vector3f &right, const Vector3f &up, const Vector3f &position)
        {
            m_right = right;
            m_up = up;
            m_position = position;
        }

        void to_array(float *out) const
        {
            out[0] = m_right.m_arfDirection[0];
            out[3] = m_right.m_arfDirection[1];
            out[6] = m_right.m_arfDirection[2];

            out[1] = m_up.m_arfDirection[0];
            out[4] = m_up.m_arfDirection[1];
            out[7] = m_up.m_arfDirection[2];

            out[2] = m_position.m_arfDirection[0];
            out[5] = m_position.m_arfDirection[1];
            out[8] = m_position.m_arfDirection[2];
        }


        std::string to_string(void)
        {
            std::stringstream buffer;
            buffer << std::fixed << std::setprecision(4) << std::setfill(' ');
            buffer << '|' << m_right.m_arfDirection[0] << " " << m_up.m_arfDirection[0] << " " << m_position.m_arfDirection[0] << "|\n";
            buffer << '|' << m_right.m_arfDirection[1] << " " << m_up.m_arfDirection[1] << " " << m_position.m_arfDirection[1] << "|\n";
            buffer << '|' << m_right.m_arfDirection[2] << " " << m_up.m_arfDirection[2] << " " << m_position.m_arfDirection[2] << "|\n";
            return buffer.str();
        }

        void SetIdentity(void)
        {
            //Todo after writting operator=
        }

        float Det(void)
        {
            float result;

            result = m_right.m_arfDirection[0] * ((m_up.m_arfDirection[1]*m_position.m_arfDirection[2]) - (m_position.m_arfDirection[1]*m_up.m_arfDirection[2])) -
                     m_up.m_arfDirection[0] * ((m_right.m_arfDirection[1]*m_position.m_arfDirection[2]) - (m_position.m_arfDirection[1]*m_right.m_arfDirection[2])) -
                     m_position.m_arfDirection[0] * ((m_right.m_arfDirection[1]*m_up.m_arfDirection[2]) - (m_right.m_arfDirection[2]*m_up.m_arfDirection[1]));

            return result;
        }

        void Inverse(void)
        {
        }

        void RotateX(float fAngle)
        {
        }

        void RotateY(float fAngle)
        {
        }

        void RotateZ(float fAngle)
        {
        }

        void Scale(float scalarX, float scalarY, float scalarZ)
        {
            Matrix3d ID;
            ID.m_right.m_arfDirection[0] = scalarX;
            ID.m_up.m_arfDirection[1] = scalarY;
            ID.m_position.m_arfDirection[2] = scalarZ;
            Multiply(ID);
        }

        void Translate(float x, float y)
        {
        }

        void Translate(const Vector3f &distance)
        {
        }

        void Multiply(const Matrix3d &rhs)
        {
            float lhs[9];
            float rhm[9];

            to_array(lhs);
            rhs.to_array(rhm);

            m_right.m_arfDirection[0] = (lhs[0]*rhm[0]) + (lhs[1]*rhm[3]) + (lhs[2]*rhm[6]);
            m_up.m_arfDirection[0] = (lhs[0]*rhm[1]) + (lhs[1]*rhm[4]) + (lhs[2]*rhm[7]);
            m_position.m_arfDirection[0] = (lhs[0]*rhm[2]) + (lhs[1]*rhm[5]) + (lhs[2]*rhm[8]);

            m_right.m_arfDirection[1] = (lhs[3]*rhm[0]) + (lhs[4]*rhm[3]) + (lhs[5]*rhm[6]);
            m_up.m_arfDirection[1] = (lhs[3]*rhm[1]) + (lhs[4]*rhm[4]) + (lhs[5]*rhm[7]);
            m_position.m_arfDirection[1] = (lhs[3]*rhm[2]) + (lhs[4]*rhm[5]) + (lhs[5]*rhm[8]);

            m_right.m_arfDirection[2] = (lhs[6]*rhm[0]) + (lhs[7]*rhm[3]) + (lhs[8]*rhm[6]);
            m_up.m_arfDirection[2] = (lhs[6]*rhm[1]) + (lhs[7]*rhm[4]) + (lhs[8]*rhm[7]);
            m_position.m_arfDirection[2] = (lhs[6]*rhm[2]) + (lhs[7]*rhm[5]) + (lhs[8]*rhm[8]);
        }

        Matrix3d &operator*(const Matrix3d &rhs)
        {
            this->Multiply(rhs);
            return *this;
        }

        Matrix3d &operator=(const Matrix3d &rhs)
        {
            m_right = rhs.m_right;
            m_up = rhs.m_up;
            m_position = rhs.m_position;
            return *this;
        }
    };
}
