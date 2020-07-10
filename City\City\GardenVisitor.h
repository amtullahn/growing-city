/**
 * \file GardenVisitor.h
 *
 * \author Amtullah Naalwala
 *
 * Garden Visitor Class
 */

#pragma once
#include "TileGarden.h"

/**
 * Garden Visitor Class tells the garden to look into the CTileGarden class
 */
class CGardenVisitor :
	public CTileVisitor
{
public:
    /** Implement the garden tile
    * \param garden a garden visitor passed in 
    */
	void VisitGarden(CTileGarden* garden);
};

