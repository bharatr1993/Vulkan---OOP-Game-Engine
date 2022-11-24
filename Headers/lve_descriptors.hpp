#pragma once

#include "lve_device.hpp"
#include "lve_texture.hpp"
#include "lve_buffer.hpp"
// std
#include <memory>
#include <unordered_map>
#include <vector>
#include "Structs.h"

namespace lve {

    class LveDescriptorSet {
    public:

        LveDescriptorSet(
            LveDevice& lveDevice, std::vector<VkDescriptorPoolSize> pSizes, std::vector<VkDescriptorSetLayoutBinding> bindings);
        ~LveDescriptorSet();

        std::vector<VkDescriptorSetLayout> getDescriptorSetLayout() const { return descriptorSetLayout; }
        std::vector<VkDescriptorSet> descriptor;
        std::vector<VkDescriptorSetLayoutBinding> binding;
        std::vector<VkDescriptorSetLayout> descriptorSetLayout;
        void writeBufferReference(std::vector<std::shared_ptr<LveBuffer>> buffer) { buffers = buffer; }//Later change to vector and modify lveModel.cpp
        void writeDescriptorSet();
        void updateDescriptorSet(void *transform);
        std::unique_ptr<LveTexture> lveTexture;

    private:
        LveDevice& lveDevice;
        std::vector<VkWriteDescriptorSet> writeDscSet;
        std::vector<VkDescriptorPoolSize> poolSizes{};
        uint32_t maxSets = 1000;
        VkDescriptorPoolCreateFlags poolFlags = 0;
        std::vector<std::shared_ptr<LveBuffer>> buffers; //Later change to vector and modify lveModel.cpp

        bool allocateDescriptor();

        void freeDescriptors(std::vector<VkDescriptorSet>& descriptors) const;

        void resetPool();

        void createPool();

        VkDescriptorPool descPool;

        void overwrite(VkDescriptorSet& set);

       

        std::vector<VkWriteDescriptorSet> writes;

        

    };

}  // namespace lve
