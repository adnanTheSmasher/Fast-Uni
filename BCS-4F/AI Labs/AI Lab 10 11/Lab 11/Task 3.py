import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler

data = {
    "student_id": [101, 102, 103, 104, 105, 106, 107, 108, 109, 110],
    "GPA": [3.8, 2.5, 3.2, 1.9, 3.5, 2.0, 3.9, 2.8, 3.0, 2.2],
    "study_hours": [25, 10, 18, 5, 22, 6, 28, 15, 17, 8],
    "attendance_rate": [95, 60, 80, 50, 90, 55, 98, 70, 75, 65]
}

df = pd.DataFrame(data)

features = df[["GPA", "study_hours", "attendance_rate"]]

scaler = StandardScaler()
X_scaled = scaler.fit_transform(features)

wcss = []

for k in range(2, 7):
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(X_scaled)
    wcss.append(kmeans.inertia_)

plt.plot(range(2, 7), wcss, marker="o")
plt.title("Elbow Method for Optimal K")
plt.xlabel("Number of Clusters (K)")
plt.ylabel("WCSS")
plt.show()


k_optimal = 3

kmeans = KMeans(n_clusters=k_optimal, random_state=42)
df["Cluster"] = kmeans.fit_predict(X_scaled)
print("\nFinal Student Clusters:")
print(df)

plt.figure()

for cluster in range(k_optimal):
    plt.scatter(
        df[df["Cluster"] == cluster]["study_hours"],
        df[df["Cluster"] == cluster]["GPA"],
        label=f"Cluster {cluster}"
    )

plt.title("Student Clusters (Study Hours vs GPA)")
plt.xlabel("Study Hours")
plt.ylabel("GPA")
plt.legend()
plt.show()