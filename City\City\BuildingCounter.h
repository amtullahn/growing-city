/**
 * \file BuildingCounter.h
 *
 * \author Amtullah Naalwala
 *
 * Visitor that counts buildings
 */

#pragma once
#include "TileVisitor.h"

/**
 * Visitor that counts buildings
 */
class CBuildingCounter :
	public CTileVisitor
{
public:
    /** Get the number of buildings
    * \returns Number of buildings */
    int GetNumBuildings() const { return mNumBuildings; }

    void VisitBuilding(CTileBuilding* building);

private:
    /// Buildings counter
    int mNumBuildings = 0;
};

