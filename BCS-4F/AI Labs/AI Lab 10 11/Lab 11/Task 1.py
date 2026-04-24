# Import libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler, LabelEncoder

df = pd.read_csv("/kaggle/input/mall-customer/Mall_Customers.csv")

df = df.drop("CustomerID", axis=1)

le = LabelEncoder()
df["Genre"] = le.fit_transform(df["Genre"])

# -------------------------------
#  PART 1: WITHOUT SCALING
# -------------------------------
X_no_scale = df.values

kmeans_no_scale = KMeans(n_clusters=5, random_state=42)
y_no_scale = kmeans_no_scale.fit_predict(X_no_scale)

print("Cluster centers WITHOUT scaling:")
print(kmeans_no_scale.cluster_centers_)

# -------------------------------
#  PART 2: WITH SCALING (EXCEPT AGE)
# -------------------------------

df_scaled = df.copy()

age_column = df_scaled["Age"]

features_to_scale = df_scaled.drop("Age", axis=1)

scaler = StandardScaler()
scaled_features = scaler.fit_transform(features_to_scale)

X_scaled = np.column_stack((age_column, scaled_features))

kmeans_scaled = KMeans(n_clusters=5, random_state=42)
y_scaled = kmeans_scaled.fit_predict(X_scaled)

print("\nCluster centers WITH scaling (Age not scaled):")
print(kmeans_scaled.cluster_centers_)