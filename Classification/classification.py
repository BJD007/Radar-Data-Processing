import numpy as np
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
import pandas as pd

class RadarTargetClassifier:
    def __init__(self, n_neighbors=5):
        self.scaler = StandardScaler()
        self.classifier = KNeighborsClassifier(n_neighbors=n_neighbors)

    def load_and_preprocess_data(self, file_path):
        # Load data from CSV file
        data = pd.read_csv(file_path)
        
        # Separate features and labels
        X = data.drop('label', axis=1).values
        y = data['label'].values

        # Split the data into training and testing sets
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

        # Scale the features
        X_train_scaled = self.scaler.fit_transform(X_train)
        X_test_scaled = self.scaler.transform(X_test)

        return X_train_scaled, X_test_scaled, y_train, y_test

    def train(self, X_train, y_train):
        self.classifier.fit(X_train, y_train)

    def predict(self, X):
        X_scaled = self.scaler.transform(X)
        return self.classifier.predict(X_scaled)

    def evaluate(self, X_test, y_test):
        X_test_scaled = self.scaler.transform(X_test)
        accuracy = self.classifier.score(X_test_scaled, y_test)
        return accuracy

def main():
    # Initialize the classifier
    classifier = RadarTargetClassifier(n_neighbors=3)

    # Load and preprocess data
    X_train, X_test, y_train, y_test = classifier.load_and_preprocess_data('radar_data.csv')

    # Train the classifier
    classifier.train(X_train, y_train)

    # Evaluate the classifier
    accuracy = classifier.evaluate(X_test, y_test)
    print(f"Classifier accuracy: {accuracy:.2f}")

    # Example: Classify a new target
    new_target = np.array([[10.5, 20.3, 15.7, 8.2]])  # Example features
    predicted_class = classifier.predict(new_target)
    print(f"Predicted class for new target: {predicted_class[0]}")

if __name__ == "__main__":
    main()
