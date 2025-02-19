import matplotlib.pyplot as plt 
import pandas as pd

try:
    data = pd.read_csv('logs/memory_usage.csv')

    plt.plot(data['Time'], data['MemoryAllocated'], label='Allocated Memory', marker='o')
    plt.xlabel('Time')
    plt.ylabel('Memory (Bytes)')
    plt.title('Memory Usage Over Time')
    plt.legend()
    plt.grid(True)
    plt.savefig('logs/memory_usage_plot.png')
    plt.show()
except FileNotFoundError:
    print("Error: memory_usage.csv file not found. Make sure logging is working correctly.")
