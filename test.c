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

/* If inline is defined as empty below, clang will warn about unused static
 * functions from linalg. This can be used to ensure 100% test coverage. */
#define inline
#include "linalg.h"

#ifdef LINALG_SINGLE_PRECISION
#define EPS ((real)1.0e-6)
#else
#define EPS ((real)1.0e-15)
#endif

static int
test01(void)
{
	v3 a, b;
	v2 c, d;

	a = v3new(1, 2, 3);
	b = v3new(3, 4, 5);
	c = v2new(3, 7);
	d = v2new(12, 28);

	if (!v3eq(v3add(a, b), v3new( 4,  6,  8), EPS)) return (1);
	if (!v3eq(v3sub(a, b), v3new(-2, -2, -2), EPS)) return (1);
	if (!v3eq(v3mul(a, -2), v3neg(v3add(a, a)), EPS)) return (1);
	if (!v3eq(v3sub(a, a), v3zero(), EPS)) return (1);
	if (!v2eq(v2add(d, v2mul(c, -4)), v2zero(), EPS)) return (1);
	if (!v2eq(v2sub(d, v2mul(c,  4)), v2zero(), EPS)) return (1);
	if (!v2eq(v2mul(c, -2), v2neg(v2add(c, c)), EPS)) return (1);
	if (!realeq(v2idx(c, 0), 3, EPS)) return (1);
	if (!realeq(v2idx(c, 1), 7, EPS)) return (1);

	return (0);
}

static int
test02(void)
{
	v3 a, b, c;
	v2 x, y;

	a = v3new(3, 0, -4);
	b = v3new(2, 7, 11);
	c = v3new(28, -41, 21);
	x = v2new(2, 3);
	y = v2new(6, -3);

	if (!v3eq(v3mul(a, 0.5), v3new(1.5, 0, -2), EPS)) return (1);
	if (!v3eq(v3cross(a, b), c, EPS)) return (1);
	if (!realeq(v3len(v3norm(b)), 1, EPS)) return (1);
	if (!realeq(v3len(a), 5, EPS)) return (1);
	if (!realeq(v3lensq(a), 25, EPS)) return (1);
	if (!realeq(v2dist(x, y), v2len(v2sub(x, y)), EPS)) return (1);
	if (!realeq(v2distsq(v2norm(x), v2zero()), 1, EPS)) return (1);

	return (0);
}

static int
test03(void)
{
	v3 a, b;

	a = v3new(2, 3, -4);
	b = v3new(2, 8, 8);

	if (!realeq(v3dist(a, b), 13, EPS)) return (1);
	if (!realeq(v3distsq(a, b), 169, EPS)) return (1);
	if (!realeq(v3idx(a, 0),  2, EPS)) return (1);
	if (!realeq(v3idx(a, 1),  3, EPS)) return (1);
	if (!realeq(v3idx(a, 2), -4, EPS)) return (1);

	return (0);
}

static int
test04(void)
{
	m22 a, b, c, d;

	a = m22new(-1, -2, -3, -4);
	b = m22new(2, 4, 6, 8);
	c = m22zero();
	d = m22new(0, -3, 3, 0);

	if (!m22eq(m22add(a, m22mul(b,  0.5)), c, EPS)) return (1);
	if (!m22eq(m22sub(a, m22mul(b, -0.5)), c, EPS)) return (1);
	if (!m22eq(m22trans(d), m22neg(d), EPS)) return (1);
	if (!m22eq(m22m22(b, m22inv(b)), m22ident(), EPS)) return (1);
	if (!m22eq(m22rot((real)M_PI), m22neg(m22ident()), EPS)) return (1);
	if (!realeq(m22det(a), -2, EPS)) return (1);
	if (!realeq(m22det(b), -8, EPS)) return (1);
	if (!realeq(m22det(c),  0, EPS)) return (1);
	if (!realeq(m22idx(a, 0, 0), -1, EPS)) return (1);
	if (!realeq(m22idx(a, 0, 1), -2, EPS)) return (1);
	if (!realeq(m22idx(a, 1, 0), -3, EPS)) return (1);
	if (!realeq(m22idx(a, 1, 1), -4, EPS)) return (1);

	return (0);
}

static int
test05(void)
{
	m33 a, b, c;

	a = m33new(1,2,3,4,5,6,7,8,9);
	b = m33new(14,32,50,32,77,122,50,122,194);
	c = m33new(30,36,42,66,81,96,102,126,150);

	if (!m33eq(m33m33(a, m33trans(a)), b, EPS)) return (1);
	if (!m33eq(m33m33(a, a), c, EPS)) return (1);
	if (!m33eq(m33add(a, a), m33mul(a, 2), EPS)) return (1);
	if (!m33eq(m33sub(a, a), m33zero(), EPS)) return (1);
	if (!realeq(m33det(c), 0, EPS)) return (1);
	if (!realeq(m33idx(a, 0, 0), 1, EPS)) return (1);
	if (!realeq(m33idx(a, 0, 1), 2, EPS)) return (1);
	if (!realeq(m33idx(a, 0, 2), 3, EPS)) return (1);
	if (!realeq(m33idx(a, 1, 0), 4, EPS)) return (1);
	if (!realeq(m33idx(a, 1, 1), 5, EPS)) return (1);
	if (!realeq(m33idx(a, 1, 2), 6, EPS)) return (1);
	if (!realeq(m33idx(a, 2, 0), 7, EPS)) return (1);
	if (!realeq(m33idx(a, 2, 1), 8, EPS)) return (1);
	if (!realeq(m33idx(a, 2, 2), 9, EPS)) return (1);

	return (0);
}

static int
test06(void)
{
	m22 a = m22new(1,2,3,4);
	v2 rx = m22rowx(a);
	v2 ry = m22rowy(a);
	v2 cx = m22colx(a);
	v2 cy = m22coly(a);

	if (!m22eq(a, m22new(rx.x, rx.y, ry.x, ry.y), EPS)) return (1);
	if (!m22eq(a, m22new(cx.x, cy.x, cx.y, cy.y), EPS)) return (1);

	return (0);
}

static int
test07(void)
{
	m22 a = m22new(1,2,3,4);
	m22 t = m22trans(a);
	v2 b = v2new(7,9);
	v2 x = m22solve(a, b);

	if (!v2eq(m22v2(a, x), b, EPS)) return (1);
	if (!m22eq(m22trans(m22m22(a, a)), m22m22(t, t), EPS)) return (1);

	return (0);
}

static int
test08(void)
{
	m33 a = m33new(4,2,3,7,8,9,1,5,6);
	v3 b = v3new(11,13,17);
	v3 x = m33solve(a, b);

	if (!v3eq(m33v3(a, x), b, EPS)) return (1);
	if (!v3eq(m33v3(m33neg(a), x), m33v3(a, v3neg(x)), EPS)) return (1);
	if (!m33eq(m33m33(a, m33inv(a)), m33ident(), EPS)) return (1);

	return (0);
}

static int
test09(void)
{
	return (0);
}

static int
test10(void)
{
	real ang3 = (real)M_PI / 3;
	m33 a = m33rotx(ang3);
	m33 b = m33roty(ang3);
	m33 c = m33rotz(ang3);
	m33 ex = m33new(1,0,0,0,-1,0,0,0,-1);
	m33 ey = m33new(-1,0,0,0,1,0,0,0,-1);
	m33 ez = m33new(-1,0,0,0,-1,0,0,0,1);

	if (!m33eq(m33m33(a, m33m33(a, a)), ex, EPS)) return (1);
	if (!m33eq(m33m33(b, m33m33(b, b)), ey, EPS)) return (1);
	if (!m33eq(m33m33(c, m33m33(c, c)), ez, EPS)) return (1);

	return (0);
}

int
main(void)
{
	if (test01()) return (1);
	if (test02()) return (1);
	if (test03()) return (1);
	if (test04()) return (1);
	if (test05()) return (1);
	if (test06()) return (1);
	if (test07()) return (1);
	if (test08()) return (1);
	if (test09()) return (1);
	if (test10()) return (1);

	return (0);
}
