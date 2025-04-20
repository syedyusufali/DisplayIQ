import cv2
import displayiq_cpp
import matplotlib.pyplot as plt

img = cv2.imread("../data/sample.jpg")
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

enhanced = displayiq_cpp.enhance_contrast(img_rgb, clip_limit=2.5, tile_size=8)

plt.subplot(1, 2, 1)
plt.imshow(img_rgb)
plt.title("Original")

plt.subplot(1, 2, 2)
plt.imshow(enhanced)
plt.title("Enhanced (C++)")
plt.show()