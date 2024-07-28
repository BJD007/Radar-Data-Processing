#include "tracking.hpp"

VectorXd initialize_tracker() {
    return VectorXd::Zero(4);
}

VectorXd update_tracks(MatrixXd& F, MatrixXd& H, MatrixXd& Q, MatrixXd& R, VectorXd& x, MatrixXd& P, const VectorXd& z) {
    // Predict
    x = F * x;
    P = F * P * F.transpose() + Q;

    // Update
    VectorXd y = z - H * x;
    MatrixXd S = H * P * H.transpose() + R;
    MatrixXd K = P * H.transpose() * S.inverse();
    x = x + K * y;
    P = (MatrixXd::Identity(4, 4) - K * H) * P;

    return x;
}
