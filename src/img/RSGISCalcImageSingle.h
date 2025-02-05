/*
 *  RSGISCalcImageSingle.h
 *  RSGIS_LIB
 *
 *  Created by Pete Bunting on 22/07/2008.
 *  Copyright 2008 RSGISLib.
 * 
 *  RSGISLib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  RSGISLib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RSGISLib.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef RSGISCalcImageSingle_H
#define RSGISCalcImageSingle_H

#include <iostream>
#include <string>

#include "gdal_priv.h"

#include "common/rsgis-tqdm.h"

#include "img/RSGISImageCalcException.h"
#include "img/RSGISCalcImageSingleValue.h"
#include "img/RSGISImageUtils.h"
#include "img/RSGISPixelInPoly.h"

// mark all exported classes/functions with DllExport to have
// them exported by Visual Studio
#undef DllExport
#ifdef _MSC_VER
    #ifdef rsgis_img_EXPORTS
        #define DllExport   __declspec( dllexport )
    #else
        #define DllExport   __declspec( dllimport )
    #endif
#else
    #define DllExport
#endif

namespace rsgis{namespace img{
	
	class DllExport RSGISCalcImageSingle
		{
		public:
			RSGISCalcImageSingle(RSGISCalcImageSingleValue *valueCalc);
			void calcImage(GDALDataset **datasetsA, GDALDataset **datasetsB, int numDS, double *outputValue, int bandA, int bandB);
			void calcImage(GDALDataset **datasetsA, int numDS, double *outputValue, int band);
			void calcImageWindow(GDALDataset **datasetsA, int numDS, double *outputValue);
			void calcImageWithinPolygon(GDALDataset **datasets, int numDS, double *outputValue, OGREnvelope *env, OGRPolygon *poly, bool output, pixelInPolyOption pixelPolyOption);
			void calcImageWithinRasterPolygon(GDALDataset **datasets, int numDS, double *outputValue, OGREnvelope *env, long fid, bool output);
			RSGISCalcImageSingleValue* getRSGISCalcImageSingleValue();
			virtual ~RSGISCalcImageSingle();
		protected:
			RSGISCalcImageSingleValue *valueCalc;
		};
}}
#endif


