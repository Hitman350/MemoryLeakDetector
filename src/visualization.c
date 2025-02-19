#include <stdio.h>
#include <stdlib.h>
#include "visualization.h"

void generate_visualization() {
    FILE *data_file = fopen("logs/memory_usage.csv", "r");
    if (!data_file) {
        printf("Error: Could not open memory usage data for visualization.\n");
        return;
    }

    FILE *plot_script = fopen("logs/plot_memory_usage.py", "w");
    if (!plot_script) {
        printf("Error: Could not create plot script.\n");
        fclose(data_file);
        return;
    }

    fprintf(plot_script,
        "import matplotlib.pyplot as plt\n"
        "import pandas as pd\n\n"
        "data = pd.read_csv('logs/memory_usage.csv')\n"
        "plt.plot(data['Time'], data['MemoryAllocated'], label='Allocated Memory')\n"
        "plt.xlabel('Time')\n"
        "plt.ylabel('Memory (Bytes)')\n"
        "plt.title('Memory Usage Over Time')\n"
        "plt.legend()\n"
        "plt.savefig('logs/memory_usage_plot.png')\n"
        "plt.show()\n"
    );

    fclose(data_file);
    fclose(plot_script);

    system("python logs/plot_memory_usage.py");
}
