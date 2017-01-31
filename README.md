linalg
======

Linalg is a collection of inline routines for operations on vectors,
matrices, and quaternions. It is implemented as a single header file using
portable C and has no dependencies. Both single precision (float) and double
precision (double) versions are available. To use, simply include linalg.h in
your source code. The code can be cleanly compiled as both C and C++.

List of types
-------------

real - single or double precision scalar value
v2 - vector in 2d
v3 - vector in 3d
m22 - 2 by 2 matrix
m33 - 3 by 3 matrix
q4 - quaternion

List of functions
-----------------

    v2new
    v2zero
    v2idx
    v2add
    v2sub
    v2neg
    v2mul
    v2div
    v2dot
    v2lensq
    v2len
    v2unit
    v2distsq
    v2dist
    v2eq

    v3new
    v3zero
    v3idx
    v3add
    v3sub
    v3neg
    v3mul
    v3div
    v3cross
    v3dot
    v3lensq
    v3len
    v3unit
    v3distsq
    v3dist
    v3eq

    m22new
    m22zero
    m22idx
    m22rowx
    m22rowy
    m22colx
    m22coly
    m22ident
    m22rot
    m22add
    m22sub
    m22neg
    m22mul
    m22div
    m22trans
    m22v2
    m22m22
    m22trace
    m22det
    m22inv
    m22solve
    m22eq

    m33new
    m33zero
    m33idx
    m33rowx
    m33rowy
    m33rowz
    m33colx
    m33coly
    m33colz
    m33ident
    m33rotx
    m33roty
    m33rotz
    m33add
    m33sub
    m33neg
    m33mul
    m33div
    m33trans
    m33v3
    m33m33
    m33trace
    m33det
    m33inv
    m33solve
    m33eq

    q4new
    q4zero
    q4idx
    q4add
    q4sub
    q4neg
    q4mul
    q4div
    q4conj
    q4q4
    q4normsq
    q4norm
    q4eq

    realeq
