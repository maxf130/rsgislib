/*
 *  RSGISCollapseRAT.h
 *  RSGIS_LIB
 *
 *  Created by Pete Bunting on 21/10/2014.
 *  Copyright 2014 RSGISLib.
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

#ifndef RSGISCollapseRAT_H
#define RSGISCollapseRAT_H

#include <string>
#include <vector>
#include <cmath>

#include "gdal_priv.h"
#include "gdal_rat.h"

#include "common/RSGISAttributeTableException.h"

#include "rastergis/RSGISRasterAttUtils.h"
#include "rastergis/RSGISCalcImageStatsAndPyramids.h"

#include "img/RSGISImageUtils.h"
#include "img/RSGISImageCalcException.h"

#include "img/RSGISCalcImageValue.h"
#include "img/RSGISCalcImage.h"

// mark all exported classes/functions with DllExport to have
// them exported by Visual Studio
#undef DllExport
#ifdef _MSC_VER
    #ifdef rsgis_rastergis_EXPORTS
        #define DllExport   __declspec( dllexport )
    #else
        #define DllExport   __declspec( dllimport )
    #endif
#else
    #define DllExport
#endif

namespace rsgis{namespace rastergis{
    
    class DllExport RSGISCollapseRAT
    {
    public:
        RSGISCollapseRAT();
        void classifyClumps(GDALDataset *inputClumps, unsigned int ratBand, std::string selectColumn, std::string outImage, std::string gdalFormat);
        ~RSGISCollapseRAT();
    };
    
    
    class DllExport RSGISCollapseRATPopNewImage : public rsgis::img::RSGISCalcImageValue
    {
    public:
        RSGISCollapseRATPopNewImage(size_t *collapsedIDs, size_t numVals, unsigned int ratBand);
        void calcImageValue(long *intBandValues, unsigned int numIntVals, float *floatBandValues, unsigned int numfloatVals, double *output);
        ~RSGISCollapseRATPopNewImage();
    protected:
        size_t *collapsedIDs;
        size_t numVals;
        unsigned int ratArrIdx;
    };
    
    

    
}}

#endif

