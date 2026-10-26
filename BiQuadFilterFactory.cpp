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
#define _USE_MATH_DEFINES
#include <cmath>
#include <regex>
#include <sstream>

#include "helpers/MemoryHelper.h"
#include "helpers/StringHelper.h"
#include "helpers/LogHelper.h"
#include "BiQuadFilter.h"
#include "BiQuadFilterFactory.h"

using namespace std;

static wregex regexType(L"^\\s*ON\\s+([A-Za-z]+)");
static wregex regexFreq(L"\\s+Fc\\s*([-+0-9.eE\u00A0]+)\\s*H\\s*z");
static wregex regexGain(L"\\s+Gain\\s*([-+0-9.eE]+)\\s*dB");
static wregex regexQ(L"\\s+(?:Q|Q=)\\s*([-+0-9.eE]+)");
static wregex regexBW(L"\\s+BW\\s+Oct\\s*([-+0-9.eE]+)");
static wregex regexSlope(L"^\\s*([-+0-9.eE]+)\\s*dB");
