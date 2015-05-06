# Release notes for Numexpr series #


## Changes from 2.2.1 to 2.2.2 ##

  * The `copy_args` argument of `NumExpr` function has been brought  lack.  This has been mainly necessary for compatibility with `PyTables < 3.0`, which I decided to continue to support.  Fixed #115.

  * The `__nonzero__` method in `ExpressionNode` class has been commented out.  This is also for compatibility with `PyTables < 3.0`.  See #24 for details.

  * Fixed the type of some parameters in the C extension so that s390 architecture compiles.  Fixes #116.  Thank to Antonio Valentino for reporting and the patch.


## Changes from 2.2 to 2.2.1 ##

  * Fixes a secondary effect of "from numpy.testing import `*`", where division is imported now too, so only then necessary functions from there are imported now.  Thanks to Christoph Gohlke for the patch.


## Changes from 2.1 to 2.2 ##

  * `[LICENSE]` Fixed a problem with the license of one of the  numexpr/win32/pthread.{c,h} files emulating pthreads on Windows   platforms.  After persmission from the original authors is granted,  these files adopt the MIT license and can be redistributed without   problems.  See [issue #109](https://code.google.com/p/numexpr/issues/detail?id=#109) for details  (https://code.google.com/p/numexpr/issues/detail?id=110).

  * `[ENH]` Improved the algorithm to decide the initial number of threads to be used.  This was necessary because by default, numexpr was using a number of threads equal to the detected number of cores, and   this can be just too much for moder systems where this number can be too high (and counterporductive for performance in many cases).  Now, the 'NUMEXPR\_NUM\_THREADS' environment variable is honored, and in case this is not present, a maximum number of **8** threads are setup initially.  The new algorithm is fully described in the Users Guide now in the note of 'General routines' section:  https://code.google.com/p/numexpr/wiki/UsersGuide#General_routines.   Closes #110.

  * `[ENH]` numexpr.test() returns `TestResult` instead of None now.  Closes #111.

  * `[FIX]` Modulus with zero with integers no longer crashes the  interpreter.  It nows puts a zero in the result.  Fixes #107.

  * `[API CLEAN]` Removed `copy_args` argument of `evaluate`.  This should only be used by old versions of PyTables (< 3.0).

  * `[DOC]` Documented the `optimization` and `truediv` flags of  `evaluate` in Users Guide  (https://code.google.com/p/numexpr/wiki/UsersGuide).


## Changes from 2.0.1 to 2.1 ##

  * New compatibility with Python 3:

  * switch from PyString to PyBytes API (requires Python >= 2.6).
  * fixed incompatibilities regarding the int/long API
  * use the Py\_TYPE macro
  * use the PyVarObject\_HEAD\_INIT macro instead of PyObject\_HEAD\_INIT

  * Dropped compatibility with Python < 2.6.

  * Fixed several issues with different platforms not supporting multithreading or subprocess properly (see tickets #75 and #77).

  * Now, when trying to use pure Python boolean operators, 'and', 'or' and 'not, an error is issued and suggesting that '&', '|' and  '~' should be used instead (fixes #24).


## Changes from 2.0 series to 2.0.1 ##

  * Added compatibility with Python 2.5 (2.4 is definitely not supported anymore).

  * `numexpr.evaluate` is fully documented now, in particular the new `out`, `order` and `casting` parameters.

  * Reduction operations are fully documented now.

  * Negative axis in reductions are not supported (they have never been actually), and a `ValueError` will be raised if they are used.


## Changes from 1.x series to 2.0 ##

  * Added support for the new iterator object in NumPy 1.6 and later.

> This allows for better performance with operations that implies broadcast operations, Fortran-ordered or non-native byte orderings. Performance for other scenarios is preserved (except for very small arrays).  See [NewVM](http://code.google.com/p/numexpr/wiki/NewVM) wiki page for details.

  * Division in numexpr is consistent now with Python/NumPy.  Fixes #22 and #58.

  * Constants like "2." or "2.0" must be evaluated as float, not integer.  Fixes #59.

  * `evaluate()` function has received a new parameter `out` for storing the result in already allocated arrays.  This is very useful when dealing with large arrays, and a allocating new space for keeping the result is not acceptable.  Closes #56.

  * Maximum number of threads raised from 256 to 4096.  Machines with a higher number of cores will still be able to import numexpr, but limited to 4096 (which is an absurdly high number already).



## Changes from 1.4.1 to 1.4.2 ##

  * Multithreaded operation is disabled for small arrays (< 32 KB).  This allows to remove the overhead of multithreading for such a small arrays.  Closes #36.

  * Dividing int arrays by zero gives a 0 as result now (and not a floating point exception anymore.  This behaviour mimics NumPy.  Thanks to Gaëtan de Menten for the fix.  Closes #37.

  * When compiled with VML support, the number of threads is set to 1 for VML core, and to the number of cores for the native pthreads implementation.  This leads to much better performance.  Closes #39.

  * Fixed different issues with reduction operations (`sum`, `prod`).  The problem is that the threaded code does not work well for broadcasting or reduction operations.  Now, the serial code is used in those cases.  Closes #41.

  * Optimization of "compilation phase" through a better hash.  This can lead up to a 25% of improvement when operating with variable expressions over small arrays.  Thanks to Gaëtan de Menten for the patch.  Closes #43.

  * The ```set_num_threads``` now returns the number of previous thread setting, as stated in the docstrings.


## Changes from 1.4 to 1.4.1 ##

  * Mingw32 can also work with pthreads compatibility code for win32.  Fixes #31.

  * Fixed a problem that used to happen when running Numexpr with threads in subprocesses.  It seems that threads needs to be initialized whenever a subprocess is created.  Fixes #33.

  * The GIL (Global Interpreter Lock) is released during computations. This should allow for better resource usage for multithreaded apps. Fixes #35.


## Changes from 1.3.1 to 1.4 ##

  * Added support for multi-threading in pure C.  This is to avoid the GIL and allows to squeeze the best performance in both multi-core machines.

  * David Cooke contributed a thorough refactorization of the opcode machinery for the virtual machine.  With this, it is really easy to add more opcodes.  See:

> http://code.google.com/p/numexpr/issues/detail?id=28

> as an example.

  * Added a couple of opcodes to VM: where\_bbbb and cast\_ib. The first allow to get boolean arrays out of the `where` function.  The second allows to cast a boolean array into an integer one.  Thanks to gdementen for his contribution.

  * Fix negation of `int64` numbers. Closes #25.

  * Using a `npy_intp` datatype (instead of plain `int`) so as to be able to manage arrays larger than 2 GB.


## Changes from 1.3 to 1.3.1 ##

  * When on AMD/Intel platforms, copies for unaligned arrays are disabled.  This is because AMD/Intel processors can deal very efficiently with unaligned data, so avoiding the copy is generally a good thing (up to 2x speed-ups wrt doing a copy can easily be seen).

> However, this optimization is not active when Numexpr is compiled with support for Intel VML (Vector Math Library).  The rational is that (surprisingly enough) Intel has not optimized the access to unaligned arrays on his VML, and hence the performance of its functions can drop a lot (as much as 10x in some cases).  Closes #21.

  * Due to an oversight, ```uint32``` types were not properly supported.  That has been solved.  Fixes #19.

  * Function `abs` for computing the absolute value added.  However, it does not strictly follow NumPy conventions. See:

> http://code.google.com/p/numexpr/wiki/Overview

> or the README.txt file for more info on this.  Thanks to Pauli Virtanen for the patch.  Closes #20.


## Changes from 1.2 to 1.3 ##

  * A new type called internally `float` has been implemented so as to be able to work natively with single-precision floating points.  This prevents the silent upcast to `double` types that was taking place in previous versions, so allowing both an improved performance and an optimal usage of memory for the single-precision computations.  However, the casting rules for floating point types slightly differs from those of NumPy.  See:

> http://code.google.com/p/numexpr/wiki/Overview

> or the README.txt file for more info on this issue.

  * Support for Python 2.6 added.

  * When linking with the MKL, added a '-rpath' option to the link step so that the paths to MKL libraries are automatically included into the runtime library search path of the final package (i.e. the user won't need to update its LD\_LIBRARY\_PATH or LD\_RUN\_PATH environment variables anymore).  Fixes #16.


## Changes from 1.1.1 to 1.2 ##

  * Support for Intel's VML (Vector Math Library) added, normally included in Intel's MKL (Math Kernel Library).  In addition, when the VML support is on, several processors can be used in parallel (see the new `set_vml_num_threads()` function).  With that, the computations of transcendental functions can be accelerated quite a few.  For example, typical speed-ups when using one single core for contiguous arrays are 3x with peaks of 7.5x (for the pow() function).  When using 2 cores the speed-ups are around 4x and 14x respectively.  Closes #9.

  * Some new VML-related functions have been added:

> - set\_vml\_accuracy\_mode(mode):  Set the accuracy for VML operations.

> - set\_vml\_num\_threads(nthreads): Suggests a maximum number of threads to be used in VML operations.

> - get\_vml\_version():  Get the VML/MKL library version.

> See the README.txt for more info about them.

  * In order to easily allow the detection of the MKL, the setup.py has been updated to use the numpy.distutils.  So, if you are already used to link NumPy/SciPy with MKL, then you will find that giving VML support to numexpr works almost the same.

  * A new `print_versions()` function has been made available.  This allows to quickly print the versions on which numexpr is based on.  Very handy for issue reporting purposes.

  * The `numexpr.numexpr` compiler function has been renamed to `numexpr.NumExpr` in order to avoid name collisions with the name of the package (!).  This function is mainly for internal use, so you should not need to upgrade your existing numexpr scripts.


## Changes from 1.1 to 1.1.1 ##

  * The case for multidimensional array operands is properly accelerated now.  Added a new benchmark (based on a script provided by Andrew Collette, thanks!) for easily testing this case in the future.  Closes #12.

  * Added a fix to avoid the caches in numexpr to grow too much.  The dictionary caches are kept now always with less than 256 entries.  Closes #11.

  * The VERSION file is correctly copied now (it was not present for the 1.1 tar file, I don't know exactly why).  Closes #8.


## Changes from 1.0 to 1.1 ##

  * Numexpr can work now in threaded environments.  Fixes #2.

  * The test suite can be run programmatically by using `numexpr.test()`.

  * Support a more complete set of functions for expressions (including those that are not supported by MSVC 7.1 compiler, like the inverse hyperbolic or log1p and expm1 functions).