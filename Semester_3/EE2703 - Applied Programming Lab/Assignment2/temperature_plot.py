import csv
from datetime import datetime
import matplotlib.pyplot as plt


def load_temperature_data(filename):
    data = {}
    with open(filename, newline="", encoding="utf-8") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            city = row["City"]
            country = row["Country"]
            date = row["dt"][:7]  # YYYY-MM
            try:
                temp = float(row["AverageTemperature"])
            except (ValueError, TypeError):
                continue
            if city not in data:
                data[city] = {"country": country, "records": {}}
            data[city]["records"][date] = temp
    return data


def get_city_temperatures(data, city_name):
    """
    Get dictionary of monthly temperature records for a given city.
    """
    if city_name not in data:
        return False, {}
    return True, data[city_name]["records"]


def plot_city_temperature(data, city_name, save_path="madras_temperature_plot.png"):
    city_found, records = get_city_temperatures(data, city_name)
    if not city_found or not records:
        print(f"City '{city_name}' not found or no data available.")
        return
    dates = [datetime.strptime(date_str, "%Y-%m") for date_str in records.keys()]
    temps = list(records.values())
    dates, temps = zip(*sorted(zip(dates, temps)))

    # Plot
    plt.figure(figsize=(12, 6))
    plt.plot(dates, temps, label=f"{city_name} Temperature", color="tab:red")
    plt.xlabel("Year")
    plt.ylabel("Temperature (°C)")
    plt.title(f"Temperature Trends in {city_name}")
    plt.legend()
    plt.grid(True, linestyle="--", alpha=0.7)
    plt.savefig(save_path, dpi=300, bbox_inches="tight")
    print(f"Plot saved as {save_path}")

    plt.show()


if __name__ == "__main__":
    filename = "GlobalLandTemperaturesByMajorCity.csv"  # change if needed
    data = load_temperature_data(filename)
    plot_city_temperature(data, "Madras")
