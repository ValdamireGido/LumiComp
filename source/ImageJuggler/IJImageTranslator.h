#pragma once

#include "IJTypes.h"
#include <vector>

template <typename _PixelCompTy> class IJImage;
class IJRGBImage;
class IJYCbCrImage444;
class IJYCbCrImage422;

struct IJRGBPixel;
struct IJYCbCrPixel444;

struct IJImageTranslator
{
	static std::array<uint8_t, 3> TranslateRGBPixelToYBR(const std::vector<uint8_t>& rgbPixel);
	static void TranslateRGBPixelToYBR(IJRGBPixel* rgbPixel, IJYCbCrPixel444* ybrPixel);

	static std::array<uint8_t, 3> TranslateYBRPixelToRGB(const std::vector<uint8_t>& ybrPixel);
	static void TranslateYBRPixelToRGB(IJYCbCrPixel444* ybrPixel, IJRGBPixel* rgbPixel);

	static IJResult RGBToYCbCr444 (IJRGBImage*		input, IJYCbCrImage444* output);
	static IJResult RGBToYCbCr442 (IJRGBImage*		input, IJYCbCrImage422* output);
	static IJResult YCbCr444ToRGB (IJYCbCrImage444*	input, IJRGBImage*		output);
	//static IJResult YCbCr422ToRGB (IJYCbCrImage422*	input, IJRGBImage*		output);

	static IJResult YCbCrCompSplit(IJYCbCrImage444*	input, std::vector<uint8_t>& yComp
														 , std::vector<uint8_t>& bComp
														 , std::vector<uint8_t>& rComp);

	static IJResult YBRToRGBCompSlit(IJYCbCrImage444* input, std::vector<uint8_t>& yComp
														   , std::vector<uint8_t>& bComp
														   , std::vector<uint8_t>& rComp);

	static IJResult YBRToRGBCompSlit(IJYCbCrImage444* input, IJRGBImage* yComp
														   , IJRGBImage* bComp
														   , IJRGBImage* rComp);

private:
	template <typename _PixelCompTy>
	static void _CopyImageAttributes(IJImage<_PixelCompTy>* input, IJImage<_PixelCompTy>* output);
};