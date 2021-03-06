/*
    Copyright �1995, Juri Munkki
    All rights reserved.

    File: BSPPlug.h
    Created: Saturday, May 6, 1995, 16:34
    Modified: Sunday, November 19, 1995, 9:37
*/

#pragma once
#include "CBSPPart.h"
#include "PAKit.h"

typedef	struct
{
	short			*bspIndexStack;
	Vector			**bspPointTemp;
	
	long			viewParameterObjectOffset;
	
	ColorRecord		***bspColorLookupTable;
	short			colorLevelOne;
	short			colorCacheSize;

	long			*tempLockCountPointer;

} BSPGlobalsInfoRecord;

typedef struct
{
	Fixed			ambient;
	short			lightCount;
	Fixed			*objLights;
	Vector			*pointArray;
	Vector			*vectorArray;
	NormalRecord	*norms;
	ColorRecord		**colorPointers;
	FaceVisibility	*faces;
	long			normalCount;
	short			colorLevelOne;
	short			colorCacheSize;
	Vector			originPoint;
}	LightingPlugParamRecord;

typedef struct
{
	//	In:
	long	edgeCount;
	Fixed	xOffset;
	Fixed	yOffset;
	Fixed	screenScale;
	Fixed	yon;
	Fixed	hither;
	
	short				*clippingCacheTable;
	EdgeCacheRecord		*edgeCacheTable;
	EdgeRecord			*uniqueEdgeTable;
	Vector				*pointTable;

	//	Out:
	Fixed	minZ;
	Fixed	maxZ;
	Fixed	minX;
	Fixed	maxX;
	Fixed	minY;
	Fixed	maxY;
}	ClipEdgesParam;

typedef struct
{
	CBSPPart		**visibleObjectArray;
	long			visibleObjectCount;
}	PreProcessListParam;

typedef struct
{
	PolyWorld		*polys;
	FaceVisibility	**faceTemp;
	PolyRecord		*polyTable;
	Vector			**bspPointTemp;
	EdgeCacheRecord	**edgeCacheHandle;
	EdgeIndex		*edgeTable;
	short			*bspIndexStack;
	short			**clippingCacheHandle;

	CBSPPart		**visibleObjectArray;
	long			visibleObjectCount;

}	DrawPolygonsParam;

typedef	void	BSPLightingPlug(LightingPlugParamRecord *p);
		void	BSPLightingPlugC(LightingPlugParamRecord *p);

typedef	void	ClipEdges(ClipEdgesParam *p);
		void	ClipEdgesC(ClipEdgesParam *p);

typedef	void	DrawPolygonsPlug(DrawPolygonsParam	*p);
		void	DrawPolygonsPlugC(DrawPolygonsParam	*p);

typedef	void	InitBSPPlug(BSPGlobalsInfoRecord *globs);
		void	InitBSPPlugC(BSPGlobalsInfoRecord *globs);

typedef	void	BSPPreProcess(Handle *globs);
		void	BSPPreProcessC(Handle *globs);

typedef	void	DrawPolygonsListPlug(DrawPolygonsParam *p);
		void	DrawPolygonsListPlugC(DrawPolygonsParam *p);

typedef	void	PreProcessListPlug(PreProcessListParam *p);
		void	PreProcessListPlugC(PreProcessListParam *p);
