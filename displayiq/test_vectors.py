import numpy as np
import cv2
import os

def save_test_vector(input_img, output_img, name="test_vector", out_dir="vectors"):
    """
    Saves input and output images to disk for hardware/software validation.

    Args:
        input_img (np.ndarray): Original image.
        output_img (np.ndarray): Processed image.
        name (str): Base name for saved files.
        out_dir (str): Directory to save images.

    Returns:
        tuple: Paths to saved input and output images.
    """
    os.makedirs(out_dir, exist_ok=True)
    in_path = os.path.join(out_dir, f"{name}_input.png")
    out_path = os.path.join(out_dir, f"{name}_output.png")
    cv2.imwrite(in_path, input_img)
    cv2.imwrite(out_path, output_img)
    return in_path, out_path