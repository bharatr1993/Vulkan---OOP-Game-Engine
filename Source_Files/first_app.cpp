#include "first_app.hpp"

// std
#include <array>
#include <stdexcept>

namespace lve {

    int moveLeft = GLFW_KEY_LEFT;
    int moveRight = GLFW_KEY_RIGHT;
    int moveForward = GLFW_KEY_UP;
    int moveBackward = GLFW_KEY_DOWN;

    playerControls currentMove = playerControls::None;

    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

        if (key == moveForward && action == GLFW_PRESS)
            currentMove =playerControls::moveUp;
        else if(key == moveForward && action == GLFW_RELEASE && currentMove==playerControls::moveUp)
            currentMove =playerControls::None;
        else if(key == moveBackward && action == GLFW_PRESS)
            currentMove = playerControls::moveDown;
        else if(key == moveBackward && action == GLFW_RELEASE && currentMove==playerControls::moveDown)
            currentMove = playerControls::None;

    }


FirstApp::FirstApp() {


    lveRenderer = std::make_unique<LveRenderer>(lveDevice, lveWindow, lveSwapChain, vertPath, fragPath, tescPath,tesePath,bmpPath, vertices,objPath);
    glfwSetKeyCallback(lveWindow.window,keyCallback);
    lveRenderer->transform.projectionMatrix = glm::perspective( glm::radians(60.),(double) lveWindow.getAspectRatio(), 0.1, 100. );
    lveRenderer->transform.projectionMatrix *= glm::lookAt(  glm::vec3(0.0f,0.0f,3.0f),  glm::vec3(0.0f,0.0f,0.0f),  glm::vec3(0.0f,1.0f,0.0f) );
}

FirstApp::~FirstApp() {}

void FirstApp::run() {

  while (!lveWindow.shouldClose()) {
       std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
       renderScene();
       lveRenderer->createCommandBuffers(pipelineNames);
       lveRenderer->drawFrame();
       glfwPollEvents();
       std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
       std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
       fElapsedTime=time_span.count();
  }

  vkDeviceWaitIdle(lveDevice.device());
}

void FirstApp::renderScene() {

        lveRenderer->transform.time += fElapsedTime ;

        jMat.translation = {0.0f,-0.75f,0.0f};
        jMat.rotation = {0.0f,-0.25f + 0.25*lveRenderer->transform.time,0.0f};
        jMat.scale={0.035f,0.035f,0.035f};

        lveRenderer->transform.juptransform=jMat.mat4();
        lveRenderer->transform.jupnormal= glm::mat4(glm::inverseTranspose(glm::mat3(lveRenderer->transform.juptransform)));

       // lveRenderer->transform.consttransform = rotamat.mat4();
        lveRenderer->transform.normalMatrix = glm::mat4(glm::inverseTranspose(glm::mat3(lveRenderer->transform.transform)));
        lveRenderer->transform.ringNormal = glm::mat4(glm::inverseTranspose(glm::mat3(lveRenderer->transform.ringtransform)));

        //lveRenderer->descriptorSet->writeBufferReference(lveRenderer->lveBufferPtrVec);
        lveRenderer->descriptorSet->updateDescriptorSet( (void *)&lveRenderer->transform);

}

}  // namespace lve