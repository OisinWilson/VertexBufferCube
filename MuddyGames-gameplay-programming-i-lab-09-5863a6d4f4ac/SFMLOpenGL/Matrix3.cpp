#include"Matrix3.h"

//@author Oisin Wilson
//@login C00213826
//@description: 
// Demo of 3D library on a cube
//@Known Bugs:
// no known bugs
namespace gpp {
	Matrix3::Matrix3()
	{
		m_A11 = 0.0;
		m_A12 = 0.0;
		m_A13 = 0.0;
		m_A21 = 0.0;
		m_A22 = 0.0;
		m_A23 = 0.0;
		m_A31 = 0.0;
		m_A32 = 0.0;
		m_A33 = 0.0;
	}

	Matrix3::Matrix3(Vector3D Row1, Vector3D Row2, Vector3D Row3)
		:
		m_A11(Row1.ReturnX()),
		m_A12(Row1.ReturnY()),
		m_A13(Row1.ReturnZ()),
		m_A21(Row2.ReturnX()),
		m_A22(Row2.ReturnY()),
		m_A23(Row2.ReturnZ()),
		m_A31(Row3.ReturnX()),
		m_A32(Row3.ReturnY()),
		m_A33(Row3.ReturnZ())
	{
	}

	Matrix3::Matrix3(double A11, double A12, double A13, double A21, double A22, double A23, double A31, double A32, double A33)
		:
		m_A11(A11),
		m_A12(A12),
		m_A13(A13),
		m_A21(A21),
		m_A22(A22),
		m_A23(A23),
		m_A31(A31),
		m_A32(A32),
		m_A33(A33)
	{
	}

	Vector3D Matrix3::operator*(Vector3D V1) const
	{
		return Vector3D(m_A11 * V1.ReturnX() + m_A12 * V1.ReturnY() + m_A13 * V1.ReturnZ(),
			m_A21 * V1.ReturnX() + m_A22 * V1.ReturnY() + m_A23 * V1.ReturnZ(),
			m_A31 * V1.ReturnX() + m_A32 * V1.ReturnY() + m_A33 * V1.ReturnZ());
	}


	Matrix3 Matrix3::Transpose() const
	{
		return Matrix3(m_A11, m_A21, m_A31,
			m_A12, m_A22, m_A32,
			m_A13, m_A23, m_A33);
	}

	Matrix3 Matrix3::operator+(Matrix3 M1) const
	{
		return Matrix3(m_A11 + M1.m_A11, m_A12 + M1.m_A12, m_A13 + M1.m_A13,
			m_A21 + M1.m_A21, m_A22 + M1.m_A22, m_A23 + M1.m_A23,
			m_A31 + M1.m_A31, m_A32 + M1.m_A32, m_A33 + M1.m_A33);
	}

	Matrix3 Matrix3::operator-(Matrix3 M1) const
	{
		return Matrix3(m_A11 - M1.m_A11, m_A12 - M1.m_A12, m_A13 - M1.m_A13,
			m_A21 - M1.m_A21, m_A22 - M1.m_A22, m_A23 - M1.m_A23,
			m_A31 - M1.m_A31, m_A32 - M1.m_A32, m_A33 - M1.m_A33);
	}

	Matrix3 Matrix3::operator*(double x) const
	{
		return Matrix3(m_A11 * x, m_A12 * x, m_A13 * x,
			m_A21 * x, m_A22 * x, m_A23 * x,
			m_A31 * x, m_A32 * x, m_A33 * x);
	}

	Matrix3 Matrix3::operator*(Matrix3 M1) const
	{
		return Matrix3(Row(0) * M1.Column(0), Row(0) * M1.Column(1), Row(0) * M1.Column(2),
			Row(1) * M1.Column(0), Row(1) * M1.Column(1), Row(1) * M1.Column(2),
			Row(2) * M1.Column(0), Row(2) * M1.Column(1), Row(2) * M1.Column(2));
	}

	double Matrix3::Determinant() const
	{
		return m_A11 * m_A22 * m_A33 - m_A11 * m_A32 * m_A23 + m_A21 * m_A32 * m_A13 - m_A31 * m_A22 * m_A13 + m_A31 * m_A12 * m_A23 - m_A21 * m_A12 * m_A33;
	}

	Vector3D Matrix3::Row(int i) const
	{
		switch (i)
		{
		case 0:
			return Vector3D(m_A11, m_A12, m_A13);
		case 1:
			return Vector3D(m_A21, m_A22, m_A23);
		default:
			return Vector3D(m_A31, m_A32, m_A33);
		}
	}

	Vector3D Matrix3::Column(int i) const
	{
		switch (i)
		{
		case 0:
			return Vector3D(m_A11, m_A21, m_A31);
		case 1:
			return Vector3D(m_A12, m_A22, m_A32);
		default:
			return Vector3D(m_A13, m_A23, m_A33);
		}
	}

	Matrix3 Matrix3::Inverse() const
	{
		double det = Determinant();

		if (det == 0)
			return Matrix3();
		else
		{
			double scale = 1 / det;
			return Matrix3(scale * (m_A22 * m_A33 - m_A23 * m_A32),
				scale * (m_A13 * m_A32 - m_A12 * m_A33),
				scale * (m_A12 * m_A23 - m_A13 * m_A22),
				scale * (m_A23 * m_A31 - m_A21 * m_A33),
				scale * (m_A11 * m_A33 - m_A13 * m_A31),
				scale * (m_A13 * m_A21 - m_A11 * m_A23),
				scale * (m_A21 * m_A32 - m_A22 * m_A31),
				scale * (m_A12 * m_A31 - m_A11 * m_A32),
				scale * (m_A11 * m_A22 - m_A12 * m_A21));
		}
	}

	Matrix3 Matrix3::Rotation(int angle) const
	{
		double radians = PI / 180 * angle;
		return Matrix3(cos(radians), sin(radians), 0,
			sin(radians), cos(radians), 0,
			0, 0, 1);
	}

	Matrix3 Matrix3::Translate(float dx, float dy)
	{
		return Matrix3(1, 0, dx,
			0, 1, dy,
			0, 0, 1);
	}

	Matrix3 Matrix3::Scale(int dx, int dy) const
	{
		return Matrix3(dx / 100.0f, 0, 0,
			0, dy / 100.0f, 0,
			0, 0, 1);
	}

	Matrix3 Matrix3::operator-() const
	{
		int x = -1;
		return Matrix3(m_A11 * x, m_A12 * x, m_A13 * x,
			m_A21 * x, m_A22 * x, m_A23 * x,
			m_A31 * x, m_A32 * x, m_A33 * x);
	}

	Matrix3 Matrix3::RotationX(float angle)
	{
		double radians = PI / 180 * angle;
		return Matrix3(1, 0, 0,
			0, cos(radians), -sin(radians),
			0, sin(radians), cos(radians));
	}

	Matrix3 Matrix3::RotationY(float angle)
	{
		double radians = PI / 180 * angle;
		return Matrix3(cos(radians), 0, sin(radians),
			0, 1, 0,
			-sin(radians), 0, cos(radians));
	}

	Matrix3 Matrix3::RotationZ(float angle)
	{
		double radians = PI / 180 * angle;
		return Matrix3(cos(radians), -sin(radians), 0,
			sin(radians), cos(radians), 0,
			0, 0, 1);
	}

	Matrix3 Matrix3::Scale3D(int dx)
	{
		return Matrix3(dx / 100.0f, 0, 0,
			0, dx / 100.0f, 0,
			0, 0, dx / 100.0f);
	}
}