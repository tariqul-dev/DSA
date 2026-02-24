import numpy as np
import pandas as pd
import sklearn.datasets as ds
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

# pd.set_option('display.max_row', None)
# pd.set_option('display.max_column', None)

breast_cancer_ds = ds.load_breast_cancer()

breast_cancer_df = pd.DataFrame(breast_cancer_ds.data, columns=breast_cancer_ds.feature_names) 

X = breast_cancer_df
Y = breast_cancer_ds.target

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=3)

scaler = StandardScaler()

scaler.fit(X_train)
X_train_std = scaler.transform(X_train)
X_test_std = scaler.transform(X_test)

print(X_train_std.std())
print(X_test_std.std())