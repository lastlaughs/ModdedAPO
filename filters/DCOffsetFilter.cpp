/*
    This file is part of EqualizerAPO, a system-wide equalizer.
    Copyright (C) 2014  Jonas Thedering

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "stdafx.h"
#include "DCOffsetFilter.h"

using namespace std;

DCOffsetFilter::DCOffsetFilter(double offset)
	: offset(offset), channelCount(0)
{
}

std::vector<std::wstring> DCOffsetFilter::initialize(float sampleRate, unsigned maxFrameCount, std::vector<std::wstring> channelNames)
{
	this->channelCount = channelNames.size();
	return channelNames;
}

#pragma AVRT_CODE_BEGIN
void DCOffsetFilter::process(double** output, double** input, unsigned frameCount)
{
	for (size_t c = 0; c < channelCount; ++c)
	{
		double* inputChannel = input[c];
		double* outputChannel = output[c];

		for (unsigned i = 0; i < frameCount; ++i)
		{
			outputChannel[i] = inputChannel[i] - this->offset;
		}
	}
}
#pragma AVRT_CODE_END
