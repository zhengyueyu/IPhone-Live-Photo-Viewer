#include "heifimage.h"
#include "qpixmap.h"
#include "qpainter.h"
extern "C"
{
#include <libheif/heif.h>
}

namespace {
	struct rgbData
	{
		uint8_t* data;
		size_t size;
		int width;
		int height;
	};
}

HeifImage::HeifImage(const QString& fileName)
	: BaseImage()
{
	m_fileName.append(fileName);
	decode2Qimage();
}

QImage HeifImage::getImage()
{
	return m_img;
}

void HeifImage::decode2Qimage()
{
	heif_context* ctx = heif_context_alloc();
	heif_error err = heif_context_read_from_file(ctx, m_fileName.toStdString().c_str(), nullptr);
	if (err.code != heif_error_Ok)
	{
		heif_context_free(ctx);
		return;
	}

	int num_images = heif_context_get_number_of_top_level_images(ctx);
	if (num_images == 0)
	{
		heif_context_free(ctx);
		return;
	}

	std::vector<heif_item_id> image_IDs(num_images);
	num_images = heif_context_get_list_of_top_level_image_IDs(ctx, image_IDs.data(), num_images);

	for (int idx = 0; idx < num_images; ++idx) {
		struct heif_image_handle* handle = nullptr;
		err = heif_context_get_image_handle(ctx, image_IDs[idx], &handle);
		if (err.code != heif_error_Ok)
		{
			heif_image_handle_release(handle);
			break;
		}

		struct heif_image* image = nullptr;
		err = heif_decode_image(handle, &image, heif_colorspace_RGB, heif_chroma_interleaved_32bit, nullptr);

		if (err.code != heif_error_Ok)
		{
			heif_image_release(image);
			heif_image_handle_release(handle);
			break;
		}

		int width = heif_image_get_width(image, heif_channel_interleaved);
		int height = heif_image_get_height(image, heif_channel_interleaved);

		int stride = 0;
		const uint8_t* data = heif_image_get_plane_readonly(image, heif_channel_interleaved, &stride);

		int validWidth = stride / 4;
		m_img = QImage(validWidth, height, QImage::Format_RGBA8888);
		if (!m_img.isNull())
		{
			memcpy_s(m_img.bits(), stride * height, data, stride * height);
		}
		heif_image_release(image);
		heif_image_handle_release(handle);
	}
	heif_context_free(ctx);
}
