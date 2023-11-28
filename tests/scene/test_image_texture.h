/**************************************************************************/
/*  test_image_texture.h                                                       */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef TEST_IMAGE_TEXTURE_H
#define TEST_IMAGE_TEXTURE_H

#include "scene/resources/image_texture.h"
#include "core/io/image.h"

#include "tests/test_macros.h"
#include "tests/test_utils.h"

namespace TestImageTexture {

	const int default_height = 64;
	const int default_width = 64;
	const int default_channels = 3;
	const Image::Format default_format = Image::Format::FORMAT_RGB8;

	static Ref<Image> create_test_image_base(int p_channels, Image::Format p_format) {
		Vector<uint8_t> data;
		data.resize(default_width * default_height * p_channels);

		// This loop fills the data with image pixel values (RGBA format).
		for (int y = 0; y < default_height; y++) {
			for (int x = 0; x < default_width; x++) {
				int offset = (y * default_width + x) * p_channels;
				for (int c = 0; c < p_channels; c++) {
					data.set(offset + c, 255);
				}
			}
		}

		return Image::create_from_data(default_width, default_height, false, p_format, data);
	}

	static Ref<Image> create_test_image() {
		return create_test_image_base(default_channels, default_format);
	}

	/*const int default_width = 64;
	const int default_height = 64;*/
	const bool use_mipmaps = false;

	Ref<Image> create_empty_image()
	{
		return Image::create_empty(default_width, default_height, use_mipmaps, Image::FORMAT_L8);
	}

	TEST_CASE("[ImageTexture] Constructor") {
		// Create an ImageTexture object.
		Ref<ImageTexture> imageTexture;
		imageTexture.instantiate();

		// Ensure that it's not null.
		REQUIRE(imageTexture.is_valid());

		// Verify default values are correct.
		CHECK(imageTexture->get_width() == 0);
		CHECK(imageTexture->get_height() == 0);
		CHECK(imageTexture->get_format() == Image::FORMAT_L8);
		CHECK_FALSE(imageTexture->has_alpha());
	}

	/*
	TEST_CASE("[ImageTexture] TestImage 64x64") {
		//Size2i taille(default_width, default_height);

		Ref<ImageTexture> imageTexture;
		imageTexture.instantiate();

		Ref<Image> image = Image::create_empty(default_width, default_height, use_mipmaps, Image::FORMAT_L8);
		//image->load_from_file("D:/projet IDL/godot_for_camera2d_test_unit/tests/scene/ressources/cubies.png");
		// imageTexture->set_image(image);
		Ref<Image> emptyImage;
		emptyImage.instantiate();
		emptyImage = emptyImage->create_empty(default_width, default_height, false, Image::FORMAT_L8);

		REQUIRE_FALSE(emptyImage.is_null());

		imageTexture->create_from_image(emptyImage);

		REQUIRE_FALSE(imageTexture.is_null());

		CHECK(imageTexture->get_width() == 64);
		CHECK(imageTexture->get_height() == 64);
	}
	*/

	TEST_CASE("[ImageTexture] TestImage 64x64")
	{
	// Create an image for the texture.
	Ref<Image> image = create_test_image();

	// Create the image texture, initially as empty.
	Ref<ImageTexture> imageTexture;
	imageTexture.instantiate();

	// Set the image on the image texture.
	imageTexture->set_image(image);

	// Ensure that the image texture is not null.
	REQUIRE_FALSE(imageTexture.is_null());

	// Check if the properties are initialized based on the image.
	CHECK(imageTexture->get_width() == default_width);
	CHECK(imageTexture->get_height() == default_width);
	CHECK(imageTexture->get_format() == default_format);
	CHECK_FALSE(imageTexture->has_alpha());
	}


}
#endif // TEST_IMAGE_TEXTURE_H
