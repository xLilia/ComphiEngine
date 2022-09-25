#pragma once
#include "MemBuffer.h"

namespace Comphi::Vulkan {

	class ImageBuffer : public MemBuffer
	{
	public:
		ImageBuffer(std::string filepath, const std::shared_ptr<GraphicsHandler>& graphicsHandler,
			VkFormat format = VK_FORMAT_R8G8B8A8_SRGB, VkImageTiling tiling = VK_IMAGE_TILING_OPTIMAL,
			VkImageUsageFlags usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT);
		
		VkImage bufferObj; //override bufferType
		//<< bufferMemory;
		//<< bufferSize;
		uint32_t width;
		uint32_t height;
		//<< graphicsHandler;
		VkFormat imageFormat;
		VkImageLayout imageLayout;

		static void copyBufferToImgBuffer(MemBuffer& srcBuffer, ImageBuffer& dstImagebuffer);
		void copyBufferToImgBuffer(MemBuffer& srcBuffer);
		virtual void cleanUp() override;

		void initImageBuffer(std::string filepath, const std::shared_ptr<GraphicsHandler>& graphicsHandler, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage);

	protected :
		ImageBuffer() = default;
		void transitionImageLayout(VkImageLayout newLayout);
	};



}