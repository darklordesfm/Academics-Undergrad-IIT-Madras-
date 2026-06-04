import csv
from collections import defaultdict


# Load data once
def load_temperature_data(filename):
    data = defaultdict(lambda: {"country": None, "records": {}})
    try:
        with open(filename, "r", encoding="utf-8") as file:
            reader = csv.DictReader(file)
            for row in reader:
                city = row["City"]
                country = row["Country"]
                date_str = row["dt"][:7]
                temp_str = row["AverageTemperature"]
                if temp_str and temp_str.strip():
                    try:
                        temp_val = float(temp_str)
                        data[city]["country"] = country
                        data[city]["records"][date_str] = temp_val
                    except ValueError:
                        continue
    except FileNotFoundError:
        return None
    return data


# The two functions below are given as useful examples to start with
def get_city_temperatures(data, city_name):
    """
    Extract temperature data for a specific city from CSV file.

    Parameters:
    filename (str): Path to the CSV file
    city_name (str): Name of the city to extract data for

    Returns:
    dict: Dictionary mapping 'YYYY-MM' to temperature (float)
          Returns empty dict if city not found
    """
    if city_name not in data:
        return False, {}
    return True, data[city_name]["records"]


def get_available_cities(data, limit=None):
    """
    Get list of unique cities in the dataset.

    Parameters:
    filename (str): Path to the CSV file
    limit (int): Maximum number of cities to return (None for all)

    Returns:
    list: List of unique city names
    """
    cities = sorted(list(data.keys()))
    return cities[:limit] if limit else cities


# =============================================================================
# ASSIGNMENT: Build a Temperature Data API
# =============================================================================
# Students should implement these 5 functions to create a complete API


def find_temperature_extremes(data, city_name):
    """
    Find the hottest and coldest months on record for a city.

    Parameters:
    filename (str): Path to the CSV file
    city_name (str): Name of the city

    Returns:
    dict: {
        'hottest': {'date': 'YYYY-MM', 'temperature': float},
        'coldest': {'date': 'YYYY-MM', 'temperature': float}
    }

    """
    city_found, temperature = get_city_temperatures(data, city_name)
    if not city_found:
        return {"error": f"City '{city_name}' not found."}
    if not temperature:
        return {}
    # Find Maximum and Minimum temperatures
    hottest = max(temperature, key=temperature.get)
    coldest = min(temperature, key=temperature.get)
    return {
        "hottest": {"month": hottest, "temperature": temperature[hottest]},
        "coldest": {"month": coldest, "temperature": temperature[coldest]},
    }


def get_seasonal_averages(data, city_name, season):
    """
    Calculate average temperature for a specific season across all years.
    Never mind that Chennai only has Hot, Hotter and Hottest...

    Parameters:
    filename (str): Path to the CSV file
    city_name (str): Name of the city
    season (str): 'spring', 'summer', 'fall', or 'winter'

    Returns:
    dict: {
        'city': str,
        'season': str,
        'average_temperature': float
    }

    Assume: Spring = Mar,Apr,May; Summer = Jun,Jul,Aug;
          Fall = Sep,Oct,Nov; Winter = Dec,Jan,Feb
    """
    city_found, temperature = get_city_temperatures(data, city_name)
    if not city_found:
        return {"error": f"City '{city_name}' not found."}
    if not temperature:
        return {}
    # Seperate seasons
    month_season = {
        "spring": [3, 4, 5],
        "summer": [6, 7, 8],
        "fall": [9, 10, 11],
        "winter": [12, 1, 2],
    }
    seasonal_temperatures = []
    # Segregate the temperature according to seasons
    for month, temp in temperature.items():
        month_number = int(month[5:7])
        if month_number in month_season[season.lower()]:
            seasonal_temperatures.append(temp)
    if not seasonal_temperatures:
        return {}
    # Seasonal Average
    avg_temp = sum(seasonal_temperatures) / len(seasonal_temperatures)
    return {"city": city_name, "season": season, "average_temperature": avg_temp}


def compare_decades(data, city_name, decade1, decade2):
    """
    Compare average temperatures between two decades for a city.

    Parameters:
    filename (str): Path to the CSV file
    city_name (str): Name of the city
    decade1 (int): First decade (e.g., 1980 for 1980s)
    decade2 (int): Second decade (e.g., 2000 for 2000s)

    Returns:
    dict: {
        'city': str,
        'decade1': {'period': '1980s', 'avg_temp': float, 'data_points': int},
        'decade2': {'period': '2000s', 'avg_temp': float, 'data_points': int},
        'difference': float,
        'trend': str  # 'warming', 'cooling', or 'stable'
    }

    """
    city_found, temperature = get_city_temperatures(data, city_name)
    if not city_found:
        return {"error": f"City '{city_name}' not found."}
    if not temperature:
        return {}
    # Decade Temperatures
    decade1_temperatures = [
        temp
        for month, temp in temperature.items()
        if decade1 <= int(month[:4]) < decade1 + 10
    ]
    decade2_temperatures = [
        temp
        for month, temp in temperature.items()
        if decade2 <= int(month[:4]) < decade2 + 10
    ]
    if not decade1_temperatures:
        return {"error": "insufficient data for one or both decades."}
    if not decade2_temperatures:
        return {"error": "insufficient data for one or both decades."}
    # Average Temperature per decade
    avg_temp1 = sum(decade1_temperatures) / len(decade1_temperatures)
    avg_temp2 = sum(decade2_temperatures) / len(decade2_temperatures)
    # Check trends
    difference = avg_temp2 - avg_temp1
    if difference > 0.1:
        trend = "warming"
    elif difference < -0.1:
        trend = "cooling"
    else:
        trend = "stable"
    return {
        "city": city_name,
        "decade1": {
            "period": f"{decade1}s",
            "avg_temp": avg_temp1,
            "data_points": len(decade1_temperatures),
        },
        "decade2": {
            "period": f"{decade2}s",
            "avg_temp": avg_temp2,
            "data_points": len(decade2_temperatures),
        },
        "difference": difference,
        "trend": trend,
    }


def find_similar_cities(data, city_name, tolerance=1.0):
    """
    Find cities with similar average temperatures to the target city.

    Parameters:
    filename (str): Path to the CSV file
    target_city (str): Reference city name
    tolerance (float): Temperature difference threshold in °C

    Returns:
    dict: {
        'target_city': str,
        'target_avg_temp': float,
        'similar_cities': [
            {'city': str, 'country': str, 'avg_temp': float, 'difference': float}
        ],
        'tolerance': float
    }

    """
    if city_name not in data:
        return {"error": f"City '{city_name}' not found."}
    target_temperatures = list(data[city_name]["records"].values())
    if not target_temperatures:
        return {
            "target_city": city_name,
            "target_avg_temp": None,
            "similar_cities": [],
            "tolerance": tolerance,
        }
    # Compute target city average
    target_avg = sum(target_temperatures) / len(target_temperatures)
    similar_cities = []
    for city, info in data.items():
        if city != city_name and info["records"]:
            temps = list(info["records"].values())
            city_avg = sum(temps) / len(temps)
            if abs(city_avg - target_avg) <= tolerance:
                similar_cities.append(
                    {
                        "city": city,
                        "country": info["country"],
                        "avg_temp": city_avg,
                        "difference": abs(city_avg - target_avg),
                    }
                )
    return {
        "target_city": city_name,
        "target_avg_temp": target_avg,
        "similar_cities": similar_cities,
        "tolerance": tolerance,
    }


def get_temperature_trends(data, city_name, window_size=5, decade_tolerance=0.2):
    """
    Calculate temperature trends using moving averages and identify patterns.

    Parameters:
    filename (str): Path to the CSV file
    city_name (str): Name of the city
    window_size (int): Number of years for moving average calculation
    decade_tolerance (float): Minimum °C/decade change to count as a real trend

    Returns:
    dict: {
        'city': str,
        'raw_annual_data': {'YYYY': float},  # Annual averages
        'moving_averages': {'YYYY': float},  # Moving averages
        'trend_analysis': {
            'overall_slope': float,  # °C per year
            'warming_periods': [{'start': year, 'end': year, 'rate': float}],
            'cooling_periods': [{'start': year, 'end': year, 'rate': float}]
        }
    }
    """
    city_found, temperatures = get_city_temperatures(data, city_name)
    if not city_found:
        return {"error": f"City '{city_name}' not found."}
    if not temperatures:
        return {}
    # Grouping monthly values into per-year lists
    annual_data = {}
    for month, temp in temperatures.items():
        year = int(month.split("-")[0])
        if year not in annual_data:
            annual_data[year] = []
        annual_data[year].append(temp)
    # Finding raw annual averages
    raw_annual_data = {}
    for year, temps in annual_data.items():
        if temps:
            raw_annual_data[year] = sum(temps) / len(temps)
    # Calculate moving averages
    sorted_years = sorted(raw_annual_data.keys())
    annual_temps = [raw_annual_data[year] for year in sorted_years]
    moving_averages = {}
    if len(annual_temps) >= window_size:
        for i in range(len(annual_temps) - window_size + 1):
            window = annual_temps[i : i + window_size]
            year_key = sorted_years[i + window_size - 1]
            moving_averages[year_key] = sum(window) / len(window)
    # Setting up for trend analysis
    ma_years = sorted(moving_averages.keys())
    ma_temps = [moving_averages[year] for year in ma_years]
    overall_slope = 0.0
    warming_periods = []
    cooling_periods = []
    # Slope calculation { slope = b = (nΣxy − ΣxΣy) / (nΣx² − (Σx)²) }
    if len(ma_years) >= 2:
        n = len(ma_years)
        sum_x = sum(ma_years)
        sum_y = sum(ma_temps)
        sum_xy = sum(ma_years[i] * ma_temps[i] for i in range(n))
        sum_x_sq = sum(x**2 for x in ma_years)
        numerator = n * sum_xy - sum_x * sum_y
        denominator = n * sum_x_sq - sum_x**2
        if denominator != 0:
            overall_slope = numerator / denominator
        # Tolerance per year
        per_year_tolerance = decade_tolerance / 10.0
        # Identify warming / cooling periods
        current_period = None
        for i in range(1, len(ma_years)):
            start_year = ma_years[i - 1]
            start_temp = ma_temps[i - 1]
            end_year = ma_years[i]
            end_temp = ma_temps[i]
            delta_temp = end_temp - start_temp
            delta_years = end_year - start_year
            if delta_years == 0:
                continue
            rate = delta_temp / delta_years
            if abs(rate) < per_year_tolerance:
                trend_type = "flat"
            elif rate > 0:
                trend_type = "warming"
            else:
                trend_type = "cooling"
            if trend_type == "flat":
                continue
            # When is trend slope is non-zero, you start a new period
            if current_period is None:
                current_period = {"start": start_year, "type": trend_type}
            elif trend_type != current_period["type"]:
                # close previous period
                current_period["end"] = start_year
                p_start_year = current_period["start"]
                p_start_temp = moving_averages[p_start_year]
                duration = current_period["end"] - p_start_year
                if duration > 0:
                    current_period["rate"] = (start_temp - p_start_temp) / duration
                else:
                    current_period["rate"] = 0.0
                if current_period["type"] == "warming":
                    warming_periods.append(current_period)
                else:
                    cooling_periods.append(current_period)
                # start new period
                current_period = {"start": start_year, "type": trend_type}
        # Save the final active period
        if current_period is not None:
            current_period["end"] = ma_years[-1]
            p_start_year = current_period["start"]
            p_start_temp = moving_averages[p_start_year]
            duration = current_period["end"] - p_start_year
            if duration > 0:
                current_period["rate"] = (ma_temps[-1] - p_start_temp) / duration
            else:
                current_period["rate"] = 0.0
            if current_period["type"] == "warming":
                warming_periods.append(current_period)
            else:
                cooling_periods.append(current_period)
    return {
        "city": city_name,
        "raw_annual_data": {str(y): v for y, v in raw_annual_data.items()},
        "moving_averages": {str(y): v for y, v in moving_averages.items()},
        "trend_analysis": {
            "overall_slope": overall_slope,
            "warming_periods": warming_periods,
            "cooling_periods": cooling_periods,
        },
    }


def test_api_functions():
    """Comprehensive test for Temperature Data API."""
    filename = "GlobalLandTemperaturesByMajorCity.csv"
    data = load_temperature_data(filename)
    test_city = "Bangalore"
    print("Testing Temperature Data API")
    print("=" * 40)

    # ---------------------------
    # 1. Basic Functionality
    # ---------------------------
    city_found, temps = get_city_temperatures(data, test_city)
    if not city_found:
        print("Basic function: DNE")
    else:
        print(f"Basic function: Found {len(temps)} records for {test_city}")

    # ---------------------------
    # 2. Extremes
    # ---------------------------
    extremes = find_temperature_extremes(data, test_city)
    if "error" in extremes:
        print("Extremes: DNE")
    else:
        print(
            f"Extremes: Hottest = {extremes['hottest']['temperature']}°C, "
            f"Coldest = {extremes['coldest']['temperature']}°C"
        )

    # ---------------------------
    # 3. Seasonal Averages
    # ---------------------------
    season = "winter"
    summer_avg = get_seasonal_averages(data, test_city, season)
    if "error" in summer_avg or not summer_avg:
        print("Seasonal: DNE")
    else:
        assert "average_temperature" in summer_avg, "Missing avg temp key"
        print(f"Seasonal: {season} average = {summer_avg['average_temperature']:.2f}°C")

    # ---------------------------
    # 4. Decade Comparison
    # ---------------------------
    comparison = compare_decades(data, test_city, 1980, 2000)
    if "error" in comparison:
        print("Decades: Insufficient data")
    else:
        print(
            f"Decades: {comparison['decade1']['period']} vs "
            f"{comparison['decade2']['period']} -> ΔT = {comparison['difference']:.2f}°C "
            f"({comparison['trend']})"
        )

    # ---------------------------
    # 5. Similar Cities
    # ---------------------------
    tolerance = 1.0
    similar = find_similar_cities(data, test_city, tolerance)
    if "error" in similar:
        print("Similar cities: DNE")
    else:
        print(
            f"Similar cities: Found {len(similar['similar_cities'])} matches within ±{tolerance}°C"
        )

    # ---------------------------
    # 6. Trends
    # ---------------------------
    trends = get_temperature_trends(data, test_city)
    if "error" in trends or not trends:
        print("Trends: DNE")
    else:
        slope = trends["trend_analysis"]["overall_slope"]
        print(
            f"Trends: Overall slope = {slope:.4f}°C/year, "
            f"Warming periods = {len(trends['trend_analysis']['warming_periods'])}, "
            f"Cooling periods = {len(trends['trend_analysis']['cooling_periods'])}"
        )

    # ---------------------------
    # 7. Performance Benchmark (basic)
    # ---------------------------
    import time

    start = time.time()
    _ = get_temperature_trends(data, test_city, window_size=5)
    elapsed = time.time() - start
    print(f"Performance: get_temperature_trends executed in {elapsed:.3f}s")

    print("=" * 40)
    print("All tests completed")


if __name__ == "__main__":
    test_api_functions()
