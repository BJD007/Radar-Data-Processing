import numpy as np
from filterpy.kalman import KalmanFilter

def initialize_tracker():
    tracker = KalmanFilter(dim_x=4, dim_z=2)
    tracker.F = np.array([[1, 0, 1, 0],
                          [0, 1, 0, 1],
                          [0, 0, 1, 0],
                          [0, 0, 0, 1]])
    tracker.H = np.array([[1, 0, 0, 0],
                          [0, 1, 0, 0]])
    tracker.R = np.eye(2) * 0.1
    tracker.Q = np.eye(4) * 0.1
    return tracker

def update_tracks(tracker, measurement):
    tracker.predict()
    tracker.update(measurement)
    return tracker.x
