# importing pandas module 
import pandas as pd 

# making data frame 
data = pd.read_csv("https://cdncontribute.geeksforgeeks.org/wp-content/uploads/nba.csv") 
	
# removing null values to avoid errors 
data.dropna(inplace = True) 

# creating new column with divided values 
data["New_Salary"]= data["Salary"].div(data['Weight']) 

# rounding of values and stroing in new colum 
data['New']= data['New_Salary'].round() 

# variable for max decimal places 
dec_places = 2

# rounding of values and stroing in new colum 
data['New2']= data['New_Salary'].round(dec_places) 

# display 
data.head(10) 

