#CNN on cifar dataset
from keras.datasets import cifar100
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import OneHotEncoder
from keras.layers import Conv2D, Dense, Flatten, MaxPooling2D, Dropout
from keras.layers import BatchNormalization
from keras.models import Sequential
from keras import optimizers
 
(x_train, y_train), (x_test, y_test) = cifar100.load_data()
print(x_train.shape)
#(50000, 32, 32, 3)
print(y_train.shape)
#(50000, 1)
"""
 x_test.shape
Out[61]: (10000, 32, 32, 3)
y_test.shape
Out[59]: (10000, 1)
"""
#plt.imshow(x_train[20].reshape(32,32,3))

def labelEncode(labels):
    #one_hot_labels = keras.utils.to_categorical(labels, num_classes=10)
    lab_encoder = LabelEncoder()
    int_encoder = lab_encoder.fit_transform(labels)
    onehot_encoder = OneHotEncoder(sparse=False)
    int_encoder = int_encoder.reshape(len(int_encoder), 1)
    onehot_encoded = onehot_encoder.fit_transform(int_encoder)
    return onehot_encoded

y_train = labelEncode(y_train)
y_test = labelEncode(y_test)

def mymodel():
    model = Sequential()
    model.add(Conv2D(16,kernel_size=(5,5), input_shape = (32,32,3),activation = 'relu'))
    model.add(MaxPooling2D(pool_size = (2,2)))
    model.add(Dropout(0.12))
    model.add(BatchNormalization())
    
    model.add(Conv2D(8,kernel_size = (3,3), activation = 'relu'))
    model.add(MaxPooling2D(pool_size = (2,2)))
    model.add(Dropout(0.24))
    
    model.add(Conv2D(8,kernel_size = (3,3), activation = 'relu'))
    model.add(MaxPooling2D(pool_size = (2,2)))
    model.add(Dropout(0.30))
    model.add(BatchNormalization())
    
    model.add(Flatten())
    model.add(Dense(200,activation = 'sigmoid'))
    model.add(Dense(100, activation = 'softmax'))
    return model

model = mymodel()
ada = optimizers.Adagrad(lr = 0.08)
model.compile(optimizer = ada, loss = 'categorical_crossentropy', metrics = ['accuracy'])
model.fit(x_train,y_train, epochs = 20, batch_size = 16)
score = model.evaluate(x_test,y_test,batch_size = 16)
print(score)


