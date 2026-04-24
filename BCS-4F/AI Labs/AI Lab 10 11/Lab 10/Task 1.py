import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score

df = pd.read_csv("/content/sample_data/california_housing_test.csv")

num_cols = df.select_dtypes(include=[np.number]).columns
for col in num_cols:
  df[col].fillna(df[col].median(), inplace=True)

print("\nMissing Values Handled....")



target = "median_house_value"
X = df.drop(target, axis=1)
y = df[target]
print("\nSelected Features:\n", X.columns)

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

print("\nData split into training and testing sets!")

model = RandomForestRegressor(n_estimators=100, random_state=42)
model.fit(X_train, y_train)

print("\nModel training completed!")

y_pred = model.predict(X_test)

mae = mean_absolute_error(y_test, y_pred)
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

print("\nModel Evaluation:")
print("Mean Absolute Error (MAE):", mae)
print("Mean Squared Error (MSE):", mse)
print("R2 Score:", r2)


importance = model.feature_importances_
features = X.columns

plt.figure(figsize=(8, 5))
plt.barh(features, importance)
plt.xlabel("Importance")
plt.title("Feature Importance")
plt.tight_layout()
plt.show()

new_house = pd.DataFrame({
    'longitude': [-122.23],
    'latitude': [37.88],
    'housing_median_age': [41],
    'total_rooms': [880],
    'total_bedrooms': [129],
    'population': [322],
    'households': [126],
    'median_income': [8.3252]
})

preedicted_price = model.predict(new_house)
print("\nPredicted Price for the New House:", preedicted_price[0])
