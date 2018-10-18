#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np


# In[2]:


from keras.datasets import mnist


# In[3]:


(X_train, Y_train), (X_test, Y_test) = mnist.load_data()
print(len(X_train))
print(len(X_test))


# In[4]:


print(Y_train[2])
print(X_train[2])


# In[5]:


#rescaling
X_train = X_train.astype('float32')/255
X_test = X_test.astype('float32')/255


# In[6]:


print(X_train[0])


# # One hot encoding

# In[7]:


from keras.utils import np_utils
Y_train = np_utils.to_categorical(Y_train, 10)
Y_test = np_utils.to_categorical(Y_test,10)


# In[8]:


print(Y_train[0])
print(Y_train[2])


# In[9]:


from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten


# In[10]:


print(X_train.shape)


# In[11]:


model = Sequential()
model.add(Flatten(input_shape=X_train.shape[1:]))
model.add(Dense(512, activation='relu'))
model.add(Dropout(0.2))
model.add(Dense(512, activation='relu'))
model.add(Dropout(0.2))
model.add(Dense(10, activation='softmax'))
model.summary()


# In[12]:


model.compile(loss='categorical_crossentropy', optimizer='rmsprop', metrics=['accuracy'])


# In[13]:


from keras.callbacks import ModelCheckpoint


# In[14]:


checkp = ModelCheckpoint(filepath='best.weights_2', verbose=1, save_best_only=True)
model_fit = model.fit(X_train, Y_train, batch_size=128, epochs=50,
          validation_split=0.2, callbacks=[checkp],
          verbose=1, shuffle=True)


# In[15]:


model.load_weights('best.weights_2')


# In[16]:


score = model.evaluate(X_test, Y_test, verbose=0)
accuracy = 100*score[1]

# print test accuracy
print('Test accuracy: %.4f%%' % accuracy)


# In[ ]:





# In[ ]:




