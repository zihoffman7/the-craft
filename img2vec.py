import numpy as np
from PIL import Image

img = Image.open('5.png')
a = np.array(img).tolist()

arr = []
for r in a:
    for e in r:
        arr += e
print(arr)
