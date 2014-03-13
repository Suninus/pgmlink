#define BOOST_TEST_MODULE outlier_detection_test

#include <cmath>

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <boost/shared_ptr.hpp>

#include "pgmlink/track_features_auxiliary.h"

using namespace pgmlink;
using namespace boost;

BOOST_AUTO_TEST_CASE( TotalDiffAggregator_test ) {
  // Set up some test data
  feature_type setI_array[3][2] = {
    {0., 1.},
    {4., 8.},
    {2., 3.}
  };
  feature_arrays setI;
  for(size_t i = 0; i < 3; i++) {
    feature_array y(setI_array[i], setI_array[i]+2);
    setI.push_back(y);
  }
  feature_type setII_array[2][1] = {{0}, {2}};
  feature_arrays setII;
  for(size_t i = 0; i < 2; i++) {
    feature_array y(setII_array[i], setII_array[i]+1);
    setII.push_back(y);
  }

  TotalDiffAggregator totaldiff;
  feature_array vectorI = totaldiff.vector_valued(setI);
  feature_type scalarI = totaldiff.scalar_valued(setI);

  feature_array vectorII = totaldiff.vector_valued(setII);
  feature_type scalarII = totaldiff.scalar_valued(setII);

  feature_array vectorIref(2); vectorIref[0] = 2; vectorIref[1] = 2;
  feature_type scalarIref = 2 * sqrt(2);

  feature_array vectorIIref(1); vectorIIref[0] = 2;
  feature_type scalarIIref = 2;

  BOOST_CHECK_EQUAL(vectorIref[0], vectorI[0]);
  BOOST_CHECK_EQUAL(vectorIref[1], vectorI[1]);
  BOOST_CHECK_EQUAL(scalarIref, scalarI);
  
  BOOST_CHECK_EQUAL(vectorIIref[0], vectorII[0]);
  BOOST_CHECK_EQUAL(scalarIIref, scalarII);

}

BOOST_AUTO_TEST_CASE( MinAggregator_test ) {
  // Set up some test data
  feature_type setI_array[3][2] = {
    {0., 1.},
    {4., 8.},
    {2., 3.}
  };
  feature_arrays setI;
  for(size_t i = 0; i < 3; i++) {
    feature_array y(setI_array[i], setI_array[i]+2);
    setI.push_back(y);
  }
  feature_type setII_array[2][1] = {{0}, {2}};
  feature_arrays setII;
  for(size_t i = 0; i < 2; i++) {
    feature_array y(setII_array[i], setII_array[i]+1);
    setII.push_back(y);
  }

  MinAggregator min;
  feature_array vectorI = min.vector_valued(setI);
  feature_type scalarI = min.scalar_valued(setI);

  feature_array vectorII = min.vector_valued(setII);
  feature_type scalarII = min.scalar_valued(setII);

  feature_array vectorIref(2); vectorIref[0] = 0.; vectorIref[1] = 1.;
  feature_type scalarIref = 0.;

  feature_array vectorIIref(1); vectorIIref[0] = 0.;
  feature_type scalarIIref = 0.;

  BOOST_CHECK_EQUAL(vectorIref[0], vectorI[0]);
  BOOST_CHECK_EQUAL(vectorIref[1], vectorI[1]);
  BOOST_CHECK_EQUAL(scalarIref, scalarI);
  
  BOOST_CHECK_EQUAL(vectorIIref[0], vectorII[0]);
  BOOST_CHECK_EQUAL(scalarIIref, scalarII);

}

BOOST_AUTO_TEST_CASE( MaxAggregator_test ) {
  // Set up some test data
  feature_type setI_array[3][2] = {
    {0., 1.},
    {4., 8.},
    {2., 3.}
  };
  feature_arrays setI;
  for(size_t i = 0; i < 3; i++) {
    feature_array y(setI_array[i], setI_array[i]+2);
    setI.push_back(y);
  }
  feature_type setII_array[2][1] = {{0}, {2}};
  feature_arrays setII;
  for(size_t i = 0; i < 2; i++) {
    feature_array y(setII_array[i], setII_array[i]+1);
    setII.push_back(y);
  }

  MaxAggregator max;
  feature_array vectorI = max.vector_valued(setI);
  feature_type scalarI = max.scalar_valued(setI);

  feature_array vectorII = max.vector_valued(setII);
  feature_type scalarII = max.scalar_valued(setII);

  feature_array vectorIref(2); vectorIref[0] = 4.; vectorIref[1] = 8.;
  feature_type scalarIref = 8.;

  feature_array vectorIIref(1); vectorIIref[0] = 2.;
  feature_type scalarIIref = 2.;

  BOOST_CHECK_EQUAL(vectorIref[0], vectorI[0]);
  BOOST_CHECK_EQUAL(vectorIref[1], vectorI[1]);
  BOOST_CHECK_EQUAL(scalarIref, scalarI);
  
  BOOST_CHECK_EQUAL(vectorIIref[0], vectorII[0]);
  BOOST_CHECK_EQUAL(scalarIIref, scalarII);

}

BOOST_AUTO_TEST_CASE( MeanAggregator_test ) {
  // Set up some test data
  feature_type setI_array[3][2] = {
    {0., 1.},
    {4., 8.},
    {2., 3.}
  };
  feature_arrays setI;
  for(size_t i = 0; i < 3; i++) {
    feature_array y(setI_array[i], setI_array[i]+2);
    setI.push_back(y);
  }
  feature_type setII_array[2][1] = {{0}, {2}};
  feature_arrays setII;
  for(size_t i = 0; i < 2; i++) {
    feature_array y(setII_array[i], setII_array[i]+1);
    setII.push_back(y);
  }

  MeanAggregator mean;
  feature_array vectorI = mean.vector_valued(setI);
  feature_type scalarI = mean.scalar_valued(setI);

  feature_array vectorII = mean.vector_valued(setII);
  feature_type scalarII = mean.scalar_valued(setII);

  feature_array vectorIref(2); vectorIref[0] = 2.; vectorIref[1] = 4.;
  feature_type scalarIref = 3.;

  feature_array vectorIIref(1); vectorIIref[0] = 1.;
  feature_type scalarIIref = 1.;

  BOOST_CHECK_EQUAL(vectorIref[0], vectorI[0]);
  BOOST_CHECK_EQUAL(vectorIref[1], vectorI[1]);
  BOOST_CHECK_EQUAL(scalarIref, scalarI);
  
  BOOST_CHECK_EQUAL(vectorIIref[0], vectorII[0]);
  BOOST_CHECK_EQUAL(scalarIIref, scalarII);

}
