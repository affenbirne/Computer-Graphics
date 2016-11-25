#ifndef _HLSL_H_
#define _HLSL_H_

#include <math.h>

#ifdef min
#error min defined
#endif

#ifdef max
#error max defined
#endif

/******************************************************************************/
/*                                   Macros                                   */
/******************************************************************************/

#define HLSL_FORCE_INLINE			inline
#define HLSL_INLINE				inline

#define xx				__xx()
#define xy				__xy()
#define xz				__xz()
#define xw				__xw()
#define yx				__yx()
#define yy				__yy()
#define yz				__yz()
#define yw				__yw()
#define zx				__zx()
#define zy				__zy()
#define zz				__zz()
#define zw				__zw()
#define wx				__wx()
#define wy				__wy()
#define wz				__wz()
#define ww				__ww()

#define xxx				__xxx()
#define xxy				__xxy()
#define xxz				__xxz()
#define xxw				__xxw()
#define xyx				__xyx()
#define xyy				__xyy()
#define xyz				__xyz()
#define xyw				__xyw()
#define xzx				__xzx()
#define xzy				__xzy()
#define xzz				__xzz()
#define xzw				__xzw()
#define xwx				__xwx()
#define xwy				__xwy()
#define xwz				__xwz()
#define xww				__xww()
#define yxx				__yxx()
#define yxy				__yxy()
#define yxz				__yxz()
#define yxw				__yxw()
#define yyx				__yyx()
#define yyy				__yyy()
#define yyz				__yyz()
#define yyw				__yyw()
#define yzx				__yzx()
#define yzy				__yzy()
#define yzz				__yzz()
#define yzw				__yzw()
#define ywx				__ywx()
#define ywy				__ywy()
#define ywz				__ywz()
#define yww				__yww()
#define zxx				__zxx()
#define zxy				__zxy()
#define zxz				__zxz()
#define zxw				__zxw()
#define zyx				__zyx()
#define zyy				__zyy()
#define zyz				__zyz()
#define zyw				__zyw()
#define zzx				__zzx()
#define zzy				__zzy()
#define zzz				__zzz()
#define zzw				__zzw()
#define zwx				__zwx()
#define zwy				__zwy()
#define zwz				__zwz()
#define zww				__zww()
#define wxx				__wxx()
#define wxy				__wxy()
#define wxz				__wxz()
#define wxw				__wxw()
#define wyx				__wyx()
#define wyy				__wyy()
#define wyz				__wyz()
#define wyw				__wyw()
#define wzx				__wzx()
#define wzy				__wzy()
#define wzz				__wzz()
#define wzw				__wzw()
#define wwx				__wwx()
#define wwy				__wwy()
#define wwz				__wwz()
#define www				__www()

#define xxxx			__xxxx()
#define xxxy			__xxxy()
#define xxxz			__xxxz()
#define xxxw			__xxxw()
#define xxyx			__xxyx()
#define xxyy			__xxyy()
#define xxyz			__xxyz()
#define xxyw			__xxyw()
#define xxzx			__xxzx()
#define xxzy			__xxzy()
#define xxzz			__xxzz()
#define xxzw			__xxzw()
#define xxwx			__xxwx()
#define xxwy			__xxwy()
#define xxwz			__xxwz()
#define xxww			__xxww()
#define xyxx			__xyxx()
#define xyxy			__xyxy()
#define xyxz			__xyxz()
#define xyxw			__xyxw()
#define xyyx			__xyyx()
#define xyyy			__xyyy()
#define xyyz			__xyyz()
#define xyyw			__xyyw()
#define xyzx			__xyzx()
#define xyzy			__xyzy()
#define xyzz			__xyzz()
#define xyzw			__xyzw()
#define xywx			__xywx()
#define xywy			__xywy()
#define xywz			__xywz()
#define xyww			__xyww()
#define xzxx			__xzxx()
#define xzxy			__xzxy()
#define xzxz			__xzxz()
#define xzxw			__xzxw()
#define xzyx			__xzyx()
#define xzyy			__xzyy()
#define xzyz			__xzyz()
#define xzyw			__xzyw()
#define xzzx			__xzzx()
#define xzzy			__xzzy()
#define xzzz			__xzzz()
#define xzzw			__xzzw()
#define xzwx			__xzwx()
#define xzwy			__xzwy()
#define xzwz			__xzwz()
#define xzww			__xzww()
#define xwxx			__xwxx()
#define xwxy			__xwxy()
#define xwxz			__xwxz()
#define xwxw			__xwxw()
#define xwyx			__xwyx()
#define xwyy			__xwyy()
#define xwyz			__xwyz()
#define xwyw			__xwyw()
#define xwzx			__xwzx()
#define xwzy			__xwzy()
#define xwzz			__xwzz()
#define xwzw			__xwzw()
#define xwwx			__xwwx()
#define xwwy			__xwwy()
#define xwwz			__xwwz()
#define xwww			__xwww()
#define yxxx			__yxxx()
#define yxxy			__yxxy()
#define yxxz			__yxxz()
#define yxxw			__yxxw()
#define yxyx			__yxyx()
#define yxyy			__yxyy()
#define yxyz			__yxyz()
#define yxyw			__yxyw()
#define yxzx			__yxzx()
#define yxzy			__yxzy()
#define yxzz			__yxzz()
#define yxzw			__yxzw()
#define yxwx			__yxwx()
#define yxwy			__yxwy()
#define yxwz			__yxwz()
#define yxww			__yxww()
#define yyxx			__yyxx()
#define yyxy			__yyxy()
#define yyxz			__yyxz()
#define yyxw			__yyxw()
#define yyyx			__yyyx()
#define yyyy			__yyyy()
#define yyyz			__yyyz()
#define yyyw			__yyyw()
#define yyzx			__yyzx()
#define yyzy			__yyzy()
#define yyzz			__yyzz()
#define yyzw			__yyzw()
#define yywx			__yywx()
#define yywy			__yywy()
#define yywz			__yywz()
#define yyww			__yyww()
#define yzxx			__yzxx()
#define yzxy			__yzxy()
#define yzxz			__yzxz()
#define yzxw			__yzxw()
#define yzyx			__yzyx()
#define yzyy			__yzyy()
#define yzyz			__yzyz()
#define yzyw			__yzyw()
#define yzzx			__yzzx()
#define yzzy			__yzzy()
#define yzzz			__yzzz()
#define yzzw			__yzzw()
#define yzwx			__yzwx()
#define yzwy			__yzwy()
#define yzwz			__yzwz()
#define yzww			__yzww()
#define ywxx			__ywxx()
#define ywxy			__ywxy()
#define ywxz			__ywxz()
#define ywxw			__ywxw()
#define ywyx			__ywyx()
#define ywyy			__ywyy()
#define ywyz			__ywyz()
#define ywyw			__ywyw()
#define ywzx			__ywzx()
#define ywzy			__ywzy()
#define ywzz			__ywzz()
#define ywzw			__ywzw()
#define ywwx			__ywwx()
#define ywwy			__ywwy()
#define ywwz			__ywwz()
#define ywww			__ywww()
#define zxxx			__zxxx()
#define zxxy			__zxxy()
#define zxxz			__zxxz()
#define zxxw			__zxxw()
#define zxyx			__zxyx()
#define zxyy			__zxyy()
#define zxyz			__zxyz()
#define zxyw			__zxyw()
#define zxzx			__zxzx()
#define zxzy			__zxzy()
#define zxzz			__zxzz()
#define zxzw			__zxzw()
#define zxwx			__zxwx()
#define zxwy			__zxwy()
#define zxwz			__zxwz()
#define zxww			__zxww()
#define zyxx			__zyxx()
#define zyxy			__zyxy()
#define zyxz			__zyxz()
#define zyxw			__zyxw()
#define zyyx			__zyyx()
#define zyyy			__zyyy()
#define zyyz			__zyyz()
#define zyyw			__zyyw()
#define zyzx			__zyzx()
#define zyzy			__zyzy()
#define zyzz			__zyzz()
#define zyzw			__zyzw()
#define zywx			__zywx()
#define zywy			__zywy()
#define zywz			__zywz()
#define zyww			__zyww()
#define zzxx			__zzxx()
#define zzxy			__zzxy()
#define zzxz			__zzxz()
#define zzxw			__zzxw()
#define zzyx			__zzyx()
#define zzyy			__zzyy()
#define zzyz			__zzyz()
#define zzyw			__zzyw()
#define zzzx			__zzzx()
#define zzzy			__zzzy()
#define zzzz			__zzzz()
#define zzzw			__zzzw()
#define zzwx			__zzwx()
#define zzwy			__zzwy()
#define zzwz			__zzwz()
#define zzww			__zzww()
#define zwxx			__zwxx()
#define zwxy			__zwxy()
#define zwxz			__zwxz()
#define zwxw			__zwxw()
#define zwyx			__zwyx()
#define zwyy			__zwyy()
#define zwyz			__zwyz()
#define zwyw			__zwyw()
#define zwzx			__zwzx()
#define zwzy			__zwzy()
#define zwzz			__zwzz()
#define zwzw			__zwzw()
#define zwwx			__zwwx()
#define zwwy			__zwwy()
#define zwwz			__zwwz()
#define zwww			__zwww()
#define wxxx			__wxxx()
#define wxxy			__wxxy()
#define wxxz			__wxxz()
#define wxxw			__wxxw()
#define wxyx			__wxyx()
#define wxyy			__wxyy()
#define wxyz			__wxyz()
#define wxyw			__wxyw()
#define wxzx			__wxzx()
#define wxzy			__wxzy()
#define wxzz			__wxzz()
#define wxzw			__wxzw()
#define wxwx			__wxwx()
#define wxwy			__wxwy()
#define wxwz			__wxwz()
#define wxww			__wxww()
#define wyxx			__wyxx()
#define wyxy			__wyxy()
#define wyxz			__wyxz()
#define wyxw			__wyxw()
#define wyyx			__wyyx()
#define wyyy			__wyyy()
#define wyyz			__wyyz()
#define wyyw			__wyyw()
#define wyzx			__wyzx()
#define wyzy			__wyzy()
#define wyzz			__wyzz()
#define wyzw			__wyzw()
#define wywx			__wywx()
#define wywy			__wywy()
#define wywz			__wywz()
#define wyww			__wyww()
#define wzxx			__wzxx()
#define wzxy			__wzxy()
#define wzxz			__wzxz()
#define wzxw			__wzxw()
#define wzyx			__wzyx()
#define wzyy			__wzyy()
#define wzyz			__wzyz()
#define wzyw			__wzyw()
#define wzzx			__wzzx()
#define wzzy			__wzzy()
#define wzzz			__wzzz()
#define wzzw			__wzzw()
#define wzwx			__wzwx()
#define wzwy			__wzwy()
#define wzwz			__wzwz()
#define wzww			__wzww()
#define wwxx			__wwxx()
#define wwxy			__wwxy()
#define wwxz			__wwxz()
#define wwxw			__wwxw()
#define wwyx			__wwyx()
#define wwyy			__wwyy()
#define wwyz			__wwyz()
#define wwyw			__wwyw()
#define wwzx			__wwzx()
#define wwzy			__wwzy()
#define wwzz			__wwzz()
#define wwzw			__wwzw()
#define wwwx			__wwwx()
#define wwwy			__wwwy()
#define wwwz			__wwwz()
#define wwww			__wwww()


/******************************************************************************/
/*                                   Types                                    */
/******************************************************************************/

template <typename T, int N>
struct vector;

/* Comparison */

template <typename T, int N>
bool operator==(const vector<T, N> & a, const vector<T, N> & b) {
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}

	return true;
}

template <typename T, int N>
bool operator!=(const vector<T, N> & a, const vector<T, N> & b) {
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i]) {
			return true;
		}
	}

	return false;
}

template <typename T, int N>
vector<bool, N> operator>(const vector<T, N> & a, const vector<T, N> & b) {
	vector<bool, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a[i] > b[i];
	}
	return c;
}

template <typename T, int N>
vector<bool, N> operator>(const vector<T, N> & a, T b) {
	vector<bool, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a[i] > b;
	}
	return c;
}

/* Arithmetic */

/* unary + */

template <typename T, int N>
HLSL_FORCE_INLINE vector<T, N> operator+(const vector<T, N> & a) {
	return a;
}

/* unary - */

template <typename T, int N>
vector<T, N> operator-(const vector<T, N> & a) {
	vector<T, N> b;
	for (int i = 0; i < N; i++) {
		b[i] = -a[i];
	}
	return b;
}

/* binary + */

template <typename T, int N>
vector<T, N> operator+(const vector<T, N> & a, const vector<T, N> & b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a[i] + b[i];
	}
	return c;
}

template <typename T, int N>
vector<T, N> operator+(const vector<T, N> & a, T b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a[i] + b;
	}
	return c;
}

template <typename T, int N>
vector<T, N> operator+=(vector<T, N> & a, const vector<T, N> & b) {
	for (int i = 0; i < N; i++) {
		a[i] += b[i];
	}
	return a;
}

/* binary - */

template <typename T, int N>
vector<T, N> operator-(const vector<T, N> & a, const vector<T, N> & b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a[i] - b[i];
	}
	return c;
}

template <typename T, int N>
vector<T, N> operator-(const vector<T, N> & a, T b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a[i] - b;
	}
	return c;
}

template <typename T, int N>
vector<T, N> operator-=(vector<T, N> & a, const vector<T, N> & b) {
	for (int i = 0; i < N; i++) {
		a[i] -= b[i];
	}
	return a;
}

/* binary * */

template <typename T, int N>
vector<T, N> operator*(const vector<T, N> & a, const vector<T, N> & b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a[i] * b[i];
	}
	return c;
}

template <typename T, int N>
vector<T, N> operator*(T a, const vector<T, N> & b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a * b[i];
	}
	return c;
}

template <typename T, int N>
vector<T, N> operator*(const vector<T, N> & a, T b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a[i] * b;
	}
	return c;
}

template <typename T, int N>
inline vector<T, N> operator*=(vector<T, N> & a, const vector<T, N> & b) {
	for (int i = 0; i < N; i++) {
		a[i] *= b[i];
	}
	return a;
}

template <typename T, int N>
inline vector<T, N> operator*=(vector<T, N> & a, T b) {
	for (int i = 0; i < N; i++) {
		a[i] *= b;
	}
	return a;
}

/* binary / */

template <typename T, int N>
vector<T, N> operator/(const vector<T, N> & a, const vector<T, N> & b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a[i] / b[i];
	}
	return c;
}

template <typename T, int N>
vector<T, N> operator/(T a, const vector<T, N> & b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a / b[i];
	}
	return c;
}

template <typename T, int N>
vector<T, N> operator/(const vector<T, N> & a, T b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = a[i] / b;
	}
	return c;
}

template <typename T, int N>
inline vector<T, N> operator/=(vector<T, N> & a, const vector<T, N> & b) {
	for (int i = 0; i < N; i++) {
		a[i] /= b[i];
	}
	return a;
}

template <typename T, int N>
inline vector<T, N> operator/=(vector<T, N> & a, T b) {
	for (int i = 0; i < N; i++) {
		a[i] /= b;
	}
	return a;
}

/******************************************************************************/

template <typename T>
struct __vector_base {
	inline operator const T *() const {
		return (const T *) this;
	}

	inline operator T *() {
		return (T *) this;
	}
};

#define __READ_SWIZZLE2(a, b)		\
inline vector<T, 2> __##a##b() const {\
	return vector<T, 2>(a, b);\
}

#define __READ_SWIZZLE3(a, b, c)		\
inline vector<T, 3> __##a##b##c() const {\
	return vector<T, 3>(a, b, c);\
}

#define __READ_SWIZZLE4(a, b, c, d)		\
	inline vector<T, 3> __##a##b##c##d() const {\
	return vector<T, 4>(a, b, c, d);\
}

/******************************************************************************/

template <typename T>
struct vector<T, 2> : __vector_base<T> {
	vector() {
	}

	vector(T k) : x(k), y(k) {
	}

	vector(T x, T y) : x(x), y(y) {
	}

	__READ_SWIZZLE2(x, x)
	__READ_SWIZZLE2(x, y)
	__READ_SWIZZLE2(y, x)
	__READ_SWIZZLE2(y, y)

	__READ_SWIZZLE3(x, x, x)
	__READ_SWIZZLE3(x, x, y)
	__READ_SWIZZLE3(x, y, x)
	__READ_SWIZZLE3(x, y, y)
	__READ_SWIZZLE3(y, x, x)
	__READ_SWIZZLE3(y, x, y)
	__READ_SWIZZLE3(y, y, x)
	__READ_SWIZZLE3(y, y, y)

	__READ_SWIZZLE4(x, x, x, x)
	__READ_SWIZZLE4(x, x, x, y)
	__READ_SWIZZLE4(x, x, y, x)
	__READ_SWIZZLE4(x, x, y, y)
	__READ_SWIZZLE4(x, y, x, x)
	__READ_SWIZZLE4(x, y, x, y)
	__READ_SWIZZLE4(x, y, y, x)
	__READ_SWIZZLE4(x, y, y, y)
	__READ_SWIZZLE4(y, x, x, x)
	__READ_SWIZZLE4(y, x, x, y)
	__READ_SWIZZLE4(y, x, y, x)
	__READ_SWIZZLE4(y, x, y, y)
	__READ_SWIZZLE4(y, y, x, x)
	__READ_SWIZZLE4(y, y, x, y)
	__READ_SWIZZLE4(y, y, y, x)
	__READ_SWIZZLE4(y, y, y, y)

	T x, y;
};

/******************************************************************************/

template <typename T>
struct vector<T, 3> : __vector_base<T> {
	vector() {
	}

	vector(T k) : x(k), y(k), z(k) {
	}

	vector(T x, T y, T z) : x(x), y(y), z(z) {
	}

	__READ_SWIZZLE2(x, x)
	__READ_SWIZZLE2(x, y)
	__READ_SWIZZLE2(x, z)
	__READ_SWIZZLE2(y, x)
	__READ_SWIZZLE2(y, y)
	__READ_SWIZZLE2(y, z)
	__READ_SWIZZLE2(z, x)
	__READ_SWIZZLE2(z, y)
	__READ_SWIZZLE2(z, z)

	__READ_SWIZZLE3(x, x, x)
	__READ_SWIZZLE3(x, x, y)
	__READ_SWIZZLE3(x, x, z)
	__READ_SWIZZLE3(x, y, x)
	__READ_SWIZZLE3(x, y, y)
	__READ_SWIZZLE3(x, y, z)
	__READ_SWIZZLE3(x, z, x)
	__READ_SWIZZLE3(x, z, y)
	__READ_SWIZZLE3(x, z, z)
	__READ_SWIZZLE3(y, x, x)
	__READ_SWIZZLE3(y, x, y)
	__READ_SWIZZLE3(y, x, z)
	__READ_SWIZZLE3(y, y, x)
	__READ_SWIZZLE3(y, y, y)
	__READ_SWIZZLE3(y, y, z)
	__READ_SWIZZLE3(y, z, x)
	__READ_SWIZZLE3(y, z, y)
	__READ_SWIZZLE3(y, z, z)
	__READ_SWIZZLE3(z, x, x)
	__READ_SWIZZLE3(z, x, y)
	__READ_SWIZZLE3(z, x, z)
	__READ_SWIZZLE3(z, y, x)
	__READ_SWIZZLE3(z, y, y)
	__READ_SWIZZLE3(z, y, z)
	__READ_SWIZZLE3(z, z, x)
	__READ_SWIZZLE3(z, z, y)
	__READ_SWIZZLE3(z, z, z)

	__READ_SWIZZLE4(x, x, x, x)
	__READ_SWIZZLE4(x, x, x, y)
	__READ_SWIZZLE4(x, x, x, z)
	__READ_SWIZZLE4(x, x, y, x)
	__READ_SWIZZLE4(x, x, y, y)
	__READ_SWIZZLE4(x, x, y, z)
	__READ_SWIZZLE4(x, x, z, x)
	__READ_SWIZZLE4(x, x, z, y)
	__READ_SWIZZLE4(x, x, z, z)
	__READ_SWIZZLE4(x, y, x, x)
	__READ_SWIZZLE4(x, y, x, y)
	__READ_SWIZZLE4(x, y, x, z)
	__READ_SWIZZLE4(x, y, y, x)
	__READ_SWIZZLE4(x, y, y, y)
	__READ_SWIZZLE4(x, y, y, z)
	__READ_SWIZZLE4(x, y, z, x)
	__READ_SWIZZLE4(x, y, z, y)
	__READ_SWIZZLE4(x, y, z, z)
	__READ_SWIZZLE4(x, z, x, x)
	__READ_SWIZZLE4(x, z, x, y)
	__READ_SWIZZLE4(x, z, x, z)
	__READ_SWIZZLE4(x, z, y, x)
	__READ_SWIZZLE4(x, z, y, y)
	__READ_SWIZZLE4(x, z, y, z)
	__READ_SWIZZLE4(x, z, z, x)
	__READ_SWIZZLE4(x, z, z, y)
	__READ_SWIZZLE4(x, z, z, z)
	__READ_SWIZZLE4(y, x, x, x)
	__READ_SWIZZLE4(y, x, x, y)
	__READ_SWIZZLE4(y, x, x, z)
	__READ_SWIZZLE4(y, x, y, x)
	__READ_SWIZZLE4(y, x, y, y)
	__READ_SWIZZLE4(y, x, y, z)
	__READ_SWIZZLE4(y, x, z, x)
	__READ_SWIZZLE4(y, x, z, y)
	__READ_SWIZZLE4(y, x, z, z)
	__READ_SWIZZLE4(y, y, x, x)
	__READ_SWIZZLE4(y, y, x, y)
	__READ_SWIZZLE4(y, y, x, z)
	__READ_SWIZZLE4(y, y, y, x)
	__READ_SWIZZLE4(y, y, y, y)
	__READ_SWIZZLE4(y, y, y, z)
	__READ_SWIZZLE4(y, y, z, x)
	__READ_SWIZZLE4(y, y, z, y)
	__READ_SWIZZLE4(y, y, z, z)
	__READ_SWIZZLE4(y, z, x, x)
	__READ_SWIZZLE4(y, z, x, y)
	__READ_SWIZZLE4(y, z, x, z)
	__READ_SWIZZLE4(y, z, y, x)
	__READ_SWIZZLE4(y, z, y, y)
	__READ_SWIZZLE4(y, z, y, z)
	__READ_SWIZZLE4(y, z, z, x)
	__READ_SWIZZLE4(y, z, z, y)
	__READ_SWIZZLE4(y, z, z, z)
	__READ_SWIZZLE4(z, x, x, x)
	__READ_SWIZZLE4(z, x, x, y)
	__READ_SWIZZLE4(z, x, x, z)
	__READ_SWIZZLE4(z, x, y, x)
	__READ_SWIZZLE4(z, x, y, y)
	__READ_SWIZZLE4(z, x, y, z)
	__READ_SWIZZLE4(z, x, z, x)
	__READ_SWIZZLE4(z, x, z, y)
	__READ_SWIZZLE4(z, x, z, z)
	__READ_SWIZZLE4(z, y, x, x)
	__READ_SWIZZLE4(z, y, x, y)
	__READ_SWIZZLE4(z, y, x, z)
	__READ_SWIZZLE4(z, y, y, x)
	__READ_SWIZZLE4(z, y, y, y)
	__READ_SWIZZLE4(z, y, y, z)
	__READ_SWIZZLE4(z, y, z, x)
	__READ_SWIZZLE4(z, y, z, y)
	__READ_SWIZZLE4(z, y, z, z)
	__READ_SWIZZLE4(z, z, x, x)
	__READ_SWIZZLE4(z, z, x, y)
	__READ_SWIZZLE4(z, z, x, z)
	__READ_SWIZZLE4(z, z, y, x)
	__READ_SWIZZLE4(z, z, y, y)
	__READ_SWIZZLE4(z, z, y, z)
	__READ_SWIZZLE4(z, z, z, x)
	__READ_SWIZZLE4(z, z, z, y)
	__READ_SWIZZLE4(z, z, z, z)

	T x, y, z;
};

/******************************************************************************/

template <typename T>
struct vector<T, 4> : __vector_base<T> {
	vector() {
	}

	vector(T k) : x(k), y(k), z(k), w(k) {
	}

	vector(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {
	}

	__READ_SWIZZLE2(x, x)
	__READ_SWIZZLE2(x, y)
	__READ_SWIZZLE2(x, z)
	__READ_SWIZZLE2(x, w)
	__READ_SWIZZLE2(y, x)
	__READ_SWIZZLE2(y, y)
	__READ_SWIZZLE2(y, z)
	__READ_SWIZZLE2(y, w)
	__READ_SWIZZLE2(z, x)
	__READ_SWIZZLE2(z, y)
	__READ_SWIZZLE2(z, z)
	__READ_SWIZZLE2(z, w)
	__READ_SWIZZLE2(w, x)
	__READ_SWIZZLE2(w, y)
	__READ_SWIZZLE2(w, z)
	__READ_SWIZZLE2(w, w)

	__READ_SWIZZLE3(x, x, x)
	__READ_SWIZZLE3(x, x, y)
	__READ_SWIZZLE3(x, x, z)
	__READ_SWIZZLE3(x, x, w)
	__READ_SWIZZLE3(x, y, x)
	__READ_SWIZZLE3(x, y, y)
	__READ_SWIZZLE3(x, y, z)
	__READ_SWIZZLE3(x, y, w)
	__READ_SWIZZLE3(x, z, x)
	__READ_SWIZZLE3(x, z, y)
	__READ_SWIZZLE3(x, z, z)
	__READ_SWIZZLE3(x, z, w)
	__READ_SWIZZLE3(x, w, x)
	__READ_SWIZZLE3(x, w, y)
	__READ_SWIZZLE3(x, w, z)
	__READ_SWIZZLE3(x, w, w)
	__READ_SWIZZLE3(y, x, x)
	__READ_SWIZZLE3(y, x, y)
	__READ_SWIZZLE3(y, x, z)
	__READ_SWIZZLE3(y, x, w)
	__READ_SWIZZLE3(y, y, x)
	__READ_SWIZZLE3(y, y, y)
	__READ_SWIZZLE3(y, y, z)
	__READ_SWIZZLE3(y, y, w)
	__READ_SWIZZLE3(y, z, x)
	__READ_SWIZZLE3(y, z, y)
	__READ_SWIZZLE3(y, z, z)
	__READ_SWIZZLE3(y, z, w)
	__READ_SWIZZLE3(y, w, x)
	__READ_SWIZZLE3(y, w, y)
	__READ_SWIZZLE3(y, w, z)
	__READ_SWIZZLE3(y, w, w)
	__READ_SWIZZLE3(z, x, x)
	__READ_SWIZZLE3(z, x, y)
	__READ_SWIZZLE3(z, x, z)
	__READ_SWIZZLE3(z, x, w)
	__READ_SWIZZLE3(z, y, x)
	__READ_SWIZZLE3(z, y, y)
	__READ_SWIZZLE3(z, y, z)
	__READ_SWIZZLE3(z, y, w)
	__READ_SWIZZLE3(z, z, x)
	__READ_SWIZZLE3(z, z, y)
	__READ_SWIZZLE3(z, z, z)
	__READ_SWIZZLE3(z, z, w)
	__READ_SWIZZLE3(z, w, x)
	__READ_SWIZZLE3(z, w, y)
	__READ_SWIZZLE3(z, w, z)
	__READ_SWIZZLE3(z, w, w)
	__READ_SWIZZLE3(w, x, x)
	__READ_SWIZZLE3(w, x, y)
	__READ_SWIZZLE3(w, x, z)
	__READ_SWIZZLE3(w, x, w)
	__READ_SWIZZLE3(w, y, x)
	__READ_SWIZZLE3(w, y, y)
	__READ_SWIZZLE3(w, y, z)
	__READ_SWIZZLE3(w, y, w)
	__READ_SWIZZLE3(w, z, x)
	__READ_SWIZZLE3(w, z, y)
	__READ_SWIZZLE3(w, z, z)
	__READ_SWIZZLE3(w, z, w)
	__READ_SWIZZLE3(w, w, x)
	__READ_SWIZZLE3(w, w, y)
	__READ_SWIZZLE3(w, w, z)
	__READ_SWIZZLE3(w, w, w)

	__READ_SWIZZLE4(x, x, x, x)
	__READ_SWIZZLE4(x, x, x, y)
	__READ_SWIZZLE4(x, x, x, z)
	__READ_SWIZZLE4(x, x, x, w)
	__READ_SWIZZLE4(x, x, y, x)
	__READ_SWIZZLE4(x, x, y, y)
	__READ_SWIZZLE4(x, x, y, z)
	__READ_SWIZZLE4(x, x, y, w)
	__READ_SWIZZLE4(x, x, z, x)
	__READ_SWIZZLE4(x, x, z, y)
	__READ_SWIZZLE4(x, x, z, z)
	__READ_SWIZZLE4(x, x, z, w)
	__READ_SWIZZLE4(x, x, w, x)
	__READ_SWIZZLE4(x, x, w, y)
	__READ_SWIZZLE4(x, x, w, z)
	__READ_SWIZZLE4(x, x, w, w)
	__READ_SWIZZLE4(x, y, x, x)
	__READ_SWIZZLE4(x, y, x, y)
	__READ_SWIZZLE4(x, y, x, z)
	__READ_SWIZZLE4(x, y, x, w)
	__READ_SWIZZLE4(x, y, y, x)
	__READ_SWIZZLE4(x, y, y, y)
	__READ_SWIZZLE4(x, y, y, z)
	__READ_SWIZZLE4(x, y, y, w)
	__READ_SWIZZLE4(x, y, z, x)
	__READ_SWIZZLE4(x, y, z, y)
	__READ_SWIZZLE4(x, y, z, z)
	__READ_SWIZZLE4(x, y, z, w)
	__READ_SWIZZLE4(x, y, w, x)
	__READ_SWIZZLE4(x, y, w, y)
	__READ_SWIZZLE4(x, y, w, z)
	__READ_SWIZZLE4(x, y, w, w)
	__READ_SWIZZLE4(x, z, x, x)
	__READ_SWIZZLE4(x, z, x, y)
	__READ_SWIZZLE4(x, z, x, z)
	__READ_SWIZZLE4(x, z, x, w)
	__READ_SWIZZLE4(x, z, y, x)
	__READ_SWIZZLE4(x, z, y, y)
	__READ_SWIZZLE4(x, z, y, z)
	__READ_SWIZZLE4(x, z, y, w)
	__READ_SWIZZLE4(x, z, z, x)
	__READ_SWIZZLE4(x, z, z, y)
	__READ_SWIZZLE4(x, z, z, z)
	__READ_SWIZZLE4(x, z, z, w)
	__READ_SWIZZLE4(x, z, w, x)
	__READ_SWIZZLE4(x, z, w, y)
	__READ_SWIZZLE4(x, z, w, z)
	__READ_SWIZZLE4(x, z, w, w)
	__READ_SWIZZLE4(x, w, x, x)
	__READ_SWIZZLE4(x, w, x, y)
	__READ_SWIZZLE4(x, w, x, z)
	__READ_SWIZZLE4(x, w, x, w)
	__READ_SWIZZLE4(x, w, y, x)
	__READ_SWIZZLE4(x, w, y, y)
	__READ_SWIZZLE4(x, w, y, z)
	__READ_SWIZZLE4(x, w, y, w)
	__READ_SWIZZLE4(x, w, z, x)
	__READ_SWIZZLE4(x, w, z, y)
	__READ_SWIZZLE4(x, w, z, z)
	__READ_SWIZZLE4(x, w, z, w)
	__READ_SWIZZLE4(x, w, w, x)
	__READ_SWIZZLE4(x, w, w, y)
	__READ_SWIZZLE4(x, w, w, z)
	__READ_SWIZZLE4(x, w, w, w)
	__READ_SWIZZLE4(y, x, x, x)
	__READ_SWIZZLE4(y, x, x, y)
	__READ_SWIZZLE4(y, x, x, z)
	__READ_SWIZZLE4(y, x, x, w)
	__READ_SWIZZLE4(y, x, y, x)
	__READ_SWIZZLE4(y, x, y, y)
	__READ_SWIZZLE4(y, x, y, z)
	__READ_SWIZZLE4(y, x, y, w)
	__READ_SWIZZLE4(y, x, z, x)
	__READ_SWIZZLE4(y, x, z, y)
	__READ_SWIZZLE4(y, x, z, z)
	__READ_SWIZZLE4(y, x, z, w)
	__READ_SWIZZLE4(y, x, w, x)
	__READ_SWIZZLE4(y, x, w, y)
	__READ_SWIZZLE4(y, x, w, z)
	__READ_SWIZZLE4(y, x, w, w)
	__READ_SWIZZLE4(y, y, x, x)
	__READ_SWIZZLE4(y, y, x, y)
	__READ_SWIZZLE4(y, y, x, z)
	__READ_SWIZZLE4(y, y, x, w)
	__READ_SWIZZLE4(y, y, y, x)
	__READ_SWIZZLE4(y, y, y, y)
	__READ_SWIZZLE4(y, y, y, z)
	__READ_SWIZZLE4(y, y, y, w)
	__READ_SWIZZLE4(y, y, z, x)
	__READ_SWIZZLE4(y, y, z, y)
	__READ_SWIZZLE4(y, y, z, z)
	__READ_SWIZZLE4(y, y, z, w)
	__READ_SWIZZLE4(y, y, w, x)
	__READ_SWIZZLE4(y, y, w, y)
	__READ_SWIZZLE4(y, y, w, z)
	__READ_SWIZZLE4(y, y, w, w)
	__READ_SWIZZLE4(y, z, x, x)
	__READ_SWIZZLE4(y, z, x, y)
	__READ_SWIZZLE4(y, z, x, z)
	__READ_SWIZZLE4(y, z, x, w)
	__READ_SWIZZLE4(y, z, y, x)
	__READ_SWIZZLE4(y, z, y, y)
	__READ_SWIZZLE4(y, z, y, z)
	__READ_SWIZZLE4(y, z, y, w)
	__READ_SWIZZLE4(y, z, z, x)
	__READ_SWIZZLE4(y, z, z, y)
	__READ_SWIZZLE4(y, z, z, z)
	__READ_SWIZZLE4(y, z, z, w)
	__READ_SWIZZLE4(y, z, w, x)
	__READ_SWIZZLE4(y, z, w, y)
	__READ_SWIZZLE4(y, z, w, z)
	__READ_SWIZZLE4(y, z, w, w)
	__READ_SWIZZLE4(y, w, x, x)
	__READ_SWIZZLE4(y, w, x, y)
	__READ_SWIZZLE4(y, w, x, z)
	__READ_SWIZZLE4(y, w, x, w)
	__READ_SWIZZLE4(y, w, y, x)
	__READ_SWIZZLE4(y, w, y, y)
	__READ_SWIZZLE4(y, w, y, z)
	__READ_SWIZZLE4(y, w, y, w)
	__READ_SWIZZLE4(y, w, z, x)
	__READ_SWIZZLE4(y, w, z, y)
	__READ_SWIZZLE4(y, w, z, z)
	__READ_SWIZZLE4(y, w, z, w)
	__READ_SWIZZLE4(y, w, w, x)
	__READ_SWIZZLE4(y, w, w, y)
	__READ_SWIZZLE4(y, w, w, z)
	__READ_SWIZZLE4(y, w, w, w)
	__READ_SWIZZLE4(z, x, x, x)
	__READ_SWIZZLE4(z, x, x, y)
	__READ_SWIZZLE4(z, x, x, z)
	__READ_SWIZZLE4(z, x, x, w)
	__READ_SWIZZLE4(z, x, y, x)
	__READ_SWIZZLE4(z, x, y, y)
	__READ_SWIZZLE4(z, x, y, z)
	__READ_SWIZZLE4(z, x, y, w)
	__READ_SWIZZLE4(z, x, z, x)
	__READ_SWIZZLE4(z, x, z, y)
	__READ_SWIZZLE4(z, x, z, z)
	__READ_SWIZZLE4(z, x, z, w)
	__READ_SWIZZLE4(z, x, w, x)
	__READ_SWIZZLE4(z, x, w, y)
	__READ_SWIZZLE4(z, x, w, z)
	__READ_SWIZZLE4(z, x, w, w)
	__READ_SWIZZLE4(z, y, x, x)
	__READ_SWIZZLE4(z, y, x, y)
	__READ_SWIZZLE4(z, y, x, z)
	__READ_SWIZZLE4(z, y, x, w)
	__READ_SWIZZLE4(z, y, y, x)
	__READ_SWIZZLE4(z, y, y, y)
	__READ_SWIZZLE4(z, y, y, z)
	__READ_SWIZZLE4(z, y, y, w)
	__READ_SWIZZLE4(z, y, z, x)
	__READ_SWIZZLE4(z, y, z, y)
	__READ_SWIZZLE4(z, y, z, z)
	__READ_SWIZZLE4(z, y, z, w)
	__READ_SWIZZLE4(z, y, w, x)
	__READ_SWIZZLE4(z, y, w, y)
	__READ_SWIZZLE4(z, y, w, z)
	__READ_SWIZZLE4(z, y, w, w)
	__READ_SWIZZLE4(z, z, x, x)
	__READ_SWIZZLE4(z, z, x, y)
	__READ_SWIZZLE4(z, z, x, z)
	__READ_SWIZZLE4(z, z, x, w)
	__READ_SWIZZLE4(z, z, y, x)
	__READ_SWIZZLE4(z, z, y, y)
	__READ_SWIZZLE4(z, z, y, z)
	__READ_SWIZZLE4(z, z, y, w)
	__READ_SWIZZLE4(z, z, z, x)
	__READ_SWIZZLE4(z, z, z, y)
	__READ_SWIZZLE4(z, z, z, z)
	__READ_SWIZZLE4(z, z, z, w)
	__READ_SWIZZLE4(z, z, w, x)
	__READ_SWIZZLE4(z, z, w, y)
	__READ_SWIZZLE4(z, z, w, z)
	__READ_SWIZZLE4(z, z, w, w)
	__READ_SWIZZLE4(z, w, x, x)
	__READ_SWIZZLE4(z, w, x, y)
	__READ_SWIZZLE4(z, w, x, z)
	__READ_SWIZZLE4(z, w, x, w)
	__READ_SWIZZLE4(z, w, y, x)
	__READ_SWIZZLE4(z, w, y, y)
	__READ_SWIZZLE4(z, w, y, z)
	__READ_SWIZZLE4(z, w, y, w)
	__READ_SWIZZLE4(z, w, z, x)
	__READ_SWIZZLE4(z, w, z, y)
	__READ_SWIZZLE4(z, w, z, z)
	__READ_SWIZZLE4(z, w, z, w)
	__READ_SWIZZLE4(z, w, w, x)
	__READ_SWIZZLE4(z, w, w, y)
	__READ_SWIZZLE4(z, w, w, z)
	__READ_SWIZZLE4(z, w, w, w)
	__READ_SWIZZLE4(w, x, x, x)
	__READ_SWIZZLE4(w, x, x, y)
	__READ_SWIZZLE4(w, x, x, z)
	__READ_SWIZZLE4(w, x, x, w)
	__READ_SWIZZLE4(w, x, y, x)
	__READ_SWIZZLE4(w, x, y, y)
	__READ_SWIZZLE4(w, x, y, z)
	__READ_SWIZZLE4(w, x, y, w)
	__READ_SWIZZLE4(w, x, z, x)
	__READ_SWIZZLE4(w, x, z, y)
	__READ_SWIZZLE4(w, x, z, z)
	__READ_SWIZZLE4(w, x, z, w)
	__READ_SWIZZLE4(w, x, w, x)
	__READ_SWIZZLE4(w, x, w, y)
	__READ_SWIZZLE4(w, x, w, z)
	__READ_SWIZZLE4(w, x, w, w)
	__READ_SWIZZLE4(w, y, x, x)
	__READ_SWIZZLE4(w, y, x, y)
	__READ_SWIZZLE4(w, y, x, z)
	__READ_SWIZZLE4(w, y, x, w)
	__READ_SWIZZLE4(w, y, y, x)
	__READ_SWIZZLE4(w, y, y, y)
	__READ_SWIZZLE4(w, y, y, z)
	__READ_SWIZZLE4(w, y, y, w)
	__READ_SWIZZLE4(w, y, z, x)
	__READ_SWIZZLE4(w, y, z, y)
	__READ_SWIZZLE4(w, y, z, z)
	__READ_SWIZZLE4(w, y, z, w)
	__READ_SWIZZLE4(w, y, w, x)
	__READ_SWIZZLE4(w, y, w, y)
	__READ_SWIZZLE4(w, y, w, z)
	__READ_SWIZZLE4(w, y, w, w)
	__READ_SWIZZLE4(w, z, x, x)
	__READ_SWIZZLE4(w, z, x, y)
	__READ_SWIZZLE4(w, z, x, z)
	__READ_SWIZZLE4(w, z, x, w)
	__READ_SWIZZLE4(w, z, y, x)
	__READ_SWIZZLE4(w, z, y, y)
	__READ_SWIZZLE4(w, z, y, z)
	__READ_SWIZZLE4(w, z, y, w)
	__READ_SWIZZLE4(w, z, z, x)
	__READ_SWIZZLE4(w, z, z, y)
	__READ_SWIZZLE4(w, z, z, z)
	__READ_SWIZZLE4(w, z, z, w)
	__READ_SWIZZLE4(w, z, w, x)
	__READ_SWIZZLE4(w, z, w, y)
	__READ_SWIZZLE4(w, z, w, z)
	__READ_SWIZZLE4(w, z, w, w)
	__READ_SWIZZLE4(w, w, x, x)
	__READ_SWIZZLE4(w, w, x, y)
	__READ_SWIZZLE4(w, w, x, z)
	__READ_SWIZZLE4(w, w, x, w)
	__READ_SWIZZLE4(w, w, y, x)
	__READ_SWIZZLE4(w, w, y, y)
	__READ_SWIZZLE4(w, w, y, z)
	__READ_SWIZZLE4(w, w, y, w)
	__READ_SWIZZLE4(w, w, z, x)
	__READ_SWIZZLE4(w, w, z, y)
	__READ_SWIZZLE4(w, w, z, z)
	__READ_SWIZZLE4(w, w, z, w)
	__READ_SWIZZLE4(w, w, w, x)
	__READ_SWIZZLE4(w, w, w, y)
	__READ_SWIZZLE4(w, w, w, z)
	__READ_SWIZZLE4(w, w, w, w)

	T x, y, z, w;
};

#undef __READ_SWIZZLE2
#undef __READ_SWIZZLE3
#undef __READ_SWIZZLE4

/******************************************************************************/

template <typename T, int M, int N>
struct matrix;

template <typename T, int M, int N>
bool operator==(const matrix<T, M, N> & a, const matrix<T, M, N> & b) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}

	return true;
}

template <typename T, int M, int N>
bool operator!=(const matrix<T, M, N> & a, const matrix<T, M, N> & b) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] != b[i][j]) {
				return true;
			}
		}
	}

	return false;
}

template <typename T, int M, int N>
matrix<T, M, N> operator-(const matrix<T, M, N> & a, const matrix<T, M, N> & b) {
	matrix<T, M, N> c;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
	return c;
}

template <typename T, int M, int N>
matrix<T, M, N> operator*(const matrix<T, M, N> & a, const matrix<T, M, N> & b) {
	matrix<T, M, N> c;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = a[i][j] * b[i][j];
		}
	}
	return c;
}

template <typename T, int M, int N>
matrix<T, M, N> operator*(const matrix<T, M, N> & a, T b) {
	matrix<T, M, N> c;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = a[i][j] * b;
		}
	}
	return c;
}

template <typename T, int M, int N>
matrix<T, M, N> operator*(T a, const matrix<T, M, N> & b) {
	matrix<T, M, N> c;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = a * b[i][j];
		}
	}
	return c;
}

/******************************************************************************/

template <typename T, int M, int N>
struct __matrix_element {
	inline __matrix_element(matrix<T, M, N> & m, int i, int j) : m(m), i(i), j(j) {
	}

	inline __matrix_element & operator=(const T & t) {
		((T *) &m)[i + M * j] = t;
		return *this;
	}

	inline operator const T &() const {
		return ((const T *) &m)[i + M * j];
	}

	inline operator T &() {
		return ((T *) &m)[i + M * j];
	}

	matrix<T, M, N> & m;
	int i;
	int j;
};

/******************************************************************************/

template <typename T, int M, int N>
struct __matrix_row {
	inline __matrix_row(matrix<T, M, N> & m, int i) : m(m), i(i) {
	}

	inline const __matrix_element<T, M, N> operator[](int j) const {
		return __matrix_element<T, M, N>(m, i, j);
	}

	inline __matrix_element<T, M, N> operator[](int j) {
		return __matrix_element<T, M, N>(m, i, j);
	}

  /*
	inline operator vector<T, N>() const {
		vector<T, N> a;
		for (int j = 0; j < N; i++) {
			a[j] = m[i][j];
		}
		return a;
	}
  */

	matrix<T, M, N> & m;
	int i;
};

template <typename T, int M, int N>
bool operator==(const __matrix_row<T, M, N> & a, const vector<T, N> & b) {
	for (int j = 0; j < N; j++) {
		if (a[j] != b[j]) {
			return false;
		}
	}

	return true;
}

template <typename T, int M, int N>
bool operator!=(const __matrix_row<T, M, N> & a, const vector<T, N> & b) {
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i]) {
			return true;
		}
	}

	return false;
}

template <typename T, int M, int N>
bool operator==(const vector<T, N> & a, const __matrix_row<T, M, N> & b) {
	for (int j = 0; j < N; j++) {
		if (a[j] != b[j]) {
			return false;
		}
	}

	return true;
}

template <typename T, int M, int N>
bool operator!=(const vector<T, N> & a, const __matrix_row<T, M, N> & b) {
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i]) {
			return true;
		}
	}

	return false;
}

/******************************************************************************/

template <typename T, int M, int N>
struct __matrix_base {
	inline const __matrix_row<T, M, N> operator[](int i) const {
		return __matrix_row<T, M, N>(*(matrix<T, M, N> *) this, i);
	}

	inline __matrix_row<T, M, N> operator[](int i) {
		return __matrix_row<T, M, N>(*(matrix<T, M, N> *) this, i);
	}

	inline operator const T *() const {
		return (const T *) this;
	}

	inline operator T *() const {
		return (T *) this;
	}
};

/******************************************************************************/

template <typename T>
struct matrix<T, 2, 2> : __matrix_base<T, 2, 2> {
	matrix() {
	}

	matrix(T k) : 
		__00(k), __10(k), 
		__01(k), __11(k) {
	}

	matrix(T __00, T __01, T __10, T __11) : 
		__00(__00), __10(__10),
		__01(__01), __11(__11) {
	}

	T __00, __10, __01, __11;
};

/******************************************************************************/

template <typename T>
struct matrix<T, 2, 3> : __matrix_base<T, 2, 3> {
	matrix() {
	}

	matrix(T k) : 
		__00(k), __10(k), 
		__01(k), __11(k), 
		__02(k), __12(k) {
	}

	matrix(T __00, T __01, T __02, T __10, T __11, T __12) : 
		__00(__00), __10(__10), 
		__01(__01), __11(__11), 
		__02(__02), __12(__12) {
	}

	T __00, __10;
	T __01, __11;
	T __02, __12;
};

/******************************************************************************/

template <typename T>
struct matrix<T, 3, 2> : __matrix_base<T, 3, 2> {
	matrix() {
	}

	matrix(T k) : 
		__00(k), __10(k), __20(k), 
		__01(k), __11(k), __21(k) {
	}

	matrix(T __00, T __01, T __10, T __11, T __20, T __21) : 
		__00(__00), __10(__10), __20(__20), 
		__01(__01), __11(__11), __21(__21) {
	}

	T __00, __10, __20;
	T __01, __11, __21;
};

/******************************************************************************/

template <typename T>
struct matrix<T, 3, 3> : __matrix_base<T, 3, 3> {
	matrix() {
	}

	matrix(T k) : 
		__00(k), __10(k), __20(k), 
		__01(k), __11(k), __21(k), 
		__02(k), __12(k), __22(k) {
	}

	matrix(T __00, T __01, T __02, T __10, T __11, T __12, T __20, T __21, T __22) : 
		__00(__00), __10(__10), __20(__20), 
		__01(__01), __11(__11), __21(__21), 
		__02(__02), __12(__12), __22(__22) {
	}

	T __00, __10, __20;
	T __01, __11, __21;
	T __02, __12, __22;
};

/******************************************************************************/

template <typename T>
struct matrix<T, 4, 4> : __matrix_base<T, 4, 4> {
	matrix() {
	}

	matrix(T k) : 
		__00(k), __10(k), __20(k), __30(k), 
		__01(k), __11(k), __21(k), __31(k),
		__02(k), __12(k), __22(k), __32(k),
		__03(k), __13(k), __23(k), __33(k) {
	}

	matrix(T __00, T __01, T __02, T __03, T __10, T __11, T __12, T __13, T __20, T __21, T __22, T __23, T __30, T __31, T __32, T __33) : 
		__00(__00), __10(__10), __20(__20), __30(__30), 
		__01(__01), __11(__11), __21(__21), __31(__31), 
		__02(__02), __12(__12), __22(__22), __32(__32), 
		__03(__03), __13(__13), __23(__23), __33(__33) {
	}

	T __00, __10, __20, __30;
	T __01, __11, __21, __31;
	T __02, __12, __22, __32;
	T __03, __13, __23, __33;
};

/******************************************************************************/

//typedef unsigned __int32 uint;
typedef unsigned int uint;

// #define uint (unsigned int)

typedef vector<float, 2> float2;
typedef vector<float, 3> float3;
typedef vector<float, 4> float4;

typedef vector<int, 2> int2;
typedef vector<int, 3> int3;
typedef vector<int, 4> int4;

typedef vector<uint, 2> uint2;
typedef vector<uint, 3> uint3;
typedef vector<uint, 4> uint4;

typedef matrix<float, 2, 2> float2x2;
typedef matrix<float, 2, 3> float2x3;
typedef matrix<float, 2, 4> float2x4;

typedef matrix<float, 3, 2> float3x2;
typedef matrix<float, 3, 3> float3x3;
typedef matrix<float, 3, 4> float3x4;

typedef matrix<float, 4, 2> float4x2;
typedef matrix<float, 4, 3> float4x3;
typedef matrix<float, 4, 4> float4x4;

/******************************************************************************/
/*                                 Functions                                  */
/******************************************************************************/

template <typename T>
T abs(T x) {
	return x < (T) 0 ? -x : x;
}

template <typename T, int N>
vector<T, N> abs(const vector<T, N> & a) {
	vector<T, N> b;
	for (int i = 0; i < N; i++) {
		b[i] = abs(a[i]);
	}
	return b;
}

template <typename T, int N>
bool all(const vector<T, N> & a) {
	for (int i = 0; i < N; i++) {
		if (!a[i]) {
			return false;
		}
	}
	return true;
}

template <typename T, int N>
bool any(const vector<T, N> & a) {
	for (int i = 0; i < N; i++) {
		if (a[i]) {
			return true;
		}
	}
	return false;
}

template <typename T>
inline T clamp(T x, T a, T b) {
	return x < a ? a : x > b ? b : x;
}

template <typename T>
vector<T, 3> cross(const vector<T, 3> & a, const vector<T, 3> & b) {
	vector<T, 3> c;
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
	return c;
}

inline float degrees(float x) {
	return x * 57.295779513082320876798154814105f;
}

template <typename T>
T determinant(const matrix<T, 2, 2> & a) {
	return a.__00 * a.__11 - a.__01 * a.__10;
}

template <typename T>
T determinant(const matrix<T, 3, 3> & a) {
	return 
		a.__11 * (a.__00 * a.__22 - a.__20 * a.__02) + 
		a.__12 * (a.__01 * a.__20 - a.__21 * a.__00) + 
		a.__10 * (a.__02 * a.__21 - a.__22 * a.__00);
}

template <typename T>
T determinant(const matrix<T, 4, 4> & a) {
	return
		a.__00 * ((a.__22 * a.__33 * a.__11 + a.__32 * a.__13 * a.__21 + a.__12 * a.__23 * a.__31) - (a.__32 * a.__23 * a.__11 + a.__12 * a.__33 * a.__21 + a.__22 * a.__13 * a.__31)) + 
		a.__10 * ((a.__32 * a.__23 * a.__01 + a.__02 * a.__33 * a.__21 + a.__22 * a.__03 * a.__31) - (a.__22 * a.__33 * a.__01 + a.__32 * a.__03 * a.__21 + a.__02 * a.__23 * a.__31)) + 
		a.__20 * ((a.__12 * a.__33 * a.__01 + a.__32 * a.__03 * a.__11 + a.__02 * a.__13 * a.__31) - (a.__32 * a.__13 * a.__01 + a.__02 * a.__33 * a.__11 + a.__12 * a.__03 * a.__31)) + 
		a.__30 * ((a.__22 * a.__13 * a.__01 + a.__02 * a.__23 * a.__11 + a.__12 * a.__03 * a.__21) - (a.__12 * a.__23 * a.__01 + a.__22 * a.__03 * a.__11 + a.__02 * a.__13 * a.__21));
}

template <typename T, int N>
inline T distance(const vector<T, N> & a, const vector<T, N> & b) {
	return length(a - b);
}

template <typename T, int N>
T dot(const vector<T, N> & a, const vector<T, N> & b) {
	T d = (T) 0;
	for (int i = 0; i < N; i++) {
		d += a[i] * b[i];
	}
	return d;
}

template <typename T, int N>
T length(const vector<T, N> & a) {
	return sqrt(dot(a, a));
}

template <typename T>
T lerp(T a, T b, T t) {
#if 0
	// THIS IS FASTER
	return a + (b - a) * t;
#else
	// THIS IS MORE STABLE
	return a * ((T) 1 - t) + b * t;
#endif
}

template <typename T, int N>
vector<T, N> lerp(const vector<T, N> & a, const vector<T, N> & b, const vector<T, N> & t) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = lerp(a[i], b[i], t[i]);
	}
	return c;
}

template <typename T, int N>
vector<T, N> lerp(const vector<T, N> & a, const vector<T, N> & b, T t) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = lerp(a[i], b[i], t);
	}
	return c;
}

template <typename T>
inline T max(T a, T b) {
	return a > b ? a : b;
}

template <typename T, int N>
vector<T, N> max(const vector<T, N> & a, const vector<T, N> & b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = max(a[i], b[i]);
	}
	return c;
}

template <typename T>
inline T min(T a, T b) {
	return a < b ? a : b;
}

template <typename T, int N>
vector<T, N> min(const vector<T, N> & a, const vector<T, N> & b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = min(a[i], b[i]);
	}
	return c;
}

template <typename T, int M, int N, int O>
matrix<T, M, N> mul(const matrix<T, M, O> & a, const matrix<T, O, N> & b) {
	matrix<T, M, N> c;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = (T) 0;
			for (int k = 0; k < O; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

template <typename T, int M, int N>
vector<T, N> mul(const vector<T, M> & a, const matrix<T, M, N> & b) {
	vector<T, N> c;
	for (int j = 0; j < N; j++) {
		c[j] = (T) 0;
		for (int i = 0; i < M; i++) {
			c[j] += a[i] * b[i][j];
		}
	}
	return c;
}

template <typename T, int M, int N>
vector<T, M> mul(const matrix<T, M, N> & a, const vector<T, N> & b) {
	vector<T, N> c;
	for (int i = 0; i < M; i++) {
		c[i] = (T) 0;
		for (int j = 0; j < N; j++) {
			c[i] += a[i][j] * b[j];
		}
	}
	return c;
}

template <typename T, int N>
vector<T, N> normalize(const vector<T, N> & a) {
	return a / length(a);
}

template <typename T, int N>
vector<T, N> pow(const vector<T, N> & a, const vector<T, N> & b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = pow(a[i], b[i]);
	}
	return c;
}

template <typename T, int N>
vector<T, N> pow(const vector<T, N> & a, T b) {
	vector<T, N> c;
	for (int i = 0; i < N; i++) {
		c[i] = pow(a[i], b);
	}
	return c;
}

inline float radians(float x) {
	return x * 0.01745329251994329576923690768489f;
}

template <typename T, int M, int N>
matrix<T, N, M> transpose(const matrix<T, M, N> & a) {
	matrix<T, N, M> b;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			b[j][i] = a[i][j];
		}
	}
	return b;
}

template <typename T>
inline T saturate(T x) {
	return clamp(x, (T) 0, (T) 1);
}

#endif
