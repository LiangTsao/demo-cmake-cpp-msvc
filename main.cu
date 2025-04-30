#include <cuda_runtime.h>
#include <iostream>

__global__ void helloFromGPU() {
    printf("Hello from GPU!\n");
}

int main() {
    // Get CUDA device properties
    int deviceCount;
    cudaGetDeviceCount(&deviceCount);

    std::cout << "Number of CUDA devices: " << deviceCount << "\n";

    for (int i = 0; i < deviceCount; ++i) {
        cudaDeviceProp prop;
        cudaGetDeviceProperties(&prop, i);

        std::cout << "Device " << i << ": " << prop.name << "\n";
        std::cout << "  Compute capability: " << prop.major << "." << prop.minor << "\n";
        std::cout << "  Total global memory: " << prop.totalGlobalMem / (1024 * 1024) << " MB\n";
    }

    // Launch a simple kernel
    helloFromGPU<<<1, 1>>>();
    cudaDeviceSynchronize();

    return 0;
}