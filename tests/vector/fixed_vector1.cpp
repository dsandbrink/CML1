/* -*- C++ -*- ------------------------------------------------------------
 @@COPYRIGHT@@
 *-----------------------------------------------------------------------*/
/** @file
 */

#include <iostream>
#include <cml/vector/fixed.h>

/* Testing headers: */
#define BOOST_TEST_MODULE fixed_vector1
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(fixed1)
{
  typedef cml::vector<double, cml::fixed<3>>	fixed3_type;
  double data[] = { 1., 2., 3. };
  fixed3_type v(data);
  BOOST_REQUIRE_EQUAL(v.size(), 3);
  BOOST_CHECK_EQUAL(v.data()[0], 1.);
  BOOST_CHECK_EQUAL(v[0], 1.);
}

BOOST_AUTO_TEST_CASE(write1)
{
  typedef cml::vector<double, cml::fixed<3>>	fixed3_type;
  fixed3_type v;
  BOOST_REQUIRE_EQUAL(v.size(), 3);
  v[0] = 1.;
  BOOST_CHECK_EQUAL(v.data()[0], 1.);
  BOOST_CHECK_EQUAL(v[0], 1.);
}

// -------------------------------------------------------------------------
// vim:ft=cpp:sw=2
