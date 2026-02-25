import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

tips = sns.load_dataset('tips')
print(tips)

plot = sns.relplot(
    data=tips,
    x = 'total_bill', 
    y='tip', 
    col='time', 
    hue='smoker', 
    style='smoker', 
    size='size'
)

plt.show()