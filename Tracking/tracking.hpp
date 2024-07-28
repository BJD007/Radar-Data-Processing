#pragma once
#include <Eigen/Dense>

using namespace Eigen;

VectorXd initialize_tracker();
VectorXd update_tracks(MatrixXd& F, MatrixXd& H, MatrixXd& Q, MatrixXd& R, VectorXd& x, MatrixXd& P, const VectorXd& z);
