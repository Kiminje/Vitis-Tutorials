
#include "types.h"

extern "C" {
  // Convolve RGB video frame with input filter
  void convolve_cpu(const RGBPixel* inFrame, RGBPixel* outFrame, const float* filter, int filter_size, int img_width, int img_height);
  // Convert RGB video frame to grayscale
  void grayscale_cpu(const RGBPixel* inFrame, GrayPixel* outFrame, int img_width, int img_height);

  // Convolve RGB video frame with input filter
  #ifdef HOST_CODE_OPT 
  void convolve_fpga(const RGBPixel* inFrame, RGBPixel* outFrame, const float* coefficient, int coefficient_size, int img_width, int img_height, 
                                 int line_offset, int num_lines);
  #else
  void convolve_fpga(const RGBPixel* inFrame, RGBPixel* outFrame, const float* filter, int filter_size, int img_width, int img_height);  
  #endif
  // Convert RGB video frame to grayscale
  void grayscale_fpga(const RGBPixel* inFrame, GrayPixel* outFrame, int img_width, int img_height);
}
