#pragma once
#include "Comphi/Platform/IFileRef.h"
#include "MemBuffer.h"

namespace Comphi::Vulkan {

	class ImageBuffer : public MemBuffer
	{
	public:
		struct ImgSpecification {
			VkFormat format = VK_FORMAT_R8G8B8A8_SRGB;
			VkImageAspectFlags aspectFlags = VK_IMAGE_ASPECT_COLOR_BIT;
			VkImageTiling tiling = VK_IMAGE_TILING_OPTIMAL;
			VkImageUsageFlags usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;
		};
		ImageBuffer(IFileRef& fileref, ImgSpecification spec);//TODO: Add rawData Initialization construct
		
		VkImage bufferObj; //override bufferType
		//<< bufferMemory;
		//<< bufferSize;
		VkExtent2D imageExtent;
		VkFormat imageFormat;
		VkImageLayout imageLayout;

		static void copyBufferToImgBuffer(MemBuffer& srcBuffer, ImageBuffer& dstImagebuffer);
		void copyBufferToImgBuffer(MemBuffer& srcBuffer);
		bool hasStencilComponent();
		virtual void cleanUp() override;

	protected :
		void initTextureImageBuffer(std::string& filepath, ImgSpecification spec);
		void initImageBuffer(ImgSpecification spec);
		void initDepthImageBuffer(VkExtent2D& swapchainExtent, VkFormat format);
		
		ImageBuffer() = default;
		void transitionImageLayout(VkImageLayout newLayout);
	};



}