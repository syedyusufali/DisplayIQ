import cv2
from .enhancement import enhance_contrast
from .evaluation import compute_psnr, compute_ssim

def process_image(img_path: str, clip_limit: float = 2.0, tile_grid_size=(8, 8)):
    """
    Processes an image using CLAHE enhancement and computes quality metrics.

    Args:
        img_path (str): Path to input image.
        clip_limit (float): CLAHE clip limit.
        tile_grid_size (tuple): CLAHE tile grid size.

    Returns:
        dict: Dictionary with original image, enhanced image, PSNR, and SSIM.
    """
    img = cv2.imread(img_path)
    enhanced = enhance_contrast(img, clip_limit, tile_grid_size)
    psnr_val = compute_psnr(img, enhanced)
    ssim_val = compute_ssim(img, enhanced)
    return {
        "original": img,
        "enhanced": enhanced,
        "psnr": psnr_val,
        "ssim": ssim_val
    }
