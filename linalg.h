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
 */

#ifndef LINALG_H_INCLUDED
#define LINALG_H_INCLUDED

#include <math.h>

#ifdef LINALG_SINGLE_PRECISION
typedef float real;
#else /* LINALG_SINGLE_PRECISION */
typedef double real;
#endif /* LINALG_SINGLE_PRECISION */

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
	real xx, xy;
	real yx, yy;
	real zx, zy;
} m32;

typedef struct {
	real xx, xy, xz;
	real yx, yy, yz;
} m23;

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
v2scale(v2 v, real s)
{
	return v2new(v.x * s, v.y * s);
}

static inline real
v2dot(v2 a, v2 b)
{
	return (a.x * b.x + a.y * b.y);
}

static inline real
v2lensq(v2 v)
{
	return (v2dot(v, v));
}

static inline real
v2len(v2 v)
{
	return ((real)sqrt((double)v2lensq(v)));
}

static inline v2
v2norm(v2 v)
{
	return (v2scale(v, (real)1.0 / v2len(v)));
}

static inline real
v2distsq(v2 a, v2 b)
{
	return (v2lensq(v2sub(a, b)));
}

static inline real
v2dist(v2 a, v2 b)
{
	return (v2len(v2sub(a, b)));
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
v3scale(v3 v, real s)
{
	return v3new(v.x * s, v.y * s, v.z * s);
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
	return (v3dot(v, v));
}

static inline real
v3len(v3 v)
{
	return ((real)sqrt((double)v3lensq(v)));
}

static inline v3
v3norm(v3 v)
{
	return (v3scale(v, (real)1.0 / v3len(v)));
}

static inline real
v3distsq(v3 a, v3 b)
{
	return (v3lensq(v3sub(a, b)));
}

static inline real
v3dist(v3 a, v3 b)
{
	return (v3len(v3sub(a, b)));
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
m22add(m22 a, m22 b)
{
	return m22new(a.xx + b.xx, a.xy + b.xy, a.yx + b.yx, a.yy + b.yy);
}

static inline m22
m22scale(m22 m, real s)
{
	return m22new(m.xx * s, m.xy * s, m.yx * s, m.yy * s);
}

static inline m22
m22trans(m22 m)
{
	return m22new(m.xx, m.yx, m.xy, m.yy);
}

static inline real
m22det(m22 m)
{
	return (m.xx * m.yy - m.xy * m.yx);
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
	m33 m = { xx, xy, xz,
		  yx, yy, yz,
		  zx, zy, zz };
	return (m);
}

static inline m33
m33zero(void)
{
	return m33new(0, 0, 0, 0, 0, 0, 0, 0, 0);
}

static inline m33
m33trans(m33 m)
{
	return m33new(m.xx, m.yx, m.zx, m.xy, m.yy, m.zy, m.xz, m.yz, m.zz);
}

static inline v2
m22v2(m22 m, v2 v)
{
	return v2new(m.xx * v.x + m.xy * v.y,
		     m.yx * v.x + m.yy * v.y);
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
		     m.zx * v.x + m.zx * v.y);
}

static inline v3
m33v3(m33 m, v3 v)
{
	return v3new(m.xx * v.x + m.xy * v.y + m.xz * v.z,
		     m.yx * v.x + m.yy * v.y + m.yz * v.z,
		     m.zx * v.x + m.zy * v.y + m.zz * v.z);
}

static inline m22
m22m22(m22 a, m22 b)
{
	return m22new(a.xx * b.xx + a.xy * b.yx,
		      a.xx * b.xy + a.xy * b.yy,
		      a.yx * b.xx + a.yy * b.yx,
		      a.yx * b.xy + a.yy * b.yy);
}

static inline m22
m23m32(m23 a, m32 b)
{
	return m22new(a.xx * b.xx + a.xy * b.yx + a.xz * b.zx,
		      a.xx * b.xy + a.xy * b.yy + a.xz * b.zy,
		      a.yx * b.xx + a.yy * b.yx + a.yz * b.zx,
		      a.yx * b.xx + a.yy * b.yx + a.yz * b.zx);
}

static inline m33
m32m23(m32 a, m23 b)
{
	return m33new(a.xx, b.xx, 0, 0, 0, 0, 0, 0, 0);
}

static inline m33
m33m33(m33 a, m33 b)
{
	return m33new(a.xx, b.xx, 0, 0, 0, 0, 0, 0, 0);
}

static inline real
m33det(m33 m)
{
	return (m.xx);
}

#endif /* LINALG_H_INCLUDED */
