import pandas as pd
import numpy as np

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder, StandardScaler
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier, export_text
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
import kagglehub
import os

df = pd.read_csv("/kaggle/input/online-retail-customer-churn-dataset/online_retail_customer_churn.csv")
df.drop(columns=['Customer_ID'], inplace=True)

num_cols = df.select_dtypes(include=[np.number]).columns
for col in num_cols:
  df[col].fillna(df[col].median(), inplace=True)
cat_cols = df.select_dtypes(include=[object]).columns
for col in cat_cols:
  df[col].fillna(df[col].mode(), inplace=True)
print("\nMissing Values Handled")

for col in num_cols:
  Q1 = df[col].quantile(0.25)
  Q3 = df[col].quantile(0.75)
  IQR = Q3 - Q1
  lower_bound = Q1 - 1.5 * IQR
  upper_bound = Q3 + 1.5 * IQR

  df[col] = np.where(df[col] < lower_bound, lower_bound, df[col])
  df[col] = np.where(df[col] > upper_bound, upper_bound, df[col])
print("\nOutliers Handled")

le_dict = {}

for col in cat_cols:
  le = LabelEncoder()
  df[col] = le.fit_transform(df[col])
  le_dict[col] = le

print("\nCategorical variables encoded!")

target = 'Target_Churn'
X = df.drop(target, axis=1)
y = df[target]

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

X_train, X_test, y_train, y_test = train_test_split(
    X_scaled, y, test_size=0.2, random_state=42
)

svm_model = SVC(kernel='linear', random_state=42)
svm_model.fit(X_train, y_train)

print("\nSVM Model training completed!")

y_pred_svm = svm_model.predict(X_test)
accuracy_svm = accuracy_score(y_test, y_pred_svm)
print("\nSVM Model Evaluation:")
print("Accuracy:", accuracy_svm)

new_customer = pd.DataFrame({
    'Age': [30],
    'Gender': ['Male'],
    'Annual_Income': [60],
    'Total_Spend': [500],
    'Years_as_Customer': [3],
    'Num_of_Purchases': [20],
    'Average_Transaction_Amount': [25],
    'Num_of_Returns': [1],
    'Num_of_Support_Contacts': [2],
    'Satisfaction_Score': [4],
    'Last_Purchase_Days_Ago': [10],
    'Email_Opt_In': [True],
    'Promotion_Response': ['Responded']
})

for col in new_customer.columns:
  if col in le_dict:
    new_customer[col] = le_dict[col].transform(new_customer[col])

new_Scaled = scaler.transform(new_customer)

prediction_svm = svm_model.predict(new_Scaled)
print("\nNew Customer Prediction (1=High Value / 0=Low Value):", prediction_svm)
