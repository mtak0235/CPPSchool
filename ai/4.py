import pandas as pd
import io
from google.colab import files
from tensorflow.keras import datasets, layers, models
import numpy as np
from sklearn.model_selection import train_test_split

iris = datasets.load_iris()
X = iris.data
y = iris.target
train_images, test_images, train_labels, test_labels = train_test_split(X, y, test_size=0.2, random_state=4)

model = models.Sequential()
model.add(layers.Dense(512, activation='relu'))
model.add(layers.Dense(10, activation='softmax'))
model.compile(optimizer='adam',
loss='sparse_categorical_crossentropy',
metrics=['accuracy'])
model.fit(train_images, train_labels, epochs=5)
test_loss, test_acc = model.evaluate(test_images, test_labels)
print('정확도:', test_acc)