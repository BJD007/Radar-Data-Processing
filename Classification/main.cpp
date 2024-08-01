#include "classification.hpp"
#include <iostream>
#include <vector>

int main() {
    // Example feature vector for a target
    vector<double> target_features = {2.5, 3.5, 4.5};

    // Classify the target
    string target_class = classify_target(target_features);

    // Print the classification result
    cout << "The target is classified as: " << target_class << endl;

    return 0;
}
