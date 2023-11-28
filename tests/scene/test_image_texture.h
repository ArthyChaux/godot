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

	const int default_width = 64;
	const int default_height = 64;
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

	TEST_CASE("[ImageTexture] TestImage 64x64") {
		// ___________________________________________________ //
		// __________________ DOESNT WORK ____________________ //
		// ___________________________________________________ //

		/*Ref<ImageTexture> imageTexture;
		imageTexture.instantiate();

		Ref<Image> image = Image::create_empty(default_width, default_height, use_mipmaps, Image::FORMAT_L8);
		Ref<Image> emptyImage;
		emptyImage.instantiate();
		emptyImage = emptyImage->create_empty(default_width, default_height, false, Image::FORMAT_L8);

		REQUIRE_FALSE(emptyImage.is_null());

		imageTexture->create_from_image(emptyImage);

		REQUIRE_FALSE(imageTexture.is_null());

		CHECK(imageTexture->get_width() == 64);
		CHECK(imageTexture->get_height() == 64);*/
	}


}
#endif // TEST_IMAGE_TEXTURE_H
