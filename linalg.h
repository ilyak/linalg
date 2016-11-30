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

#ifdef LINALG_SINGLE_PRECISION
typedef float real;
#else /* LINALG_SINGLE_PRECISION */
typedef double real;
#endif /* LINALG_SINGLE_PRECISION */

#define inline __inline__

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
	v2 c = { a.x + b.x, a.y + b.y };

	return (c);
}

static inline v2
v2sub(v2 a, v2 b)
{
	v2 c = { a.x - b.x, a.y - b.y };

	return (c);
}

static inline v2
v2neg(v2 v)
{
	v2 r = { -v.x, -v.y };

	return (r);
}

static inline v2
v2scale(v2 v, real s)
{
	v2 r = { v.x * s, v.y * s };

	return (r);
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
	return (v2dist(a, b) < eps);
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
	v3 c = { a.x + b.x, a.y + b.y, a.z + b.z };

	return (c);
}

static inline v3
v3sub(v3 a, v3 b)
{
	v3 c = { a.x - b.x, a.y - b.y, a.z - b.z };

	return (c);
}

static inline v3
v3neg(v3 v)
{
	v3 r = { -v.x, -v.y, -v.z };

	return (r);
}

static inline v3
v3scale(v3 v, real s)
{
	v3 r = { v.x * s, v.y * s, v.z * s };

	return (r);
}

static inline v3
v3cross(v3 a, v3 b)
{
	v3 r = { a.y * b.z - a.z * b.y,
		 a.z * b.x - a.x * b.z,
		 a.x * b.y - a.y * b.x };

	return (r);
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
	return (v3dist(a, b) < eps);
}

static inline v2
m22v2(m22 m, v2 v)
{
	v2 w = { m.xx * v.x + m.xy * v.y,
		 m.yx * v.x + m.yy * v.y };

	return (w);
}

static inline v2
m23v3(m23 m, v3 v)
{
	v2 w = { m.xx * v.x + m.xy * v.y + m.xz * v.z,
		 m.yx * v.x + m.yy * v.y + m.yz * v.z };

	return (w);
}

static inline v3
m32v2(m32 m, v2 v)
{
	v3 w = { m.xx * v.x + m.xy * v.y,
		 m.yx * v.x + m.yy * v.y,
		 m.zx * v.x + m.zx * v.y };

	return (w);
}

static inline v3
m33v3(m33 m, v3 v)
{
	v3 w = { m.xx * v.x + m.xy * v.y + m.xz * v.z,
		 m.yx * v.x + m.yy * v.y + m.yz * v.z,
		 m.zx * v.x + m.zy * v.y + m.zz * v.z };

	return (w);
}

#endif /* LINALG_H_INCLUDED */
