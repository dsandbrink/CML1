## Configurable Math Library

CML1 is considered stable and closed for new features.

For the current CML development, please see https://github.com/demianmnave/CML.

## License

The Configurable Math Library (CML) is released under the [Boost Software
License, Version 1.0.](http://www.boost.org/LICENSE_1_0.txt).


## Using the CML

CML does not have a `make install` option.  As it is header-only, it is simple enough to copy the `cml` header directory into your project, and setup your build to reference it.


## Running Tests

To run the test suite from a command prompt using a Makefile-like generator, start in your build directory and execute:

`cmake <path-to-source> -DBUILD_TESTS=On`

Then, to build the tests (again from your build directory):

`cmake --build . --config Release`

You can run the full test suite from your build directory by executing:

`ctest`
