from setuptools import setup, find_packages

setup(
    name='displayiq',
    version='0.1',
    packages=find_packages(),
    install_requires=[
        'numpy',
        'opencv-python',
        'scikit-image',
        'matplotlib'
    ],
    author='Your Name',
    description='Image and Video Processing Toolkit for Display Systems',
)