#include "linalg.h"

/* This tests C++ stuff. Most testing is done in test.c */

#ifdef LINALG_SINGLE_PRECISION
#define EPS ((real)1.0e-6)
#else
#define EPS ((real)1.0e-16)
#endif

using namespace linalg;

static bool
test01()
{
	m33 a = m33new(1,2,3,2,5,6,3,6,7);

	if (!m33eq(m33m33(a, m33trans(a)), m33m33(m33trans(a), a), EPS))
		return (true);

	return (false);
}

int
main()
{
	if (test01()) return (1);

	return (0);
}
