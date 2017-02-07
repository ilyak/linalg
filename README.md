linalg
======

Linalg is a collection of inline routines for operations on vectors,
matrices, and quaternions. It is implemented as a single header file using
portable C and has no dependencies. Both single precision (float) and double
precision (double) versions are available. To use, simply include linalg.h in
your source code. The code can be cleanly compiled as both C and C++.

List of types
-------------

- _real_ - single or double precision scalar value
- _v2_ - vector in 2d
- _v3_ - vector in 3d
- _m22_ - 2 by 2 matrix
- _m33_ - 3 by 3 matrix
- _q4_ - quaternion

List of functions
-----------------

- _v2new_
- _v2zero_
- _v2idx_
- _v2add_
- _v2sub_
- _v2neg_
- _v2mul_
- _v2div_
- _v2dot_
- _v2lensq_
- _v2len_
- _v2unit_
- _v2distsq_
- _v2dist_
- _v2eq_

- _v3new_
- _v3zero_
- _v3idx_
- _v3add_
- _v3sub_
- _v3neg_
- _v3mul_
- _v3div_
- _v3cross_
- _v3dot_
- _v3lensq_
- _v3len_
- _v3unit_
- _v3distsq_
- _v3dist_
- _v3eq_

- _m22new_
- _m22zero_
- _m22idx_
- _m22rowx_
- _m22rowy_
- _m22colx_
- _m22coly_
- _m22ident_
- _m22rot_
- _m22add_
- _m22sub_
- _m22neg_
- _m22mul_
- _m22div_
- _m22trans_
- _m22v2_
- _m22m22_
- _m22trace_
- _m22det_
- _m22inv_
- _m22solve_
- _m22eq_

- _m33new_
- _m33zero_
- _m33idx_
- _m33rowx_
- _m33rowy_
- _m33rowz_
- _m33colx_
- _m33coly_
- _m33colz_
- _m33ident_
- _m33rotx_
- _m33roty_
- _m33rotz_
- _m33add_
- _m33sub_
- _m33neg_
- _m33mul_
- _m33div_
- _m33trans_
- _m33v3_
- _m33m33_
- _m33trace_
- _m33det_
- _m33inv_
- _m33solve_
- _m33eq_

- _q4new_
- _q4zero_
- _q4idx_
- _q4add_
- _q4sub_
- _q4neg_
- _q4mul_
- _q4div_
- _q4conj_
- _q4q4_
- _q4normsq_
- _q4norm_
- _q4eq_

- _realeq_
