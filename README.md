# DisplayIQ
[![SoC-Aware](https://img.shields.io/badge/design-SoC--aware-blue.svg)](#)  
[![Lang](https://img.shields.io/badge/lang-Python%20%7C%20C%2B%2B-orange.svg)](#)  
[![Accelerated](https://img.shields.io/badge/acceleration-C++%20%2B%20Pybind11-brightgreen.svg)](#)

**A systems-level image enhancement toolkit simulating real-world display processing workflows for embedded systems and SoC platforms.**

---

## Overview

**DisplayIQ** is a hardware-aware implementation of classical image enhancement algiorithms, designed to reflect how real-world display pipelines are developed, optimized, and prepared for deployment in embedded and SoC environments.

This project demonstrates:
- Prototyping image enhancement in **Python**
- Porting to **C++** for efficient embedded execution
- Profiling for **latency**, **memory**, and **scalability**
- Bridging to higher-level frameworks using **pybind11**

> While the core algorithm (CLAHE) is classical, this project focuses on how such algorithms are engineered, tuned, and prepared for integration in visual subsystems within modern embedded platforms.

---

## Features

| Module | Description |
|--------|-------------|
| **Python Prototyping** | Image enhancement pipeline using OpenCV, NumPy |
| **C++ Engine** | Optimized enhancement logic (CLAHE) with clean APIs |
| **Pybind Bridge** | Python/C++ interoperability for hybrid pipelines |
| **Metrics Logger** | Tracks latency and memory usage |
| **Test Vector Export** | Easily export inputs/outputs for downstream integration |

---

## Motivation

This project was created to **simulate the full development lifecycle** of image processing algorithms targeting embedded systems such as:
- Mobile application processors
- AR/VR headsets
- Wearables and custom SoCs

It reflects typical engineering workflows where:
- Algorithms are rapidly prototyped in Python or MATLAB
- Then optimized and implemented in C++ for hardware deployment
- With careful trade-offs in compute, memory, latency, and quality

---
## Demo

### Python Demo

```bash
python examples/demo_enhancement.ipynb
```

### C++ Executable

```bash
./enhance data/sample.jpg
```

## Sample Output

```yaml
Latency: 7.34 ms
Input size: 768.00 KB
Output size: 768.00 KB
```
---

## Example Output

| Original | Enhanced (C++ Accelerated) |
|----------|----------------------------|
| ![original](assets/original.jpg) | ![enhanced](assets/enhanced.jpg) |

---

## Directory Structure

```plaintext
displayiq/
├── displayiq/         # Python enhancement and evaluation modules
├── cpp/               # C++ engine, pybind11 wrapper, and CLI executable
│   ├── include/
│   ├── src/
│   ├── bindings/
│   └── main.cpp
├── examples/          # Notebooks and Python demos
├── tests/             # Unit tests
├── data/              # Sample images (not versioned)
├── README.md
```

---

## Technologies Used

**Python 3.8+**
- NumPy  
- OpenCV  
- scikit-image  
- matplotlib  

**C++17**
- OpenCV  
- pybind11  
- CMake  

---

## Future Enhancements

- Add quantization-aware fixed-point simulation (8-bit / 10-bit)  
- Export binary test vectors for hardware verification teams  
- Add support for benchmarking on Jetson or Raspberry Pi  
- Implement faster variants of CLAHE with tunable power-quality tradeoffs  
- Build a Streamlit UI to allow interactive visual tuning   

---

## License

This repository is provided under the **MIT License**.  
Free to use for educational, research, or engineering portfolio purposes.

---

## Contact

**Created by:** Syed Yusuf Ali 

*PhD Candidate, Johns Hopkins University*  
For questions or collaboration ideas, feel free to reach out via GitHub or [LinkedIn](https://www.linkedin.com/in/syedyusufjhu/).



