#ifndef PGMLINK_TRACK_FEATURES_H
#define PGMLINK_TRACK_FEATURES_H

#include <cassert>
#include <stdexcept>
#include <vector>
#include <armadillo>

#include "pgmlink/traxels.h"

namespace pgmlink {

class OutlierCalculator {
  public:
    OutlierCalculator() {};
    ~OutlierCalculator() {};
    virtual const std::vector<size_t>& calculate(const feature_arrays& features) = 0;
    virtual const feature_array& get_measures() const;
    virtual const std::string& name() const;
  protected:
    static const std::string name_;
    feature_array measures_;
}; // class OutlierCalculator

class MVNOutlierCalculator : public OutlierCalculator {
  public:
    MVNOutlierCalculator() {};
    ~MVNOutlierCalculator() {};
    const std::vector<size_t>& calculate(const feature_arrays& features);
    const feature_array& get_measures() const;
    const arma::Mat<feature_type>& get_covariance() const;
    const arma::Mat<feature_type>& get_inverse_covariance() const;
    const arma::Col<feature_type>& get_mean() const;
    virtual const std::string& name() const;

  protected:
    static const std::string name_;
    static const feature_type sigma_threshold_;
    feature_array measures_;
    std::vector<size_t> outlier_ids_;
    arma::Col<feature_type> mean_;
    arma::Mat<feature_type> covariance_;
    arma::Mat<feature_type> inv_covariance_;
}; // class MVNOutlierCalculator


class FeatureAggregator {
 public:
  FeatureAggregator() {};
  virtual ~FeatureAggregator() {};
  virtual feature_array vector_valued(const feature_arrays features);
  virtual feature_type scalar_valued(const feature_arrays features);
  virtual const std::string& name() const;

  static const std::string name_;
}; // Class FeatureAggregator

class OutlierBadnessAggregator : public FeatureAggregator {
 public:
  OutlierBadnessAggregator() {};
  ~OutlierBadnessAggregator() {};
  feature_array vector_valued(const feature_arrays features);
  feature_type scalar_valued(const feature_arrays features);
  virtual const std::string& name() const;
 protected:
  static const std::string name_;
  MVNOutlierCalculator mvn_outlier_calculator_;
}; // Class OutlierBadnessAggregator

} // Namespace pgmlink

#endif // PGMLINK_TRACK_FEATURES_H