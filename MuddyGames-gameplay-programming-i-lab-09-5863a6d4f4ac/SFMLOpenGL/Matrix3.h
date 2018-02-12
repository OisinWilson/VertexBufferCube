#pragma once

//@author Oisin Wilson
//@login C00213826
//@description: 
// Demo of 3D library on a cube
//@Known Bugs:
// no known bugs

#include"Vector3.h"

const double PI{ 3.14159265359 };

namespace gpp {
	class Matrix3
	{
	public:
		Matrix3();
		Matrix3(Vector3D Row1, Vector3D Row2, Vector3D Row3);
		Matrix3(double A11, double A12, double A13,
			double A21, double A22, double A23,
			double A31, double A32, double A33);

		Vector3D operator *(Vector3D V1) const;
		//static Vector3 operator *(Vector3 V1, Matrix3 M1);

		Matrix3 Transpose() const;

		Matrix3 operator +(Matrix3 M1) const;
		Matrix3 operator -(Matrix3 M1) const;

		Matrix3 operator *(double x) const;
		Matrix3 operator *(Matrix3 M1) const;

		double Determinant() const;

		Vector3D Row(int i) const;

		Vector3D Column(int i) const;

		Matrix3 Inverse() const;
		Matrix3 Rotation(int angle) const;
		static Matrix3 Translate(float dx, float dy);
		Matrix3 Scale(int dx, int dy) const;

		Matrix3 operator -() const;

		static Matrix3 RotationX(float angle);
		static Matrix3 RotationY(float angle);
		static Matrix3 RotationZ(float angle);

		static Matrix3 Scale3D(int dx);

	private:
		double m_A11;
		double m_A12;
		double m_A13;
		double m_A21;
		double m_A22;
		double m_A23;
		double m_A31;
		double m_A32;
		double m_A33;
	};
}