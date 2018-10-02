import numpy as np
import matplotlib.pyplot as plt  
import pandas as pd  

dataset = pd.read_csv('iris1.csv', header=0)

X = dataset.iloc[:, :-1].values  
y = dataset.iloc[:, 4].values  

from sklearn.model_selection import train_test_split  
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.30,stratify=y)

#from sklearn.preprocessing import StandardScaler  
#scaler = StandardScaler()  
#scaler.fit(X_train)
#
#X_train = scaler.transform(X_train)  
#X_test = scaler.transform(X_test) 

from sklearn.neighbors import KNeighborsClassifier  
classifier = KNeighborsClassifier(n_neighbors=5)  
classifier.fit(X_train, y_train)  

y_pred = classifier.predict(X_test)  

from sklearn.metrics import classification_report, confusion_matrix  
#print(confusion_matrix(y_test, y_pred))  
print(pd.crosstab(y_test, y_pred, rownames=['True'], colnames=['Predicted'], margins=True))
#print(classification_report(y_test, y_pred))


from sklearn.model_selection import StratifiedKFold
from sklearn.metrics import accuracy_score
skf = StratifiedKFold(n_splits=10)
skf.get_n_splits(X, y)  
StratifiedKFold(n_splits=10, random_state=None, shuffle=False)
a=0
for train_index, test_index in skf.split(X, y):
	print("TRAIN:", train_index, "TEST:", test_index)
	X_train, X_test = X[train_index], X[test_index]
	y_train, y_test = y[train_index], y[test_index]
	y_pred = classifier.predict(X_test)
	accuracy = accuracy_score(y_test, y_pred)
	a+=accuracy
print("\nK-fold cross validation (10 folds): "+str(a/10))