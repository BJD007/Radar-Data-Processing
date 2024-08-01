#include "classification.hpp"
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

// Example labeled dataset (features and corresponding classes)
struct LabeledSample {
    vector<double> features;
    string label;
};

// Example dataset
vector<LabeledSample> dataset = {
    {{1.0, 2.0, 3.0}, "car"},
    {{2.0, 3.0, 4.0}, "bus"},
    {{3.0, 4.0, 5.0}, "truck"},
    {{4.0, 5.0, 6.0}, "cyclist"},
    {{5.0, 6.0, 7.0}, "pedestrian"}
};

// Function to compute Euclidean distance between two feature vectors
double euclidean_distance(const vector<double>& a, const vector<double>& b) {
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

// k-NN classification function
string classify_target(const vector<double>& features) {
    int k = 3; // Number of nearest neighbors to consider
    vector<pair<double, string>> distances;

    // Compute distances from the target features to all samples in the dataset
    for (const auto& sample : dataset) {
        double distance = euclidean_distance(features, sample.features);
        distances.push_back(make_pair(distance, sample.label));
    }

    // Sort distances in ascending order
    sort(distances.begin(), distances.end());

    // Count the occurrences of each class in the k nearest neighbors
    vector<string> nearest_labels;
    for (int i = 0; i < k; ++i) {
        nearest_labels.push_back(distances[i].second);
    }

    // Find the most common class among the k nearest neighbors
    sort(nearest_labels.begin(), nearest_labels.end());
    string most_common_class = nearest_labels[0];
    int max_count = 1;
    int current_count = 1;
    for (size_t i = 1; i < nearest_labels.size(); ++i) {
        if (nearest_labels[i] == nearest_labels[i - 1]) {
            current_count++;
            if (current_count > max_count) {
                max_count = current_count;
                most_common_class = nearest_labels[i];
            }
        } else {
            current_count = 1;
        }
    }

    return most_common_class;
}
