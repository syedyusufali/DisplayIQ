from skimage.metrics import structural_similarity as ssim
import cv2
import numpy as np

def compute_psnr(original: np.ndarray, processed: np.ndarray) -> float:
    return cv2.PSNR(original, processed)

def compute_ssim(original: np.ndarray, processed: np.ndarray) -> float:
    gray1 = cv2.cvtColor(original, cv2.COLOR_BGR2GRAY)
    gray2 = cv2.cvtColor(processed, cv2.COLOR_BGR2GRAY)
    return ssim(gray1, gray2)
