#pragma once
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>
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
            m_right.m_arfDirection[0] = m_up.m_arfDirection[1] = m_position.m_arfDirection[2] = 1.0f;

            m_right.m_arfDirection[1] = m_right.m_arfDirection[2] = 0.0f;
            m_up.m_arfDirection[1] = m_up.m_arfDirection[2] = 0.0f;
            m_position.m_arfDirection[1] = m_position.m_arfDirection[2] = 0.0f;
        }

        Matrix3d(const Vector3f &right, const Vector3f &up, const Vector3f &position)
        {
            m_right = right;
            m_up = up;
            m_position = position;
        }

        float Determinant(void) const
        {
            float fDeterminant = 0;

            fDeterminant = m_right.m_arfDirection[0] * ((m_up.m_arfDirection[1] * m_position.m_arfDirection[2]) - (m_up.m_arfDirection[2] * m_position.m_arfDirection[1])) -
                           m_up.m_arfDirection[0] * ((m_right.m_arfDirection[1] * m_position.m_arfDirection[2]) - (m_right.m_arfDirection[2] * m_position.m_arfDirection[1])) +
                           m_position.m_arfDirection[0] * ((m_right.m_arfDirection[1] * m_up.m_arfDirection[2]) - (m_right.m_arfDirection[2] * m_up.m_arfDirection[1]));

            return fDeterminant;
        }
    };

    struct Matrix
    {
        Vector4f m_right;
        Vector4f m_forward;
        Vector4f m_up;
        Vector4f m_position;

        Matrix()
        {
            m_right.m_arfDirection[0] = 1.0f;
            m_up.m_arfDirection[1] = 1.0f;
            m_forward.m_arfDirection[2] = 1.0f;
            m_position.m_arfDirection[3] = 1.0f;
        }

        Matrix(const Matrix &rhs)
        {
            m_right = rhs.m_right;
            m_forward = rhs.m_forward;
            m_up = rhs.m_up;
            m_position = rhs.m_position;
        }

        Matrix(const Vector4f &right, const Vector4f &up, const Vector4f &forward, const Vector4f &position)
        {
            m_right = right;
            m_up = up;
            m_forward = forward;
            m_position = position;
        }

        std::string to_string(void) const
        {
            std::stringstream buffer;
            buffer << std::fixed << std::setprecision(4) << std::setfill(' ');
            buffer << '|' << m_right.m_arfDirection[0] << " " << m_up.m_arfDirection[0] << " " << m_forward.m_arfDirection[0] << " " << m_position.m_arfDirection[0] << "|\n";
            buffer << '|' << m_right.m_arfDirection[1] << " " << m_up.m_arfDirection[1] << " " << m_forward.m_arfDirection[1] << " " << m_position.m_arfDirection[1] << "|\n";
            buffer << '|' << m_right.m_arfDirection[2] << " " << m_up.m_arfDirection[2] << " " << m_forward.m_arfDirection[2] << " " << m_position.m_arfDirection[2] << "|\n";
            buffer << '|' << m_right.m_arfDirection[3] << " " << m_up.m_arfDirection[3] << " " << m_forward.m_arfDirection[3] << " " << m_position.m_arfDirection[3] << "|\n";
            return buffer.str();
        }

        void SetIdentity(void)
        {
            m_right.m_arfDirection[0] = m_up.m_arfDirection[1] = m_forward.m_arfDirection[2] = m_position.m_arfDirection[3] = 1.0f;

            m_right.m_arfDirection[1] = m_right.m_arfDirection[2] = m_right.m_arfDirection[3] = 0.0f;
            m_up.m_arfDirection[1] = m_up.m_arfDirection[2] = m_up.m_arfDirection[3] = 0.0f;
            m_forward.m_arfDirection[1] = m_forward.m_arfDirection[2] = m_forward.m_arfDirection[3] = 0.0f;
            m_position.m_arfDirection[1] = m_position.m_arfDirection[2] = m_position.m_arfDirection[3] = 0.0f;
        }

        float Determinant(void) const
        {
            float result;

            result = m_right.m_arfDirection[0] * Matrix3d(Vector3f(m_up.m_arfDirection[1],m_up.m_arfDirection[2],m_up.m_arfDirection[3]),
                                                          Vector3f(m_forward.m_arfDirection[1],m_forward.m_arfDirection[2],m_forward.m_arfDirection[3]),
                                                          Vector3f(m_position.m_arfDirection[1],m_position.m_arfDirection[2],m_position.m_arfDirection[3])).Determinant()
                     - m_up.m_arfDirection[0] * Matrix3d(Vector3f(m_right.m_arfDirection[1],m_right.m_arfDirection[2],m_right.m_arfDirection[3]),
                                                         Vector3f(m_forward.m_arfDirection[1],m_forward.m_arfDirection[2],m_forward.m_arfDirection[3]),
                                                         Vector3f(m_position.m_arfDirection[1],m_position.m_arfDirection[2],m_position.m_arfDirection[3])).Determinant()
                     + m_forward.m_arfDirection[0] * Matrix3d(Vector3f(m_right.m_arfDirection[1],m_right.m_arfDirection[2],m_right.m_arfDirection[3]),
                                                              Vector3f(m_up.m_arfDirection[1],m_up.m_arfDirection[2],m_up.m_arfDirection[3]),
                                                              Vector3f(m_position.m_arfDirection[1],m_position.m_arfDirection[2],m_position.m_arfDirection[3])).Determinant()
                     - m_position.m_arfDirection[0] *  Matrix3d(Vector3f(m_right.m_arfDirection[1],m_right.m_arfDirection[2],m_right.m_arfDirection[3]),
                                                                Vector3f(m_up.m_arfDirection[1],m_up.m_arfDirection[2],m_up.m_arfDirection[3]),
                                                                Vector3f(m_forward.m_arfDirection[1],m_forward.m_arfDirection[2],m_forward.m_arfDirection[3])).Determinant();

            return result;
        }

        Matrix Transpose(void) const
        {
            Matrix result;

            result.m_right._X = m_right._X;
            result.m_up._Y = m_up._Y;
            result.m_forward._Z = m_forward._Z;
            result.m_position._W = m_position._W;

            result.m_right._Y = m_up._X;
            result.m_right._Z = m_forward._X;
            result.m_right._W = m_position._X;

            result.m_up._X = m_right._Y;
            result.m_up._Z = m_forward._Y;
            result.m_up._W = m_position._Y;

            result.m_forward._X = m_right._Z;
            result.m_forward._Y = m_up._Z;
            result.m_forward._W = m_position._Z;

            result.m_position._X = m_right._W;
            result.m_position._Y = m_up._W;
            result.m_position._Z = m_forward._W;

            return result;
        }

        Matrix Inverse(void) const
        {
            Matrix result;

            float fDeterminant = 1.0f / Determinant();

            //Matrix of Minors
            result.m_right.m_arfDirection[0] = Matrix3d(Vector3f(m_up.m_arfDirection[1],m_up.m_arfDirection[2],m_up.m_arfDirection[3]),
                                                        Vector3f(m_forward.m_arfDirection[1],m_forward.m_arfDirection[2],m_forward.m_arfDirection[3]),
                                                        Vector3f(m_position.m_arfDirection[1],m_position.m_arfDirection[2],m_position.m_arfDirection[3])).Determinant();

            result.m_right.m_arfDirection[1] = Matrix3d(Vector3f(m_up.m_arfDirection[0],m_up.m_arfDirection[2],m_up.m_arfDirection[3]),
                                                        Vector3f(m_forward.m_arfDirection[0],m_forward.m_arfDirection[2],m_forward.m_arfDirection[3]),
                                                        Vector3f(m_position.m_arfDirection[0],m_position.m_arfDirection[2],m_position.m_arfDirection[3])).Determinant();

            result.m_right.m_arfDirection[2] = Matrix3d(Vector3f(m_up.m_arfDirection[0],m_up.m_arfDirection[1],m_up.m_arfDirection[3]),
                                                        Vector3f(m_forward.m_arfDirection[0],m_forward.m_arfDirection[1],m_forward.m_arfDirection[3]),
                                                        Vector3f(m_position.m_arfDirection[0],m_position.m_arfDirection[1],m_position.m_arfDirection[3])).Determinant();

            result.m_right.m_arfDirection[3] = Matrix3d(Vector3f(m_up.m_arfDirection[0],m_up.m_arfDirection[1],m_up.m_arfDirection[2]),
                                                        Vector3f(m_forward.m_arfDirection[0],m_forward.m_arfDirection[1],m_forward.m_arfDirection[2]),
                                                        Vector3f(m_position.m_arfDirection[0],m_position.m_arfDirection[1],m_position.m_arfDirection[2])).Determinant();

            result.m_up.m_arfDirection[0] = Matrix3d(Vector3f(m_right.m_arfDirection[1],m_right.m_arfDirection[2],m_right.m_arfDirection[3]),
                                                        Vector3f(m_forward.m_arfDirection[1],m_forward.m_arfDirection[2],m_forward.m_arfDirection[3]),
                                                        Vector3f(m_position.m_arfDirection[1],m_position.m_arfDirection[2],m_position.m_arfDirection[3])).Determinant();

            result.m_up.m_arfDirection[1] = Matrix3d(Vector3f(m_right.m_arfDirection[0],m_right.m_arfDirection[2],m_right.m_arfDirection[3]),
                                                        Vector3f(m_forward.m_arfDirection[0],m_forward.m_arfDirection[2],m_forward.m_arfDirection[3]),
                                                        Vector3f(m_position.m_arfDirection[0],m_position.m_arfDirection[2],m_position.m_arfDirection[3])).Determinant();

            result.m_up.m_arfDirection[2] = Matrix3d(Vector3f(m_right.m_arfDirection[0],m_right.m_arfDirection[1],m_right.m_arfDirection[3]),
                                                        Vector3f(m_forward.m_arfDirection[0],m_forward.m_arfDirection[1],m_forward.m_arfDirection[3]),
                                                        Vector3f(m_position.m_arfDirection[0],m_position.m_arfDirection[1],m_position.m_arfDirection[3])).Determinant();

            result.m_up.m_arfDirection[3] = Matrix3d(Vector3f(m_right.m_arfDirection[0],m_right.m_arfDirection[1],m_right.m_arfDirection[2]),
                                                     Vector3f(m_forward.m_arfDirection[0],m_forward.m_arfDirection[1],m_forward.m_arfDirection[2]),
                                                     Vector3f(m_position.m_arfDirection[0],m_position.m_arfDirection[1],m_position.m_arfDirection[2])).Determinant();

            result.m_forward.m_arfDirection[0] = Matrix3d(Vector3f(m_right.m_arfDirection[1],m_right.m_arfDirection[2],m_right.m_arfDirection[3]),
                                                        Vector3f(m_up.m_arfDirection[1],m_up.m_arfDirection[2],m_up.m_arfDirection[3]),
                                                        Vector3f(m_position.m_arfDirection[1],m_position.m_arfDirection[2],m_position.m_arfDirection[3])).Determinant();

            result.m_forward.m_arfDirection[1] = Matrix3d(Vector3f(m_right.m_arfDirection[0],m_right.m_arfDirection[2],m_right.m_arfDirection[3]),
                                                        Vector3f(m_up.m_arfDirection[0],m_up.m_arfDirection[2],m_up.m_arfDirection[3]),
                                                        Vector3f(m_position.m_arfDirection[0],m_position.m_arfDirection[2],m_position.m_arfDirection[3])).Determinant();

            result.m_forward.m_arfDirection[2] = Matrix3d(Vector3f(m_right.m_arfDirection[0],m_right.m_arfDirection[1],m_right.m_arfDirection[3]),
                                                        Vector3f(m_up.m_arfDirection[0],m_up.m_arfDirection[1],m_up.m_arfDirection[3]),
                                                        Vector3f(m_position.m_arfDirection[0],m_position.m_arfDirection[1],m_position.m_arfDirection[3])).Determinant();

            result.m_forward.m_arfDirection[3] =  Matrix3d(Vector3f(m_right.m_arfDirection[0],m_right.m_arfDirection[1],m_right.m_arfDirection[2]),
                                                           Vector3f(m_up.m_arfDirection[0],m_up.m_arfDirection[1],m_up.m_arfDirection[2]),
                                                           Vector3f(m_position.m_arfDirection[0],m_position.m_arfDirection[1],m_position.m_arfDirection[2])).Determinant();

            result.m_position.m_arfDirection[0] = Matrix3d(Vector3f(m_right.m_arfDirection[1],m_right.m_arfDirection[2],m_right.m_arfDirection[3]),
                                                           Vector3f(m_up.m_arfDirection[1],m_up.m_arfDirection[2],m_up.m_arfDirection[3]),
                                                           Vector3f(m_forward.m_arfDirection[1],m_forward.m_arfDirection[2],m_forward.m_arfDirection[3])).Determinant();

            result.m_position.m_arfDirection[1] = Matrix3d(Vector3f(m_right.m_arfDirection[0],m_right.m_arfDirection[2],m_right.m_arfDirection[3]),
                                                           Vector3f(m_up.m_arfDirection[0],m_up.m_arfDirection[2],m_up.m_arfDirection[3]),
                                                           Vector3f(m_forward.m_arfDirection[0],m_forward.m_arfDirection[2],m_forward.m_arfDirection[3])).Determinant();

            result.m_position.m_arfDirection[2] = Matrix3d(Vector3f(m_right.m_arfDirection[0],m_right.m_arfDirection[1],m_right.m_arfDirection[3]),
                                                           Vector3f(m_up.m_arfDirection[0],m_up.m_arfDirection[1],m_up.m_arfDirection[3]),
                                                           Vector3f(m_forward.m_arfDirection[0],m_forward.m_arfDirection[1],m_forward.m_arfDirection[3])).Determinant();

            result.m_position.m_arfDirection[3] = Matrix3d(Vector3f(m_right.m_arfDirection[0],m_right.m_arfDirection[1],m_right.m_arfDirection[2]),
                                                           Vector3f(m_up.m_arfDirection[0],m_up.m_arfDirection[1],m_up.m_arfDirection[2]),
                                                           Vector3f(m_forward.m_arfDirection[0],m_forward.m_arfDirection[1],m_forward.m_arfDirection[2])).Determinant();

            //Matrix of Cofactors
            result.m_up._X *= -1.0f;
            result.m_position._X *= -1.0f;

            result.m_right._Y *= -1.0f;
            result.m_forward._Y *= -1.0f;

            result.m_up._Z *= -1.0f;
            result.m_position._Z *= -1.0f;

            result.m_right._W *= -1.0f;
            result.m_forward._W *= -1.0f;

            result = result.Transpose();

            result.m_right._X *= fDeterminant;
            result.m_right._Y *= fDeterminant;
            result.m_right._Z *= fDeterminant;
            result.m_right._W *= fDeterminant;

            result.m_up._X *= fDeterminant;
            result.m_up._Y *= fDeterminant;
            result.m_up._Z *= fDeterminant;
            result.m_up._W *= fDeterminant;

            result.m_forward._X *= fDeterminant;
            result.m_forward._Y *= fDeterminant;
            result.m_forward._Z *= fDeterminant;
            result.m_forward._W *= fDeterminant;

            result.m_position._X *= fDeterminant;
            result.m_position._Y *= fDeterminant;
            result.m_position._Z *= fDeterminant;
            result.m_position._W *= fDeterminant;

            return result;
        }

        Matrix Multiply(const Matrix &rhs) const
        {
            Matrix result;

            result.m_right._X =    (m_right._X * rhs.m_right._X)          + (m_up._X * rhs.m_right._Y)      + (m_forward._X * rhs.m_right._Z)      + (m_position._X * rhs.m_right._W);
            result.m_up._X =       (m_right._X * rhs.m_up._X)             + (m_up._X * rhs.m_up._Y)         + (m_forward._X * rhs.m_up._Z)         + (m_position._X * rhs.m_up._W);
            result.m_forward._X =  (m_right._X * rhs.m_forward._X)        + (m_up._X * rhs.m_forward._Y)    + (m_forward._X * rhs.m_forward._Z)    + (m_position._X * rhs.m_forward._W);
            result.m_position._X = (m_right._X * rhs.m_position._X)       + (m_up._X * rhs.m_position._Y)   + (m_forward._X * rhs.m_position._Z)   + (m_position._X * rhs.m_position._W);

            result.m_right._Y =    (m_right._Y * rhs.m_right._X)          + (m_up._Y * rhs.m_right._Y)      + (m_forward._Y * rhs.m_right._Z)      + (m_position._Y * rhs.m_right._W);
            result.m_up._Y =       (m_right._Y * rhs.m_up._X)             + (m_up._Y * rhs.m_up._Y)         + (m_forward._Y * rhs.m_up._Z)         + (m_position._Y * rhs.m_up._W);
            result.m_forward._Y =  (m_right._Y * rhs.m_forward._X)        + (m_up._Y * rhs.m_forward._Y)    + (m_forward._Y * rhs.m_forward._Z)    + (m_position._Y * rhs.m_forward._W);
            result.m_position._Y = (m_right._Y * rhs.m_position._X)       + (m_up._Y * rhs.m_position._Y)   + (m_forward._Y * rhs.m_position._Z)   + (m_position._Y * rhs.m_position._W);

            result.m_right._Z =    (m_right._Z * rhs.m_right._X)          + (m_up._Z * rhs.m_right._Y)      + (m_forward._Z * rhs.m_right._Z)      + (m_position._Z * rhs.m_right._W);
            result.m_up._Z =       (m_right._Z * rhs.m_up._X)             + (m_up._Z * rhs.m_up._Y)         + (m_forward._Z * rhs.m_up._Z)         + (m_position._Z * rhs.m_up._W);
            result.m_forward._Z =  (m_right._Z * rhs.m_forward._X)        + (m_up._Z * rhs.m_forward._Y)    + (m_forward._Z * rhs.m_forward._Z)    + (m_position._Z * rhs.m_forward._W);
            result.m_position._Z = (m_right._Z * rhs.m_position._X)       + (m_up._Z * rhs.m_position._Y)   + (m_forward._Z * rhs.m_position._Z)   + (m_position._Z * rhs.m_position._W);

            result.m_right._W =    (m_right._W * rhs.m_right._X)          + (m_up._W * rhs.m_right._Y)      + (m_forward._W * rhs.m_right._Z)      + (m_position._W * rhs.m_right._W);
            result.m_up._W =       (m_right._W * rhs.m_up._X)             + (m_up._W * rhs.m_up._Y)         + (m_forward._W * rhs.m_up._Z)         + (m_position._W * rhs.m_up._W);
            result.m_forward._W =  (m_right._W * rhs.m_forward._X)        + (m_up._W * rhs.m_forward._Y)    + (m_forward._W * rhs.m_forward._Z)    + (m_position._W * rhs.m_forward._W);
            result.m_position._W = (m_right._W * rhs.m_position._X)       + (m_up._W * rhs.m_position._Y)   + (m_forward._W * rhs.m_position._Z)   + (m_position._W * rhs.m_position._W);

            return result;
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Function:  RotateX
        // Last Modified:  July 15, 2024
        // Author:  Jason A Biddle
        //
        // Purpose:  Rotates about the X-axis by a given angle.
        //
        // In:  fAngle - The angle in degrees to be rotated by.
        //
        // Out:  --
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void RotateX(float fAngle)
        {
            float fRads = DegreestoRadians(fAngle);
            Matrix rotation;

            rotation.m_up._Y = std::cos(fRads);
            rotation.m_up._Z = std::sin(fRads);

            rotation.m_forward._Y = -std::sin(fRads);
            rotation.m_forward._Z = std::cos(fRads);

            *this = this->Multiply(rotation);
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Function: RotateY
        // Last Modified:  July 15, 2024
        // Author:  Jason A Biddle
        //
        // Purpose:  Rotates about the Y-axis by a given angle.
        //
        // In:  fAngle - The angle in degrees to be rotate by.
        //
        // Out:  --
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void RotateY(float fAngle)
        {
            float fRads = DegreestoRadians(fAngle);
            Matrix rotation;

            rotation.m_right._X = std::cos(fRads);
            rotation.m_right._Z = -std::sin(fRads);

            rotation.m_forward._X = std::sin(fRads);
            rotation.m_forward._Z = std::cos(fRads);

            *this = this->Multiply(rotation);
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Function: RotateZ
        // Last Modified:  July 15, 2024
        // Author:  Jason A Biddle
        //
        // Purpose:  Rotates about the Z-axis by a given angle.
        //
        // In:  fAngle - The angle in degrees to be rotate by.
        //
        // Out:  --
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void RotateZ(float fAngle)
        {
            float fRads = DegreestoRadians(fAngle);
            Matrix rotation;

            rotation.m_right._X = std::cos(fRads);
            rotation.m_right._Y = std::sin(fRads);

            rotation.m_up._X = -std::sin(fRads);
            rotation.m_up._Y = std::cos(fRads);

            *this = this->Multiply(rotation);
        }

        void Scale(float fX, float fY, float fZ)
        {
            Matrix scalar;
            scalar.m_right._X = fX;
            scalar.m_up._Y = fY;
            scalar.m_forward._Z = fZ;

            *this = this->Multiply(scalar);
        }

        void Translate(float fX, float fY, float fZ)
        {
            m_position._X += fX;
            m_position._Y += fY;
            m_position._Z += fZ;
        }

        void Translate(const Vector4f &distance)
        {
            m_position += distance;
        }

        Matrix &operator=(const Matrix &rhs)
        {
            m_right = rhs.m_right;
            m_up = rhs.m_up;
            m_forward = rhs.m_forward;
            m_position = rhs.m_position;
            return *this;
        }
    };
}
