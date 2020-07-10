#include "pch.h"
#include "GardenVisitor.h"
#include "TileGarden.h"
#include "Tile.h"

void CGardenVisitor::VisitGarden(CTileGarden* visitor) 
{
	visitor->Prune(visitor);
}