import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('sineCSV.csv', header=None).T

x_time= df.index
y_ampl = df.values


plt.figure(figsize = (50, 5))
plt.plot(x_time, y_ampl)
plt.title('Generated Signal')
plt.xlabel('Time Index')
plt.ylabel('Amplitude')
plt.legend()
plt.grid(True)
plt.show()
