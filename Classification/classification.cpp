#include "classification.hpp"
#include <random>

string classify_target(const vector<double>& features) {
    // Placeholder for classification
    vector<string> classes = {"car", "bus", "truck", "cyclist", "pedestrian"};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, classes.size() - 1);
    return classes[dis(gen)];
}
