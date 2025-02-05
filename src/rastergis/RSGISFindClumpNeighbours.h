/*
 *  RSGISFindClumpNeighbours.h
 *  RSGIS_LIB
 *
 *  Created by Pete Bunting on 27/03/2012.
 *  Copyright 2012 RSGISLib.
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

#ifndef RSGISFindClumpNeighbours_H
#define RSGISFindClumpNeighbours_H

#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <list>
#include <vector>
#include <algorithm>

#include "img/RSGISImageCalcException.h"
#include "img/RSGISCalcImageValue.h"
#include "img/RSGISCalcImage.h"

#include "libkea/KEAImageIO.h"

#include "common/rsgis-tqdm.h"

#include "rastergis/RSGISRasterAttUtils.h"

#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include "ogr_api.h"

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
    
    class DllExport RSGISFindClumpNeighbours
    {
    public:
        RSGISFindClumpNeighbours();
        std::vector<std::list<size_t>* >* findNeighbours(GDALDataset *clumpImage, unsigned int ratBand);
        void findNeighboursKEAImageCalc(GDALDataset *clumpImage, unsigned int ratBand);
        ~RSGISFindClumpNeighbours();
    };
    
    
    
    class DllExport RSGISFindNeighboursCalcImage : public rsgis::img::RSGISCalcImageValue
	{
	public:
		RSGISFindNeighboursCalcImage(size_t numRows, std::vector<std::vector<size_t>* > *neighbours, unsigned int ratBand);
		void calcImageValue(float ***dataBlock, int numBands, int winSize, double *output);
		~RSGISFindNeighboursCalcImage();
    private:
        size_t numRows;
        std::vector<std::vector<size_t>* > *neighbours;
        unsigned int ratBand;
	};
    
    
    class DllExport RSGISIdentifyBoundaryPixels : public rsgis::img::RSGISCalcImageValue
	{
	public:
		RSGISIdentifyBoundaryPixels(unsigned int ratBand);
		void calcImageValue(float ***dataBlock, int numBands, int winSize, double *output);
		~RSGISIdentifyBoundaryPixels();
    protected:
        unsigned int ratBand;
	};
    
}}

#endif
