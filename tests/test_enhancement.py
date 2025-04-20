from displayiq.enhancement import enhance_contrast
import cv2
import numpy as np

def test_enhance_contrast():
    img = np.ones((100, 100, 3), dtype=np.uint8) * 127
    result = enhance_contrast(img)
    assert result.shape == img.shape
