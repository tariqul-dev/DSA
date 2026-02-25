# Methods to handle missing values
# 1. Imputation
# 2. Dropping

# Central Tendencies:
# 1. Mean
# 2. Median
# 3. Mode

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

random_df = pd.read_csv('./data/random_dataset.csv')

# print(random_df.head())

# print(random_df.isnull().sum())

# Analyze the distribution of data in the Peak column
# fig, ax = plt.subplots(figsize=(8, 8))
# sns.histplot(data=random_df.Peak)
# plt.show()

# Clean with median
random_df

# print(random_df.describe(include='all'))
# print(random_df.head())
# print(random_df.isna().sum())

random_df = random_df.drop(columns=['All Time Peak', 'Ref.', 'Peak'])
print(random_df.head())

fig, ax = plt.subplots(figsize=(8,8))
sns.histplot(data=random_df.Peak)
plt.show()