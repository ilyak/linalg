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

#include "linalg.h"

#define EPS ((real)1.0e-10)

static int
test01(void)
{
	v3 a, b;

	a = v3new(1, 2, 3);
	b = v3new(3, 4, 5);

	if (!v3eq(v3add(a, b), v3new( 4,  6,  8), EPS)) return (1);
	if (!v3eq(v3sub(a, b), v3new(-2, -2, -2), EPS)) return (1);

	return (0);
}

static int
test02(void)
{
	v3 a;

	a = v3new(3, 0, -4);

	if (!v3eq(v3scale(a, 0.5), v3new(1.5, 0, -2), EPS)) return (1);
	if (!realeq(v3len(a), 5, EPS)) return (1);
	if (!realeq(v3lensq(a), 25, EPS)) return (1);

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

	return (0);
}

static int
test04(void)
{
	m22 a, b, c;

	a = m22new(-1, -2, -3, -4);
	b = m22new(2, 4, 6, 8);
	c = m22zero();

	if (!m22eq(m22add(a, m22scale(b, 0.5)), c, EPS)) return (1);
	if (!realeq(m22det(a), -2, EPS)) return (1);
	if (!realeq(m22det(b), -8, EPS)) return (1);
	if (!realeq(m22det(c),  0, EPS)) return (1);

	return (0);
}

static int
test05(void)
{
	m33 a, b, c;

	a = b = m33new(1,2,3,4,5,6,7,8,9);
	c = m33new(30,36,42,66,81,96,102,126,150);

	if (!m33eq(m33m33(a, b), c, EPS)) return (1);
	if (!realeq(m33det(c), 0, EPS)) return (1);

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

	return (0);
}
