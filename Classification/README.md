# Classification

- Dataset: A simple dataset of labeled samples is defined, with each sample having a feature vector and a corresponding class label.
- Euclidean Distance: A function to compute the Euclidean distance between two feature vectors is implemented.
- k-NN Classification: The classify_target function uses the k-Nearest Neighbors algorithm to classify the target based on the feature vector. It computes the distances from the target features to all samples in the dataset, sorts the distances, and finds the most common class among the k nearest neighbors.
- Example Usage: The main code demonstrates how to use the classify_target function to classify a target based on its features.

Created on 2019-08-10