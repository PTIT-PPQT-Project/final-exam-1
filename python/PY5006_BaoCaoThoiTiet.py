import json
import math

class CityWeather:
    def __init__(self, data):
        self.name = data.get('city', 'Khong ro')
        try:
            self.temp = int(data.get('temperature_celsius', -float('inf')))
        except (ValueError, TypeError):
            self.temp = -float('inf')
            
        try:
            self.humidity = int(data.get('humidity_percent', float('inf')))
        except (ValueError, TypeError):
            self.humidity = float('inf')

        try:
            self.wind = int(data.get('wind_kmh', 0))
        except (ValueError, TypeError):
            self.wind = 0

def main():
    all_cities = []
    
    try:
        with open('datas.json', 'r', encoding='utf-8') as f:
            data_list = json.load(f)
            if not isinstance(data_list, list):
                raise json.JSONDecodeError("Data is not a list", "", 0)
                
            for city_data in data_list:
                if isinstance(city_data, dict):
                    all_cities.append(CityWeather(city_data))
                    
    except (FileNotFoundError, json.JSONDecodeError, TypeError):
        pass

    try:
        w_threshold = int(input())
    except (ValueError, EOFError):
        w_threshold = 0
        
    if not all_cities:
        print("None")
        print("None")
        print("None")
        return

    max_temp_city = sorted(all_cities, key=lambda x: x.temp, reverse=True)[0]
    print(max_temp_city.name)
    
    min_humidity_city = sorted(all_cities, key=lambda x: x.humidity)[0]
    print(min_humidity_city.name)
    
    windy_cities = []
    for city in all_cities:
        if city.wind > w_threshold:
            windy_cities.append(city)
            
    if not windy_cities:
        print("None")
    else:
        sorted_windy_cities = sorted(windy_cities, key=lambda x: x.wind, reverse=True)
        for city in sorted_windy_cities:
            print(city.name)

if __name__ == "__main__":
    main()