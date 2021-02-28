
#include <torch/torch.h>
#include <torch/script.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)

//using namespace cv;
void print_tensor_size(const torch::Tensor&);
void print_script_module(const torch::jit::script::Module& module, size_t spaces = 0);

int main() {

  cv::Mat test;
  test.create(200, 400, CV_32FC1);
  float *index_ptr_testGrapics = test.ptr<float>(0);
  float pixel_level = 0.0f;
  for(int i=0; i< test.rows * test.cols;i++)
  {
    if(pixel_level < 1.0)
    {
      pixel_level = pixel_level + 0.00001f;
    }
    else{
      pixel_level = 0.0f;
    }
     *index_ptr_testGrapics = pixel_level;
    index_ptr_testGrapics++;
  }
  cv::imshow("diff", test);
  cv::waitKey(5000);

    
   // pinball_game objPinBall;
    torch::Device device(torch::kCPU);
    torch::Tensor tensor = torch::zeros({2,5});
    std::cout << tensor << std::endl;
    
    tensor[0][1] = 16;
    std::cout << tensor[0,1] << std::endl;
    std::cout << tensor << std::endl;


if (torch::cuda::is_available()) {
  std::cout << "CUDA is available! " << std::endl;
  device = torch::kCUDA;
}
    torch::Tensor ta = torch::rand({5,3});
    torch::Tensor t = ta.to(device);
    std::cout << t << std::endl;
    t = t.reshape({3,5});
    std::cout << t << std::endl;
    t[0][0] = 17.3f;
    std::cout << t << std::endl;
    torch::Tensor test_tensor2 = torch::zeros({2,3});
    std::cout << test_tensor2 << std::endl;
    torch::Tensor test_gpu_tensor = tensor.to(device);
    std::cout << test_gpu_tensor << std::endl;
//-------------------------------------

    std::cout << "More basic tests\n";
    torch::Tensor t4 = torch::tensor({3,2}).to(device);
    std::cout << t4 << std::endl;
    
    
    std::vector<float> data1 = {11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
    torch::Tensor t5 = torch::from_blob(data1.data(), {2,3}, torch::requires_grad()).to(device);
    std::cout << "************* GPU t5 tensor **************\n";
    std::cout << t5 << std::endl;
    std::cout << "************* Reshape t5 tensor code  t5.reshape({3,2}) no change **************\n";
    t5.reshape({3,2});
    std::cout << t5 << std::endl;

    std::cout << "************* Reshape t5 = t5.reshape({3,2})  t5 tensor **************\n";
    t5 = t5.reshape({3,2});
    std::cout << t5 << std::endl;
    torch::Tensor a1_cpu = torch::tensor(5.0, torch::kFloat32);
    a1_cpu.set_requires_grad(true);
    torch::Tensor b1_cpu = torch::tensor(2.8532, torch::kFloat32);
    b1_cpu.set_requires_grad(false);
    torch::Tensor c1_cpu = torch::tensor(0.0, torch::kFloat32);
    c1_cpu.set_requires_grad(false);


    c1_cpu = a1_cpu * b1_cpu;
    std::cout << "c1_cpu = a1_cpu * b1_cpu = " << c1_cpu << '\n';
    c1_cpu.backward();// Compute the gradients
    std::cout << "a1_cpu gradient = " << a1_cpu.grad() << '\n';
    std::cout << "b1_cpu gradient = " << b1_cpu.grad() << '\n';
    
    std::cout << "PyTorch Basics\n\n";
    std::cout << std::fixed << std::setprecision(4);
}
