#pragma once

#include "lve_device.hpp"
#include "lve_model.hpp"
#include "lve_pipeline.hpp"
#include "lve_swap_chain.hpp"
#include "lve_window.hpp"
#include "lve_transform.hpp"
#include "lve_renderer.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/constants.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"
#include <chrono>
#include "Structs.h"
// std
#include <memory>
#include <vector>
#include <string.h>


namespace lve {
class FirstApp {
 public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  FirstApp();
  ~FirstApp();

  FirstApp(const FirstApp &) = delete;
  FirstApp &operator=(const FirstApp &) = delete;

  void run();

 private:

  void renderScene();

  std::vector<std::string> vertPath = { {"../Shaders/jup_vert.spv"} };
  std::vector<std::string> fragPath = { {"../Shaders/jup_frag.spv"}};
  std::vector<std::string> bmpPath = { {"../Pictures/metal.bmp"},{"../Pictures/fireem.bmp"}, {"../Pictures/hudgo.bmp"},{"../Pictures/hud.bmp"}, {"../Pictures/deepspace.bmp"},{"../Pictures/ball.bmp"}, {"../Pictures/jupiterNormal.bmp"}};
  std::vector<std::string> tescPath = {}; //Unused----Testing
  std::vector<std::string> tesePath = {}; //Unused----Testing
  std::vector<std::vector<std::string>> objPath = {
                                                    {"../Pictures/jupiter.obj"}
                                                    };
  std::vector<std::string> pipelineNames = {};
  TransformComponent tfMat, jMat={};
  std::chrono::high_resolution_clock::time_point tstart;
  std::unique_ptr<LveRenderer> lveRenderer;
  double fElapsedTime;
  bool init = true;
  float time = 0;

    std::vector<Vertex> vertices = {
            {{-0.5f,-0.5f,0.5f,1.0f},
             {0.5f,0.5f,0.5f,1.0f},
             {0.5f,0.5f,0.5f,1.0f},
             {0.f,1.0f,1.0f,1.0f}},

            {{+0.5f, -0.5f, +0.5f,1.0f},
             {  0.,  0.,  1.,1. },
             {  1.,  0.,  1.,1. },
             {  1., 1.,1.,1. }},
            {{+0.5f, +0.5f, +0.5f,1.0f},
             {  0.,  0.,  1.,1. },
             {  1.,  1.,  1.,1.f },
             {  1., 0. ,1.,1.}},
            {{-0.5f, +0.5f, +0.5f,1.},
             {  0.,  0.,  1. ,1.},
             {  0.,  1.,  1. ,1.},
             {  0., 0.,1.,1. }},
            {{-0.5f, -0.5f, -0.5f,1.},
             {  0.,  0., -1.,1. },
             {  0.,  0.,  0.,1. },
             {  1., 0.,1.,1. }}
    };

    //IGNORE----------------------------------------------------------
  /*
      //{ {{-0.5f, -0.5f}}, {{-0.5f, 0.5f}}, {{0.5f, 0.5f}} }, { {{0.0f, -0.5f}}, {{0.5f, 0.5f}}, {{-0.5f, 0.5f}} } };
    {
    {{-0.5f, -0.5f, +0.5f},
    {  0.,  0.,  1. },
    {  0.,  0.,  1. },
    {  0., 1. }},
    {{+0.5f, -0.5f, +0.5f},
    {  0.,  0.,  1. },
    {  1.,  0.,  1. },
    {  1., 1. }},
    {{+0.5f, +0.5f, +0.5f},
    {  0.,  0.,  1. },
    {  1.,  1.,  1. },
    {  1., 0. }},
    {{-0.5f, +0.5f, +0.5f},
    {  0.,  0.,  1. },
    {  0.,  1.,  1. },
    {  0., 0. }},
    {{-0.5f, -0.5f, -0.5f},
    {  0.,  0., -1. },
    {  0.,  0.,  0. },
    {  1., 0. }},
    {{+0.5f, -0.5f, -0.5f},
    {  0.,  0., -1. },
    {  1.,  0.,  0. },
    {  0., 0. }},
    {{+0.5f, +0.5f, -0.5f},
    {  0.,  0., -1. },
    {  1.,  1.,  0. },
    {  0., 1. }},
    {{-0.5f, +0.5f, -0.5f},
    { -1.,  0.,  0. },
    {  0.,  1.,  0. },
    {  0., 1. }}
    }
  };

  //--- 0
  //--+ 1
  //-++ 2
  //++- 3
  //+-+ 4
  //+++ 5
  //+-- 6
  //-+- 7
  //------------------------------------------------------------

  std::vector<uint32_t> index = {
        0, 1, 2,
        3, 0, 2,

        1, 5, 6,
        6, 2, 1,

        7, 6, 5,
        5, 4, 7,

        4, 0, 3,
        3, 7, 4,

        4, 5, 1,
        1, 0, 4,

        3, 2, 6,
        6, 7, 3
    */


  LveWindow lveWindow{WIDTH, HEIGHT, "Vulkan: Scarlet Storm!"};
  LveDevice lveDevice{lveWindow};
  LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
};
}  // namespace lve