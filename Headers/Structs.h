#pragma once

#include <vector>
#include "glm.hpp"
#include "vulkan.h"

struct Vertex {
	glm::vec4 position;
	glm::vec4 normal;
	glm::vec4 color;
	glm::vec4 uv;
};

struct Transform {
    glm::mat4 transform;
	glm::mat4 ringtransform;
	glm::mat4 consttransform;
	glm::mat4 normalMatrix;
	glm::mat4 ringNormal;
	glm::mat4 projectionMatrix;
    glm::mat4 textransform;
    glm::mat4 aimtransform;
    glm::mat4 dstransform;
    glm::mat4 juptransform;
    glm::mat4 jupnormal;
    glm::mat4 asdtransform;
    glm::mat4 asdnormal;
    float time;
};

struct colorTF {
    glm::vec4 color;
};

struct TextureFile
{
	uint32_t			width;
	uint32_t			height;
	unsigned char* pixels;
	VkImage				texImage;
	VkImageView			texImageView;
	VkSampler			texSampler;
	VkDeviceMemory			vdm;
	VkDeviceMemory			nvdm;
};

enum class playerControls {
    moveUp,
    moveDown,
    None
};