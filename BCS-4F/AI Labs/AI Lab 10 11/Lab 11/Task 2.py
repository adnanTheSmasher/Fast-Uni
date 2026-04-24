import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler, LabelEncoder

data = {
    'vehicle_serial_no': [5, 3, 8, 2, 4, 7, 6, 10, 1, 9],
    'mileage': [150000, 120000, 250000, 80000, 100000, 220000, 180000, 300000, 75000, 280000],
    'fuel_efficiency': [15, 18, 10, 22, 20, 12, 16, 8, 24, 9],
    'maintenance_cost': [5000, 4000, 7000, 2000, 3000, 6500, 5500, 8000, 1500, 7500],
    'vehicle_type': ['SUV', 'Sedan', 'Truck', 'Hatchback', 'Sedan', 'Truck', 'SUV', 'Truck', 'Hatchback', 'SUV']
}

df = pd.DataFrame(data)


df = df.drop("vehicle_serial_no", axis=1)


le = LabelEncoder()
df["vehicle_type"] = le.fit_transform(df["vehicle_type"])

# -----------------------------------
# PART 1: WITHOUT SCALING
# -----------------------------------
X_no_scale = df.values

kmeans_no_scale = KMeans(n_clusters=3, random_state=42)
y_no_scale = kmeans_no_scale.fit_predict(X_no_scale)

df["Cluster_No_Scale"] = y_no_scale

print("WITHOUT SCALING:")
print(df)

# -----------------------------------
#  PART 2: WITH SCALING
# (except vehicle_type)
# -----------------------------------

df_scaled = df.drop("Cluster_No_Scale", axis=1).copy()


vehicle_type_col = df_scaled["vehicle_type"]


features_to_scale = df_scaled.drop("vehicle_type", axis=1)

scaler = StandardScaler()
scaled_features = scaler.fit_transform(features_to_scale)


X_scaled = np.column_stack((scaled_features, vehicle_type_col))

kmeans_scaled = KMeans(n_clusters=3, random_state=42)
y_scaled = kmeans_scaled.fit_predict(X_scaled)

df["Cluster_Scaled"] = y_scaled

print("\nWITH SCALING:")
print(df)