from tensorflow import keras
from sklearn.model_selection import train_test_split
from tensorflow.keras import datasets, layers, models
import numpy as np
import tensorflow as tf

train_input = np.array([[[1, 1], [1, 1]], [[0, 0], [0, 0]], [[1, 0], [1, 0]], [[0, 1], [0, 1]], [[1, 0], [0, 1]], [[0, 1], [1, 0]], [[0, 0], [1, 1]], [[1, 1], [0, 0]]])
train_labels = np.array([0, 0, 1, 1, 2, 2, 3, 3])
label = ["solid", "vertical", "diagonal", "horizontal"]

train_input = train_input / 1.
model = models.Sequential()
model.add(layers.Flatten(input_shape=(2, 2)))
model.add(layers.Dense(128, activation='relu'))
model.add(layers.Dense(10, activation='softmax'))
model.compile(optimizer='adam',
loss='sparse_categorical_crossentropy',
metrics=['accuracy'])
model.fit(train_input, train_labels, epochs=5)
test_loss, test_acc = model.evaluate(train_input, train_labels)
print('정확도:', test_acc)