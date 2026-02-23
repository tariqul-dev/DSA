import pandas as pd
from sklearn.datasets import fetch_california_housing

# housing = fetch_california_housing()
# housing_df = pd.DataFrame(housing.data, columns=housing.feature_names)
# print(housing_df.head())
# print()
# print(housing_df.shape)

boston_df = pd.read_csv('./boston.csv')

# print(type(boston_df))
# print(boston_df.info())
# print(boston_df.isnull().sum())

# print(boston_df.count())
# print(boston_df.mean())
# print(boston_df.std())
# print(boston_df.describe())