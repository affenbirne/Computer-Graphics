#ifndef _HLSL_EX_H_
#define _HLSL_EX_H_

#include "HLSL.h"

/******************************************************************************/
/*                                   Types                                    */
/******************************************************************************/

typedef unsigned char uchar;
typedef unsigned short ushort;

/******************************************************************************/
/*                                   Macros                                   */
/******************************************************************************/

#define HLSL_EX_PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825f

/******************************************************************************/
/*                                 Functions                                  */
/******************************************************************************/

template <typename T, int M, int N>
const matrix<T, N, M> adjoint(const matrix<T, M, N> & a) {
	matrix<T, N, M> b;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int s = 1 - 2 * ((i ^ j) & 1);
			b[j][i] = (T) s * cofactor(a, i, j);
		}
	}
	return b;
}

template <typename T, int M, int N>
T cofactor(const matrix<T, M, N> & a, int i, int j) {
	matrix<T, M - 1, N - 1> b;

	for (int jj = 0; jj < j; jj++) {
		for (int ii = 0; ii < i; ii++) {
			b[ii][jj] = a[ii][jj];
		}
	}

	for (int jj = j + 1; jj < N; jj++) {
		for (int ii = 0; ii < i; ii++) {
			b[ii][jj - 1] = a[ii][jj];
		}
	}

	for (int jj = 0; jj < j; jj++) {
		for (int ii = i + 1; ii < M; ii++) {
			b[ii - 1][jj] = a[ii][jj];
		}
	}

	for (int jj = j + 1; jj < N; jj++) {
		for (int ii = i + 1; ii < M; ii++) {
			b[ii - 1][jj - 1] = a[ii][jj];
		}
	}

	return determinant(b);
}

template <typename T>
T cofactor(const matrix<T, 2, 2> & a, int i, int j) {
	return a[1 - i][1 - j];
}

template <typename T, int N>
inline T distance_sqr(const vector<T, N> & a, const vector<T, N> & b) {
	return length_sqr(a - b);
}

template <typename T>
matrix<T, 4, 4> frustum(T x0, T x1, T y0, T y1, T z0, T z1) {
	return matrix<T, 4, 4>(
		(T) 2 * z0 / (x1 - x0),                  (T) 0,                (T) 0, (T) 0, 
		                 (T) 0, (T) 2 * z0 / (y1 - y0),                (T) 0, (T) 0, 
		 (x0 + x1) / (x0 - x1),  (y0 + y1) / (y0 - y1),       z1 / (z1 - z0), (T) 1, 
		                 (T) 0,                  (T) 0, -z1 * z0 / (z1 - z0), (T) 0
	);
}

template <typename T, int M, int N>
const matrix<T, M, N> identity() {
	matrix<T, M, N> a;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = i == j ? (T) 1 : (T) 0;
		}
	}
	return a;
}

template <typename T, int N>
inline const matrix<T, N, N> invert(const matrix<T, N, N> & a) {
	return ((T) 1 / determinant(a)) * adjoint(a);
}

template <typename T, int N>
T length_sqr(const vector<T, N> & a) {
	return dot(a, a);
}

template <typename T>
matrix<T, 4, 4> perspective(T fovy, T aspect, T z0, T z1) {
	T y1 = z0 * tan(fovy / (T) 2);
	T y0 = -y1;
	T x1 = aspect * y1;
	T x0 = -x1;
	return frustum<T>(x0, x1, y0, y1, z0, z1);
}

template <typename T, int M, int N>
matrix<T, M, N> rotation_x(T angle) {
	T ca = cos(angle);
	T sa = sin(angle);

	matrix<T, M, N> a = identity<T, M, N>();
	a[1][1] = +ca;
	a[1][2] = +sa;
	a[2][1] = -sa;
	a[2][2] = +ca;
	return a;
}

template <typename T, int M, int N>
matrix<T, M, N> rotation_y(T angle) {
	T ca = cos(angle);
	T sa = sin(angle);

	matrix<T, M, N> a = identity<T, M, N>();
	a[0][0] = +ca;
	a[0][2] = -sa;
	a[2][0] = +sa;
	a[2][2] = +ca;
	return a;
}

template <typename T, int M, int N>
matrix<T, M, N> rotation_z(T angle) {
	T ca = cos(angle);
	T sa = sin(angle);

	matrix<T, M, N> a = identity<T, M, N>();
	a[0][0] = +ca;
	a[0][1] = +sa;
	a[1][0] = -sa;
	a[1][1] = +ca;
	return a;
}

template <typename T, int M, int N>
matrix<T, M, N> scale(const vector<T, 3> & s) {
	matrix<T, M, N> a = identity<T, M, N>();
	for (int i = 0; i < 3; i++) {
		a[i][i] = s[i];
	}
	return a;
}

template <typename T, int M, int N>
matrix<T, 4, 4> translation(const vector<T, 3> & t) {
	matrix<T, M, N> a = identity<T, M, N>();
	for (int j = 0; j < 3; j++) {
		a[3][j] = t[j];
	}
	return a;
}

#endif
