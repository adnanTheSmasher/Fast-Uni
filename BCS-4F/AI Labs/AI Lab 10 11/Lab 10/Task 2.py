import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

import kagglehub
import os

path = kagglehub.dataset_download("venky73/spam-mails-dataset")
df = pd.read_csv("/kaggle/input/spam-mails-dataset/spam_ham_dataset.csv")

df.drop(columns=['Unnamed: 0'], inplace=True)
df.dropna(inplace=True)

df['label_num'] = df['label_num'].astype(int)
print("Data cleaned Successfully")


vectorizer = TfidfVectorizer(stop_words='english',max_features=5000)
X = vectorizer.fit_transform(df['text'])
y = df['label_num']
print("\nText converted to numerical features!")

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

model = LogisticRegression(max_iter=1000)
model.fit(X_train, y_train)

print("\nModel training completed!")

y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)
print("\nModel Evaluation:")
print("Accuracy:", accuracy)

def predict_email(email_text):
  email_vector = vectorizer.transform([email_text])
  prediction = model.predict(email_vector)
  return "SPAM" if prediction == 1 else "NOT SPAM"

test_email = "Congratulations! You won a free lottery. Click here now!"
result = predict_email(test_email)

print("\nTest Email:", test_email)
print("Prediction:", result)