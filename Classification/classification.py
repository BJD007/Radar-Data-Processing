from sklearn.ensemble import RandomForestClassifier

def classify_target(features):
    # Assuming a pre-trained model
    model = RandomForestClassifier()
    # model.load("pretrained_model.pkl")
    classes = ['car', 'bus', 'truck', 'cyclist', 'pedestrian']
    prediction = model.predict([features])[0]
    return classes[prediction]
