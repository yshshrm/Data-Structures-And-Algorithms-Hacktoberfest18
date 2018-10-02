import folium
import numpy as np
from folium import plugins
import sys
import pandas as pd
import matplotlib.pyplot as plt
# Importing the dataset
dataset = pd.read_csv('Global_Landslide_Catalog_Export.csv')
X = dataset.iloc[:, -2:].values
# Get a basic world map.
map = folium.Map(location=[30, 0], zoom_start=2)
# Draw markers on the map.
from sklearn.cluster import KMeans
kmeans = KMeans(n_clusters = 5, init = 'k-means++', random_state = 42)
y_kmeans = kmeans.fit_predict(X)
import folium

# Get a basic world map.
map = folium.Map(location=[30, 0], zoom_start=2)
# Draw markers on the map.
for name, row in dataset.iterrows():
    if row["source_name"]:
        folium.CircleMarker(location=[row['latitude'], row['longitude']],radius=15,fill_color="#3db7e4",popup=row['source_name'])
# Create and show the map.
stationArr = dataset[['latitude', 'longitude']].as_matrix()
map.add_child(plugins.HeatMap(stationArr, radius=15))
map.save('osm.html')
map

