#ifndef LIBGPU_EXT_CUDA
#define LIBGPU_EXT_CUDA

#include <cuda.h>

#include <compyte/config.h>
#include <compyte/buffer.h>
#include <compyte/extension.h>

static void (*cuda_enter)(void *);
static void (*cuda_exit)(void *);
static void *(*cuda_make_ctx)(CUcontext, int);
static CUcontext (*cuda_get_ctx)(void *);
static CUstream (*cuda_get_stream)(void *);
static gpudata *(*cuda_make_buf)(void *, CUdeviceptr, size_t);
static CUdeviceptr (*cuda_get_ptr)(gpudata *);
static size_t (*cuda_get_sz)(gpudata *);
static void (*cuda_set_compiler)(void *(*)(const char *, size_t, int *));

static void setup_ext_cuda(void) {
  // The casts are necessary to reassure C++ compilers
  cuda_enter = (void (*)(void *))compyte_get_extension("cuda_enter");
  cuda_exit = (void (*)(void *))compyte_get_extension("cuda_exit");
  cuda_make_ctx = (void *(*)(CUcontext, int))compyte_get_extension("cuda_make_ctx");
  cuda_get_ctx = (CUcontext (*)(void *))compyte_get_extension("cuda_get_ctx");
  cuda_get_stream = (CUstream (*)(void *))compyte_get_extension("cuda_get_stream");
  cuda_make_buf = (gpudata *(*)(void *, CUdeviceptr, size_t))compyte_get_extension("cuda_make_buf");
  cuda_get_ptr = (CUdeviceptr (*)(gpudata *))compyte_get_extension("cuda_get_ptr");
  cuda_get_sz = (size_t (*)(gpudata *))compyte_get_extension("cuda_get_sz");
  cuda_set_compiler = (void (*)(void *(*)(const char *, size_t, int *)))compyte_get_extension("cuda_set_compiler");
}

#endif
