/*
 * Copyright (c) 2016 Ilya Kaliman
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Project: https://github.com/ilyak/linalg
 */

#ifndef LINALG_H_INCLUDED
#define LINALG_H_INCLUDED

#include <math.h>

#ifdef __cplusplus
namespace linalg {
#endif

#ifdef LINALG_SINGLE_PRECISION
typedef float real;
#else /* LINALG_SINGLE_PRECISION */
typedef double real;
#endif /* LINALG_SINGLE_PRECISION */

/* Do not pollute global namespace in C++ with preprocessor defines. */
#ifndef __cplusplus
#define v2idx(v, i) (((real *)&(v))[(i)])
#define v3idx(v, i) (((real *)&(v))[(i)])
#define m22idx(m, i, j) (((real *)&(m))[2*(i)+(j)])
#define m23idx(m, i, j) (((real *)&(m))[3*(i)+(j)])
#define m32idx(m, i, j) (((real *)&(m))[2*(i)+(j)])
#define m33idx(m, i, j) (((real *)&(m))[3*(i)+(j)])
#endif /* __cplusplus */

typedef struct {
	real x, y;
} v2;

typedef struct {
	real x, y, z;
} v3;

typedef struct {
	real xx, xy;
	real yx, yy;
} m22;

typedef struct {
	real xx, xy, xz;
	real yx, yy, yz;
} m23;

typedef struct {
	real xx, xy;
	real yx, yy;
	real zx, zy;
} m32;

typedef struct {
	real xx, xy, xz;
	real yx, yy, yz;
	real zx, zy, zz;
} m33;

static inline int
realeq(real a, real b, real eps)
{
	return (fabs((double)(a - b)) < (double)eps);
}

static inline v2
v2new(real x, real y)
{
	v2 v = { x, y };
	return (v);
}

static inline v2
v2zero(void)
{
	return v2new(0, 0);
}

static inline v2
v2add(v2 a, v2 b)
{
	return v2new(a.x + b.x, a.y + b.y);
}

static inline v2
v2sub(v2 a, v2 b)
{
	return v2new(a.x - b.x, a.y - b.y);
}

static inline v2
v2neg(v2 v)
{
	return v2new(-v.x, -v.y);
}

static inline v2
v2mul(v2 v, real s)
{
	return v2new(v.x * s, v.y * s);
}

static inline v2
v2div(v2 v, real s)
{
	return v2new(v.x / s, v.y / s);
}

static inline real
v2dot(v2 a, v2 b)
{
	return (a.x * b.x + a.y * b.y);
}

static inline real
v2lensq(v2 v)
{
	return v2dot(v, v);
}

static inline real
v2len(v2 v)
{
	return ((real)sqrt((double)v2lensq(v)));
}

static inline v2
v2norm(v2 v)
{
	return (v2div(v, v2len(v)));
}

static inline real
v2distsq(v2 a, v2 b)
{
	return v2lensq(v2sub(a, b));
}

static inline real
v2dist(v2 a, v2 b)
{
	return v2len(v2sub(a, b));
}

static inline int
v2eq(v2 a, v2 b, real eps)
{
	if (!realeq(a.x, b.x, eps)) return (0);
	if (!realeq(a.y, b.y, eps)) return (0);
	return (1);
}

static inline v3
v3new(real x, real y, real z)
{
	v3 v = { x, y, z };
	return (v);
}

static inline v3
v3zero(void)
{
	return v3new(0, 0, 0);
}

static inline v3
v3add(v3 a, v3 b)
{
	return v3new(a.x + b.x, a.y + b.y, a.z + b.z);
}

static inline v3
v3sub(v3 a, v3 b)
{
	return v3new(a.x - b.x, a.y - b.y, a.z - b.z);
}

static inline v3
v3neg(v3 v)
{
	return v3new(-v.x, -v.y, -v.z);
}

static inline v3
v3mul(v3 v, real s)
{
	return v3new(v.x * s, v.y * s, v.z * s);
}

static inline v3
v3div(v3 v, real s)
{
	return v3new(v.x / s, v.y / s, v.z / s);
}

static inline v3
v3cross(v3 a, v3 b)
{
	return v3new(a.y * b.z - a.z * b.y,
		     a.z * b.x - a.x * b.z,
		     a.x * b.y - a.y * b.x);
}

static inline real
v3dot(v3 a, v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

static inline real
v3lensq(v3 v)
{
	return v3dot(v, v);
}

static inline real
v3len(v3 v)
{
	return ((real)sqrt((double)v3lensq(v)));
}

static inline v3
v3norm(v3 v)
{
	return (v3div(v, v3len(v)));
}

static inline real
v3distsq(v3 a, v3 b)
{
	return v3lensq(v3sub(a, b));
}

static inline real
v3dist(v3 a, v3 b)
{
	return v3len(v3sub(a, b));
}

static inline int
v3eq(v3 a, v3 b, real eps)
{
	if (!realeq(a.x, b.x, eps)) return (0);
	if (!realeq(a.y, b.y, eps)) return (0);
	if (!realeq(a.z, b.z, eps)) return (0);
	return (1);
}

static inline m22
m22new(real xx, real xy, real yx, real yy)
{
	m22 m = { xx, xy, yx, yy };
	return (m);
}

static inline m22
m22zero(void)
{
	return m22new(0, 0, 0, 0);
}

static inline m22
m22ident(void)
{
	return m22new(1, 0, 0, 1);
}

static inline m22
m22add(m22 a, m22 b)
{
	return m22new(a.xx + b.xx, a.xy + b.xy, a.yx + b.yx, a.yy + b.yy);
}

static inline m22
m22sub(m22 a, m22 b)
{
	return m22new(a.xx - b.xx, a.xy - b.xy, a.yx - b.yx, a.yy - b.yy);
}

static inline m22
m22neg(m22 m)
{
	return m22new(-m.xx, -m.xy, -m.yx, -m.yy);
}

static inline m22
m22mul(m22 m, real s)
{
	return m22new(m.xx * s, m.xy * s, m.yx * s, m.yy * s);
}

static inline m22
m22div(m22 m, real s)
{
	return m22mul(m, (real)1.0 / s);
}

static inline m22
m22trans(m22 m)
{
	return m22new(m.xx, m.yx, m.xy, m.yy);
}

static inline v2
m22v2(m22 m, v2 v)
{
	return v2new(m.xx * v.x + m.xy * v.y,
		     m.yx * v.x + m.yy * v.y);
}

static inline m22
m22m22(m22 a, m22 b)
{
	return m22new(a.xx * b.xx + a.xy * b.yx,
		      a.xx * b.xy + a.xy * b.yy,
		      a.yx * b.xx + a.yy * b.yx,
		      a.yx * b.xy + a.yy * b.yy);
}

static inline real
m22det(m22 m)
{
	return (m.xx * m.yy - m.xy * m.yx);
}

static inline m22
m22inv(m22 m)
{
	m22 i = m22new(m.yy, -m.xy, -m.yx, m.xx);
	return m22div(i, m22det(m));
}

static inline v2
m22solve(m22 a, v2 b)
{
	return v2new((a.xy*b.y - a.yy*b.x) / (a.xy*a.yx - a.xx*a.yy),
		     (a.yx*b.x - a.xx*b.y) / (a.xy*a.yx - a.xx*a.yy));
}

static inline int
m22eq(m22 a, m22 b, real eps)
{
	if (!realeq(a.xx, b.xx, eps)) return (0);
	if (!realeq(a.xy, b.xy, eps)) return (0);
	if (!realeq(a.yx, b.yx, eps)) return (0);
	if (!realeq(a.yy, b.yy, eps)) return (0);
	return (1);
}

static inline m33
m33new(real xx, real xy, real xz,
       real yx, real yy, real yz,
       real zx, real zy, real zz)
{
	m33 m = { xx, xy, xz, yx, yy, yz, zx, zy, zz };
	return (m);
}

static inline m33
m33zero(void)
{
	return m33new(0, 0, 0, 0, 0, 0, 0, 0, 0);
}

static inline m33
m33ident(void)
{
	return m33new(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

static inline m33
m33add(m33 a, m33 b)
{
	return m33new(a.xx + b.xx, a.xy + b.xy, a.xz + b.xz,
		      a.yx + b.yx, a.yy + b.yy, a.yz + b.yz,
		      a.zx + b.zx, a.zy + b.zy, a.zz + b.zz);
}

static inline m33
m33sub(m33 a, m33 b)
{
	return m33new(a.xx - b.xx, a.xy - b.xy, a.xz - b.xz,
		      a.yx - b.yx, a.yy - b.yy, a.yz - b.yz,
		      a.zx - b.zx, a.zy - b.zy, a.zz - b.zz);
}

static inline m33
m33neg(m33 m)
{
	return m33new(-m.xx, -m.xy, -m.xz,
		      -m.yx, -m.yy, -m.yz,
		      -m.zx, -m.zy, -m.zz);
}

static inline m33
m33mul(m33 m, real s)
{
	return m33new(m.xx * s, m.xy * s, m.xz * s,
		      m.yx * s, m.yy * s, m.yz * s,
		      m.zx * s, m.zy * s, m.zz * s);
}

static inline m33
m33div(m33 m, real s)
{
	return m33mul(m, (real)1.0 / s);
}

static inline m33
m33trans(m33 m)
{
	return m33new(m.xx, m.yx, m.zx, m.xy, m.yy, m.zy, m.xz, m.yz, m.zz);
}

static inline v3
m33v3(m33 m, v3 v)
{
	return v3new(m.xx * v.x + m.xy * v.y + m.xz * v.z,
		     m.yx * v.x + m.yy * v.y + m.yz * v.z,
		     m.zx * v.x + m.zy * v.y + m.zz * v.z);
}

static inline m33
m33m33(m33 a, m33 b)
{
	return m33new(a.xx * b.xx + a.xy * b.yx + a.xz * b.zx,
		      a.xx * b.xy + a.xy * b.yy + a.xz * b.zy,
		      a.xx * b.xz + a.xy * b.yz + a.xz * b.zz,
		      a.yx * b.xx + a.yy * b.yx + a.yz * b.zx,
		      a.yx * b.xy + a.yy * b.yy + a.yz * b.zy,
		      a.yx * b.xz + a.yy * b.yz + a.yz * b.zz,
		      a.zx * b.xx + a.zy * b.yx + a.zz * b.zx,
		      a.zx * b.xy + a.zy * b.yy + a.zz * b.zy,
		      a.zx * b.xz + a.zy * b.yz + a.zz * b.zz);
}

static inline real
m33det(m33 m)
{
	return (m.xx * m.yy * m.zz + m.xy * m.yz * m.zx +
		m.yx * m.zy * m.xz - m.xz * m.yy * m.zx -
		m.xx * m.yz * m.zy - m.xy * m.yx * m.zz);
}

static inline m33
m33inv(m33 m)
{
	m33 i = m33new(m.yy * m.zz - m.yz * m.zy,
		       m.zy * m.xz - m.zz * m.xy,
		       m.xy * m.yz - m.xz * m.yy,
		       m.yz * m.zx - m.yx * m.zz,
		       m.zz * m.xx - m.zx * m.xz,
		       m.xz * m.yx - m.xx * m.yz,
		       m.yx * m.zy - m.yy * m.zx,
		       m.zx * m.xy - m.zy * m.xx,
		       m.xx * m.yy - m.xy * m.yx);
	return m33div(i, m33det(m));
}

static inline v3
m33solve(m33 a, v3 b)
{
	real d = m33det(a);
	real dx = m33det(m33new(b.x,a.xy,a.xz,b.y,a.yy,a.yz,b.z,a.zy,a.zz));
	real dy = m33det(m33new(a.xx,b.x,a.xz,a.yx,b.y,a.yz,a.zx,b.z,a.zz));
	real dz = m33det(m33new(a.xx,a.xy,b.x,a.yx,a.yy,b.y,a.zx,a.zy,b.z));
	return v3new(dx/d, dy/d, dz/d);
}

static inline int
m33eq(m33 a, m33 b, real eps)
{
	if (!realeq(a.xx, b.xx, eps)) return (0);
	if (!realeq(a.xy, b.xy, eps)) return (0);
	if (!realeq(a.xz, b.xz, eps)) return (0);
	if (!realeq(a.yx, b.yx, eps)) return (0);
	if (!realeq(a.yy, b.yy, eps)) return (0);
	if (!realeq(a.yz, b.yz, eps)) return (0);
	if (!realeq(a.zx, b.zx, eps)) return (0);
	if (!realeq(a.zy, b.zy, eps)) return (0);
	if (!realeq(a.zz, b.zz, eps)) return (0);
	return (1);
}

static inline m23
m23new(real xx, real xy, real xz, real yx, real yy, real yz)
{
	m23 m = { xx, xy, xz, yx, yy, yz };
	return (m);
}

static inline m32
m32new(real xx, real xy, real yx, real yy, real zx, real zy)
{
	m32 m = { xx, xy, yx, yy, zx, zy };
	return (m);
}

static inline m32
m23trans(m23 m)
{
	return m32new(m.xx, m.yx, m.xy, m.yy, m.xz, m.yz);
}

static inline m23
m32trans(m32 m)
{
	return m23new(m.xx, m.yx, m.zx, m.xy, m.yy, m.zy);
}

static inline v2
m23v3(m23 m, v3 v)
{
	return v2new(m.xx * v.x + m.xy * v.y + m.xz * v.z,
		     m.yx * v.x + m.yy * v.y + m.yz * v.z);
}

static inline v3
m32v2(m32 m, v2 v)
{
	return v3new(m.xx * v.x + m.xy * v.y,
		     m.yx * v.x + m.yy * v.y,
		     m.zx * v.x + m.zy * v.y);
}

static inline m22
m23m32(m23 a, m32 b)
{
	return m22new(a.xx * b.xx + a.xy * b.yx + a.xz * b.zx,
		      a.xx * b.xy + a.xy * b.yy + a.xz * b.zy,
		      a.yx * b.xx + a.yy * b.yx + a.yz * b.zx,
		      a.yx * b.xy + a.yy * b.yy + a.yz * b.zy);
}

static inline m33
m32m23(m32 a, m23 b)
{
	return m33new(a.xx * b.xx + a.xy * b.yx,
		      a.xx * b.xy + a.xy * b.yy,
		      a.xx * b.xz + a.xy * b.yz,
		      a.yx * b.xx + a.yy * b.yx,
		      a.yx * b.xy + a.yy * b.yy,
		      a.yx * b.xz + a.yy * b.yz,
		      a.zx * b.xx + a.zy * b.yx,
		      a.zx * b.xy + a.zy * b.yy,
		      a.zx * b.xz + a.zy * b.yz);
}

#ifdef __cplusplus
} /* namespace linalg */
#endif

#endif /* LINALG_H_INCLUDED */
