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

        Matrix &operator=(const Matrix &rhs)
        {
            m_right = rhs.m_right;
            m_up = rhs.m_up;
            m_forward = rhs.m_forward;
            m_position = rhs.m_position;
            return *this;
        }
    };
    // struct Matrix3d
    // {
    //     Vector3f m_right;
    //     Vector3f m_up;
    //     Vector3f m_position;

    //     Matrix3d()
    //     {
    //         m_right.m_arfDirection[0] = 1.0f;
    //         m_up.m_arfDirection[1] = 1.0f;
    //         m_position.m_arfDirection[2] = 1.0f;
    //     }

    //     Matrix3d(const Matrix3d &rhs)
    //     {
    //         m_right = rhs.m_right;
    //         m_up = rhs.m_up;
    //         m_position = rhs.m_position;
    //     }

    //     Matrix3d(const Vector3f &right, const Vector3f &up, const Vector3f &position)
    //     {
    //         m_right = right;
    //         m_up = up;
    //         m_position = position;
    //     }

    //     void to_array(float *out) const
    //     {
    //         out[0] = m_right.m_arfDirection[0];
    //         out[3] = m_right.m_arfDirection[1];
    //         out[6] = m_right.m_arfDirection[2];

    //         out[1] = m_up.m_arfDirection[0];
    //         out[4] = m_up.m_arfDirection[1];
    //         out[7] = m_up.m_arfDirection[2];

    //         out[2] = m_position.m_arfDirection[0];
    //         out[5] = m_position.m_arfDirection[1];
    //         out[8] = m_position.m_arfDirection[2];
    //     }


    //     std::string to_string(void)
    //     {
    //         std::stringstream buffer;
    //         buffer << std::fixed << std::setprecision(4) << std::setfill(' ');
    //         buffer << '|' << m_right.m_arfDirection[0] << " " << m_up.m_arfDirection[0] << " " << m_position.m_arfDirection[0] << "|\n";
    //         buffer << '|' << m_right.m_arfDirection[1] << " " << m_up.m_arfDirection[1] << " " << m_position.m_arfDirection[1] << "|\n";
    //         buffer << '|' << m_right.m_arfDirection[2] << " " << m_up.m_arfDirection[2] << " " << m_position.m_arfDirection[2] << "|\n";
    //         return buffer.str();
    //     }

    //     void SetIdentity(void)
    //     {
    //         //Todo after writting operator=
    //         m_right.m_arfDirection[0] = m_up.m_arfDirection[1] = m_position.m_arfDirection[2] = 1.0f;

    //         m_right.m_arfDirection[1] = m_right.m_arfDirection[2] = 0.0f;
    //         m_up.m_arfDirection[0] = m_up.m_arfDirection[2] = 0.0f;
    //         m_position.m_arfDirection[0] = m_position.m_arfDirection[1] = 0.0f;
    //     }

    //     float Det(void)
    //     {
    //         float result;

    //         result = m_right.m_arfDirection[0] * ((m_up.m_arfDirection[1]*m_position.m_arfDirection[2]) - (m_position.m_arfDirection[1]*m_up.m_arfDirection[2])) -
    //                  m_up.m_arfDirection[0] * ((m_right.m_arfDirection[1]*m_position.m_arfDirection[2]) - (m_position.m_arfDirection[1]*m_right.m_arfDirection[2])) +
    //                  m_position.m_arfDirection[0] * ((m_right.m_arfDirection[1]*m_up.m_arfDirection[2]) - (m_right.m_arfDirection[2]*m_up.m_arfDirection[1]));

    //         return result;
    //     }

    //     void Inverse(void)
    //     {
    //         float lhs[9];
    //         to_array(lhs);
    //         float det = 1.0f / Det();
    //         std::cout << "Det(f) := " << Det() << std::endl;

    //         //Matrix of Minors
    //         float minors[9];
    //         minors[0] = (lhs[4] * lhs[8]) - (lhs[5] * lhs[7]);
    //         minors[1] = (lhs[3] * lhs[8]) - (lhs[5] * lhs[6]);
    //         minors[2] = (lhs[3] * lhs[7]) - (lhs[4] * lhs[6]);

    //         minors[3] = (lhs[1] * lhs[8]) - (lhs[2] * lhs[7]);
    //         minors[4] = (lhs[0] * lhs[8]) - (lhs[2] * lhs[6]);
    //         minors[5] = (lhs[0] * lhs[7]) - (lhs[1] * lhs[6]);

    //         minors[6] = (lhs[1] * lhs[5]) - (lhs[2] * lhs[4]);
    //         minors[7] = (lhs[0] * lhs[5]) - (lhs[2] * lhs[3]);
    //         minors[8] = (lhs[0] * lhs[4]) - (lhs[1] * lhs[3]);

    //         std::cout << std::fixed << std::setprecision(20);
    //         for(int row=0;row<3;row++)
    //         {
    //             std::cout << "|";
    //             for(int col=0;col<3;col++)
    //             {
    //                 if(col == 2)
    //                     std::cout << minors[col + (row*3)] << "|";
    //                 else
    //                     std::cout << minors[col + (row*3)] << " ";
    //             }
    //             std::cout << std::endl;
    //         }
    //         m_right.m_arfDirection[0] = minors[0] * det;
    //         m_right.m_arfDirection[1] = minors[1] * det * -1.0f;
    //         m_right.m_arfDirection[2] = minors[2] * det;

    //         m_up.m_arfDirection[0] = minors[3] * det * -1.0f;
    //         m_up.m_arfDirection[1] = minors[4] * det;
    //         m_up.m_arfDirection[2] = minors[5] * det * -1.0f;

    //         m_position.m_arfDirection[0] = minors[6] * det;
    //         m_position.m_arfDirection[1] = minors[7] * det * -1.0f;
    //         m_position.m_arfDirection[2] = minors[8] * det;
    //     }

    //     void RotateX(float fAngle)
    //     {
    //         Matrix3d rotmatrix;

    //         m_up.m_arfDirection[1] = std::cos(fAngle);
    //         m_up.m_ar
    //     }

    //     void RotateY(float fAngle)
    //     {
    //     }

    //     void RotateZ(float fAngle)
    //     {
    //     }

    //     void Scale(float scalarX, float scalarY, float scalarZ)
    //     {
    //         Matrix3d ID;
    //         ID.m_right.m_arfDirection[0] = scalarX;
    //         ID.m_up.m_arfDirection[1] = scalarY;
    //         ID.m_position.m_arfDirection[2] = scalarZ;
    //         Multiply(ID);
    //     }

    //     void Translate(float x, float y)
    //     {
    //         Math::Vector3f translate(x,y,0.0f);
    //         m_position += translate;
    //     }

    //     void Translate(const Vector3f &distance)
    //     {
    //         m_position += distance;
    //     }

    //     void Multiply(const Matrix3d &rhs)
    //     {
    //         float lhs[9];
    //         float rhm[9];

    //         to_array(lhs);
    //         rhs.to_array(rhm);

    //         m_right.m_arfDirection[0] = (lhs[0]*rhm[0]) + (lhs[1]*rhm[3]) + (lhs[2]*rhm[6]);
    //         m_up.m_arfDirection[0] = (lhs[0]*rhm[1]) + (lhs[1]*rhm[4]) + (lhs[2]*rhm[7]);
    //         m_position.m_arfDirection[0] = (lhs[0]*rhm[2]) + (lhs[1]*rhm[5]) + (lhs[2]*rhm[8]);

    //         m_right.m_arfDirection[1] = (lhs[3]*rhm[0]) + (lhs[4]*rhm[3]) + (lhs[5]*rhm[6]);
    //         m_up.m_arfDirection[1] = (lhs[3]*rhm[1]) + (lhs[4]*rhm[4]) + (lhs[5]*rhm[7]);
    //         m_position.m_arfDirection[1] = (lhs[3]*rhm[2]) + (lhs[4]*rhm[5]) + (lhs[5]*rhm[8]);

    //         m_right.m_arfDirection[2] = (lhs[6]*rhm[0]) + (lhs[7]*rhm[3]) + (lhs[8]*rhm[6]);
    //         m_up.m_arfDirection[2] = (lhs[6]*rhm[1]) + (lhs[7]*rhm[4]) + (lhs[8]*rhm[7]);
    //         m_position.m_arfDirection[2] = (lhs[6]*rhm[2]) + (lhs[7]*rhm[5]) + (lhs[8]*rhm[8]);
    //     }

    //     Matrix3d &operator*(const Matrix3d &rhs)
    //     {
    //         this->Multiply(rhs);
    //         return *this;
    //     }

    //     Matrix3d &operator=(const Matrix3d &rhs)
    //     {
    //         m_right = rhs.m_right;
    //         m_up = rhs.m_up;
    //         m_position = rhs.m_position;
    //         return *this;
    //     }
    // };
}
