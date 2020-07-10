/**
 * \file TileGarden.cpp
 *
 * \author Amtullah Naalwala
 *
 * Ability to tend the garden after adding a new Garden tile type
 */


#include "pch.h"
#include "TileGarden.h"


using namespace std;
using namespace Gdiplus;

/// Image of initial garden
const wstring InitialGarden = L"garden.png";

/// Image of garden 2 seconds after neglect
const wstring Garden2 = L"garden1.png";

/// Image of garden 4 seconds after neglect
const wstring Garden4 = L"garden2.png";

/// Image of garden 7 seconds after neglect
const wstring Garden7 = L"garden3.png";

/// Image of garden 10 seconds after neglect
const wstring Garden10 = L"garden4.png";

/** Constructor
* \param city The city this is a member of
*/
CTileGarden::CTileGarden(CCity* city) : CTile(city)
{
    //SetImage(InitialGarden);
   
}

/**
*  Destructor
*/
CTileGarden::~CTileGarden()
{
 
}

/**  Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns Pointer to the crated node
 */
std::shared_ptr<xmlnode::CXmlNode> CTileGarden::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CTile::XmlSave(node);

    itemNode->SetAttribute(L"type", L"garden");


    return itemNode;
}

/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
*/
void CTileGarden::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CTile::XmlLoad(node);
    SetImage(node->GetAttributeValue(L"file", L""));
}


/**
 * Called before the image is drawn
 * \param elapsed Time since last draw
 */
void CTileGarden::Update(double elapsed)
{
    CTile::Update(elapsed);

    mSincePruning += elapsed;

    // If the time since pruning is greater than 2 seconds then change image to Garden 2
    if (mSincePruning >= 2 && mPruningState != PruningStates::Overgrown1)
    {
        SetImage(Garden2);
        mPruningState = PruningStates::Overgrown1;

    }

    if (mSincePruning >= 4)
    {
        SetImage(Garden4);
        mPruningState = PruningStates::Overgrown2;
    }

    if (mSincePruning >= 7) 
    {
        SetImage(Garden7);
        mPruningState = PruningStates::Overgrown3;
    }

    if(mSincePruning >= 10)
    {
        SetImage(Garden10);
        mPruningState = PruningStates::Overgrown4;
    }

}

void CTileGarden::Prune(CTileGarden *garden) {
    SetImage(InitialGarden);
    mSincePruning = 0;
}

