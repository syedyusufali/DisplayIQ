import os

def ensure_dir(directory):
    """
    Ensures the specified directory exists; creates it if not.

    Args:
        directory (str): Directory path.
    """
    if not os.path.exists(directory):
        os.makedirs(directory)

def get_filename(path):
    """
    Extracts filename without extension from a file path.

    Args:
        path (str): File path.

    Returns:
        str: Filename without extension.
    """
    return os.path.splitext(os.path.basename(path))[0]
