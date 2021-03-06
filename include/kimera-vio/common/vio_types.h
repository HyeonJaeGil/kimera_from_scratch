#pragma once

#include <cstdint>
#include <vector>
#include <memory>
#include <utility>
#include <gtsam/base/Matrix.h>
#include <gtsam/geometry/Point2.h>
#include <gtsam/geometry/Point3.h>
#include <opencv2/core.hpp>


namespace VIO {
using Timestamp = std::int64_t;

using Point2 = gtsam::Point2;
using Point3 = gtsam::Point3;
using Vector3 = gtsam::Vector3;
using Vector6 = gtsam::Vector6;
using Matrix3 = gtsam::Matrix33;
using Matrix6 = gtsam::Matrix66;
using Matrices3 =
    std::vector<gtsam::Matrix3, Eigen::aligned_allocator<gtsam::Matrix3>>;
using Vectors3 = std::vector<Vector3, Eigen::aligned_allocator<Vector3>>;

// float version
using Vector3f = Eigen::Matrix<float, 3, 1>;
using Vector6f = Eigen::Matrix<float, 6, 1>;
using Matrix3f = Eigen::Matrix<float, 3, 3>;
using Matrix6f = Eigen::Matrix<float, 6, 6>;
using Matrixf = Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic>;
using Matrices3f = std::vector<Matrix3f, Eigen::aligned_allocator<Matrix3f>>;
using Vectors3f = std::vector<Vector3f, Eigen::aligned_allocator<Vector3f>>;

enum class KeypointStatus {
  VALID,
  NO_LEFT_RECT,
  NO_RIGHT_RECT,
  NO_DEPTH,
  FAILED_ARUN
};

using Depth = double;
using Depths = std::vector<Depth>;

using DMatchVec = std::vector<cv::DMatch>;

using FrameId = std::uint64_t;  // Frame id is used as the index of gtsam symbol
                                // (not as a gtsam key).
using PlaneId = std::uint64_t;
using LandmarkId = long int;  // -1 for invalid landmarks. // int would be too
                            // small if it is 16 bits!
using LandmarkIds = std::vector<LandmarkId>;
using LandmarkCV = cv::Point3d;
using LandmarksCV = std::vector<LandmarkCV>;
enum class LandmarkType { SMART, PROJECTION };
using KeypointCV = cv::Point2f;
using KeypointsCV = std::vector<KeypointCV>;
using StatusKeypointCV = std::pair<KeypointStatus, KeypointCV>;
using StatusKeypointsCV = std::vector<StatusKeypointCV>;
using BearingVectors =
    std::vector<gtsam::Vector3, Eigen::aligned_allocator<gtsam::Vector3>>;

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}